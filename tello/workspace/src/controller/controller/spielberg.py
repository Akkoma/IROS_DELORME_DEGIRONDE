#!/home/alix.degironde/Public/ven_IROS/bin python3

import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, CancelResponse, GoalResponse
from rclpy.executors import MultiThreadedExecutor
from rclpy.callback_groups import ReentrantCallbackGroup
from geometry_msgs.msg import Twist
from std_msgs.msg import Empty
from tello_msg.action import Spielberg
import time


class SpielbergActionServer(Node):
    """
    Action Server pour le mode Spielberg - Séquences cinématiques du drone.
    
    Ce noeud permet d'exécuter des séquences de mouvements prédéfinies
    pour créer des plans de caméra cinématiques avec le drone Tello.
    
    Séquence par défaut:
    1. Décollage
    2. Montée lente
    3. Rotation panoramique 360°
    4. Travelling avant
    5. Montée en spirale
    6. Travelling arrière
    7. Descente douce
    8. Atterrissage
    """
    
    def __init__(self):
        super().__init__('spielberg_action_server')
        
        # Utiliser un callback group réentrant pour permettre les appels asynchrones
        self._callback_group = ReentrantCallbackGroup()
        
        # Action Server
        self._action_server = ActionServer(
            self,
            Spielberg,
            'spielberg',
            execute_callback=self.execute_callback,
            goal_callback=self.goal_callback,
            cancel_callback=self.cancel_callback,
            callback_group=self._callback_group
        )
        
        # Publishers vers le drone
        self.pub_takeoff = self.create_publisher(Empty, '/takeoff', 10)
        self.pub_land = self.create_publisher(Empty, '/land', 10)
        self.pub_control = self.create_publisher(Twist, '/control', 10)
        
        # Flag d'annulation
        self._goal_cancelled = False
        
        # Définition de la séquence cinématique
        self.sequence = [
            {
                'name': 'Décollage',
                'duration': 3.0,
                'action': self.takeoff_action
            },
            {
                'name': 'Montée douce',
                'duration': 3.0,
                'action': lambda: self.move_action(0.0, 0.0, 0.3, 0.0)
            },
            {
                'name': 'Pause stabilisation',
                'duration': 1.0,
                'action': lambda: self.move_action(0.0, 0.0, 0.0, 0.0)
            },
            {
                'name': 'Rotation panoramique (180°)',
                'duration': 6.0,
                'action': lambda: self.move_action(0.0, 0.0, 0.0, 0.5)
            },
            {
                'name': 'Pause',
                'duration': 1.0,
                'action': lambda: self.move_action(0.0, 0.0, 0.0, 0.0)
            },
            {
                'name': 'Travelling avant',
                'duration': 4.0,
                'action': lambda: self.move_action(0.3, 0.0, 0.0, 0.0)
            },
            {
                'name': 'Pause',
                'duration': 1.0,
                'action': lambda: self.move_action(0.0, 0.0, 0.0, 0.0)
            },
            {
                'name': 'Montée en spirale',
                'duration': 5.0,
                'action': lambda: self.move_action(0.0, 0.0, 0.2, 0.3)
            },
            {
                'name': 'Pause stabilisation',
                'duration': 1.0,
                'action': lambda: self.move_action(0.0, 0.0, 0.0, 0.0)
            },
            {
                'name': 'Travelling arrière',
                'duration': 4.0,
                'action': lambda: self.move_action(-0.3, 0.0, 0.0, 0.0)
            },
            {
                'name': 'Pause',
                'duration': 1.0,
                'action': lambda: self.move_action(0.0, 0.0, 0.0, 0.0)
            },
            {
                'name': 'Descente douce',
                'duration': 3.0,
                'action': lambda: self.move_action(0.0, 0.0, -0.3, 0.0)
            },
            {
                'name': 'Pause avant atterrissage',
                'duration': 1.0,
                'action': lambda: self.move_action(0.0, 0.0, 0.0, 0.0)
            },
            {
                'name': 'Atterrissage',
                'duration': 3.0,
                'action': self.land_action
            }
        ]
        
        self.get_logger().info('Action Server Spielberg initialisé')
        self.get_logger().info(f'Séquence cinématique: {len(self.sequence)} étapes')
    
    def goal_callback(self, goal_request):
        """Callback appelé quand un nouveau goal est reçu"""
        self.get_logger().info('Nouveau goal Spielberg reçu')
        # Accepter tous les goals
        return GoalResponse.ACCEPT
    
    def cancel_callback(self, goal_handle):
        """Callback appelé quand une annulation est demandée"""
        self.get_logger().info('Demande d\'annulation reçue')
        self._goal_cancelled = True
        return CancelResponse.ACCEPT
    
    async def execute_callback(self, goal_handle):
        """
        Callback principal qui exécute la séquence cinématique
        
        Args:
            goal_handle: Handle du goal en cours d'exécution
        
        Returns:
            Spielberg.Result: Résultat de l'action (success, message)
        """
        self.get_logger().info('=== DÉBUT DE LA SÉQUENCE SPIELBERG ===')
        
        # Réinitialiser le flag d'annulation
        self._goal_cancelled = False
        
        # Préparer le feedback
        feedback_msg = Spielberg.Feedback()
        feedback_msg.total_steps = len(self.sequence)
        
        # Timer pour le temps écoulé
        start_time = time.time()
        
        # Exécuter chaque étape de la séquence
        for step_index, step in enumerate(self.sequence):
            # Vérifier si l'annulation a été demandée
            if self._goal_cancelled or not goal_handle.is_active:
                self.get_logger().warn('Séquence annulée')
                # Arrêter le drone
                self.stop_drone()
                goal_handle.canceled()
                result = Spielberg.Result()
                result.success = False
                result.message = 'Séquence annulée par l\'utilisateur'
                return result
            
            # Log de l'étape
            self.get_logger().info(
                f'Étape {step_index + 1}/{len(self.sequence)}: {step["name"]}'
            )
            
            # Publier le feedback
            feedback_msg.current_step = step_index
            feedback_msg.elapsed_time = time.time() - start_time
            goal_handle.publish_feedback(feedback_msg)
            
            # Exécuter l'action de l'étape
            await self.execute_step(step)
        
        # Arrêter le drone en fin de séquence
        self.stop_drone()
        
        # Séquence terminée avec succès
        goal_handle.succeed()
        result = Spielberg.Result()
        result.success = True
        result.message = f'Séquence cinématique terminée ({len(self.sequence)} étapes)'
        
        self.get_logger().info('=== FIN DE LA SÉQUENCE SPIELBERG ===')
        self.get_logger().info(f'Temps total: {time.time() - start_time:.1f}s')
        
        return result
    
    async def execute_step(self, step):
        """
        Exécute une étape de la séquence
        
        Args:
            step: Dictionnaire contenant 'name', 'duration' et 'action'
        """
        # Lancer l'action
        step['action']()
        
        # Attendre la durée spécifiée (avec vérification d'annulation)
        duration = step['duration']
        sleep_interval = 0.1  # Vérifier l'annulation toutes les 100ms
        elapsed = 0.0
        
        while elapsed < duration:
            if self._goal_cancelled:
                break
            
            await rclpy.task.sleep(sleep_interval)
            elapsed += sleep_interval
    
    def takeoff_action(self):
        """Action de décollage"""
        msg = Empty()
        self.pub_takeoff.publish(msg)
        self.get_logger().info('> Commande: Décollage')
    
    def land_action(self):
        """Action d'atterrissage"""
        msg = Empty()
        self.pub_land.publish(msg)
        self.get_logger().info('> Commande: Atterrissage')
    
    def move_action(self, linear_x, linear_y, linear_z, angular_z):
        """
        Action de mouvement
        
        Args:
            linear_x: Vitesse avant/arrière (m/s)
            linear_y: Vitesse gauche/droite (m/s)
            linear_z: Vitesse haut/bas (m/s)
            angular_z: Vitesse de rotation (rad/s)
        """
        msg = Twist()
        msg.linear.x = linear_x
        msg.linear.y = linear_y
        msg.linear.z = linear_z
        msg.angular.z = angular_z
        self.pub_control.publish(msg)
        
        # Log uniquement pour les mouvements non nuls
        if any([linear_x, linear_y, linear_z, angular_z]):
            self.get_logger().info(
                f'> Mouvement: x={linear_x:.2f}, y={linear_y:.2f}, '
                f'z={linear_z:.2f}, rot={angular_z:.2f}',
                throttle_duration_sec=0.5
            )
    
    def stop_drone(self):
        """Arrête tous les mouvements du drone"""
        msg = Twist()
        msg.linear.x = 0.0
        msg.linear.y = 0.0
        msg.linear.z = 0.0
        msg.angular.z = 0.0
        self.pub_control.publish(msg)
        self.get_logger().info('> Arrêt du drone')


def main(args=None):
    rclpy.init(args=args)
    
    action_server = SpielbergActionServer()
    
    # Utiliser un MultiThreadedExecutor pour gérer les callbacks asynchrones
    executor = MultiThreadedExecutor()
    executor.add_node(action_server)
    
    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        action_server.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
