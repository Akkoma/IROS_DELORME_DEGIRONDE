#!/home/alix.degironde/Public/ven_IROS/bin python3

import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, CancelResponse, GoalResponse
from geometry_msgs.msg import Twist
from std_msgs.msg import Empty
from tello_msg.action import Spielberg
import time


class SpielbergActionServer(Node):
    def __init__(self):
        super().__init__('spielberg_action_server')
        
        # Action Server
        self._action_server = ActionServer(
            self,
            Spielberg,
            'spielberg',
            goal_callback=self.goal_callback,
            cancel_callback=self.cancel_callback,
            execute_callback=self.execute_callback,
        )
        
        # Publishers vers le drone
        self.pub_takeoff = self.create_publisher(Empty, '/takeoff', 10)
        self.pub_land = self.create_publisher(Empty, '/land', 10)
        self.pub_control = self.create_publisher(Twist, '/control', 10)
        
        self.get_logger().info('Noeud spielberg_action_server initialisé')
        self.get_logger().info("Action server 'spielberg' disponible")
    
    def goal_callback(self, goal_request):
        """Accepte ou rejette un goal reçu"""
        self.get_logger().info('Réception d\'un goal Spielberg...')
        # Accepter tous les goals
        return GoalResponse.ACCEPT
    
    def cancel_callback(self, goal_handle):
        """Gère l'annulation d'un goal en cours"""
        self.get_logger().info('Réception d\'une demande d\'annulation Spielberg')
        return CancelResponse.ACCEPT
    
    def execute_callback(self, goal_handle):
        """Exécute la séquence Spielberg"""
        self.get_logger().info('Exécution de la séquence Spielberg...')
        
        # Paramètres de la séquence cinématique
        total_steps = 5
        start_time = time.time()
        
        try:
            # Étape 1 : Décollage
            self.get_logger().info('[Étape 1/5] Décollage...')
            self.pub_takeoff.publish(Empty())
            self.publish_feedback(goal_handle, 1, total_steps, 0.0)
            time.sleep(3)
            
            # Vérifier les annulations
            if goal_handle.is_cancel_requested():
                goal_handle.canceled()
                self.get_logger().warn('Séquence Spielberg annulée')
                result = Spielberg.Result()
                result.success = False
                result.message = "Séquence annulée"
                return result
            
            # Étape 2 : Mouvement en avant
            self.get_logger().info('[Étape 2/5] Mouvement en avant...')
            twist = Twist()
            twist.linear.x = 0.5
            self.pub_control.publish(twist)
            self.publish_feedback(goal_handle, 2, total_steps, time.time() - start_time)
            time.sleep(2)
            
            if goal_handle.is_cancel_requested():
                goal_handle.canceled()
                self.get_logger().warn('Séquence Spielberg annulée')
                result = Spielberg.Result()
                result.success = False
                result.message = "Séquence annulée"
                return result
            
            # Étape 3 : Rotation
            self.get_logger().info('[Étape 3/5] Rotation...')
            twist = Twist()
            twist.angular.z = 1.0
            self.pub_control.publish(twist)
            self.publish_feedback(goal_handle, 3, total_steps, time.time() - start_time)
            time.sleep(3)
            
            if goal_handle.is_cancel_requested():
                goal_handle.canceled()
                self.get_logger().warn('Séquence Spielberg annulée')
                result = Spielberg.Result()
                result.success = False
                result.message = "Séquence annulée"
                return result
            
            # Étape 4 : Mouvement en arrière
            self.get_logger().info('[Étape 4/5] Mouvement en arrière...')
            twist = Twist()
            twist.linear.x = -0.5
            self.pub_control.publish(twist)
            self.publish_feedback(goal_handle, 4, total_steps, time.time() - start_time)
            time.sleep(2)
            
            if goal_handle.is_cancel_requested():
                goal_handle.canceled()
                self.get_logger().warn('Séquence Spielberg annulée')
                result = Spielberg.Result()
                result.success = False
                result.message = "Séquence annulée"
                return result
            
            # Étape 5 : Atterrissage
            self.get_logger().info('[Étape 5/5] Atterrissage...')
            self.pub_land.publish(Empty())
            self.publish_feedback(goal_handle, total_steps, total_steps, time.time() - start_time)
            time.sleep(2)
            
            # Arrêter le drone
            twist_stop = Twist()
            self.pub_control.publish(twist_stop)
            
            # Succès
            goal_handle.succeed()
            result = Spielberg.Result()
            result.success = True
            result.message = f"Séquence Spielberg complétée en {time.time() - start_time:.1f}s"
            self.get_logger().info(f"✓ {result.message}")
            return result
            
        except Exception as e:
            self.get_logger().error(f"Erreur lors de l'exécution Spielberg: {e}")
            goal_handle.abort()
            result = Spielberg.Result()
            result.success = False
            result.message = f"Erreur: {str(e)}"
            return result
    
    def publish_feedback(self, goal_handle, current_step, total_steps, elapsed_time):
        """Publie le feedback de progression"""
        feedback_msg = Spielberg.Feedback()
        feedback_msg.current_step = current_step
        feedback_msg.total_steps = total_steps
        feedback_msg.elapsed_time = elapsed_time
        goal_handle.publish_feedback(feedback_msg)


def main(args=None):
    rclpy.init(args=args)
    node = SpielbergActionServer()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()