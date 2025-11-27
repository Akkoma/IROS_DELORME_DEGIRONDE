#!/home/alix.degironde/Public/ven_IROS/bin python3

import sys
import time
import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from sensor_msgs.msg import Image
from tello_msg.msg import TelloStatus
from std_msgs.msg import Int32
from geometry_msgs.msg import Twist
import cv2
import numpy as np

from tello_msg.action import Spielberg

class SpielbergNode(Node):
    def __init__(self):
        super().__init__('spielberg')
        
        # Action Server
        self._action_server = ActionServer(
            self,
            Spielberg,
            'spielberg',
            self.execute_callback
        )
        
        # Publisher pour envoyer les commandes de mouvement
        self.cmd_vel_pub = self.create_publisher(
            Twist,
            '/control',
            10
        )
        
        # Variables pour gérer l'exécution
        self.current_goal_handle = None
        self.is_sequence_running = False
        
        # Variables pour la séquence de commandes
        self.sequence_timer = None
        self.sequence_index = 0
        self.sequence_start_time = None
        
        # Définir la séquence de commandes : [(durée_en_secondes, commande_twist)]
        self.command_sequence = [
            (2.0, self.create_twist(0.0, 50.0, 0.0, 0.0, 0.0, 0.0)),  # Avancer 5s
            (1.0, self.create_twist(0.0, 0.0, 0.0, 0.0, 0.0, 40.0)),  # Rotation 3s
            (2.0, self.create_twist(0.0, -50.0, 0.0, 0.0, 0.0, 0.0)),  # recule 2s
            (1.0, self.create_twist(0.0, 0.0, 0.0, 0.0, 0.0, -40.0)), # Rotation inverse 3s
            (2.0, self.create_twist(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)),   # Stop 2s
        ]
    
    def create_twist(self, lx, ly, lz, ax, ay, az):
        """Crée un message Twist avec les valeurs données"""
        twist = Twist()
        twist.linear.x = lx
        twist.linear.y = ly
        twist.linear.z = lz
        twist.angular.x = ax
        twist.angular.y = ay
        twist.angular.z = az
        return twist
    
    def execute_callback(self, goal_handle):
        """Callback de l'action qui démarre la séquence"""
        self.get_logger().info('Action Spielberg reçue - Démarrage de la séquence')
        
        # Vérifier si une séquence est déjà en cours
        if self.is_sequence_running:
            self.get_logger().warn('Une séquence est déjà en cours')
            result = Spielberg.Result()
            result.success = False
            result.message = 'Une séquence est déjà en cours'
            goal_handle.abort(result)
            return result
        
        # Accepter le goal
        self.current_goal_handle = goal_handle
        self.is_sequence_running = True
        
        # Démarrer la séquence
        self.start_sequence()
        
        # Retourner immédiatement avec succès
        # La séquence continuera à s'exécuter via le timer
        result = Spielberg.Result()
        result.success = True
        result.message = 'Séquence Spielberg démarrée'
        self.get_logger().info('Goal Spielberg accepté - Séquence en cours')
        return result
    
    def start_sequence(self):
        """Démarre la séquence de commandes"""
        self.sequence_index = 0
        self.sequence_start_time = self.get_clock().now()
        
        # Créer un timer qui s'exécute à 10Hz (toutes les 0.1s)
        if self.sequence_timer is not None:
            self.sequence_timer.cancel()
        
        self.sequence_timer = self.create_timer(0.1, self.execute_sequence)
        self.get_logger().info('Séquence de commandes démarrée')
    
    def stop_sequence(self):
        """Arrête la séquence de commandes"""
        if self.sequence_timer is not None:
            self.sequence_timer.cancel()
            self.sequence_timer = None
        
        # Envoyer une commande d'arrêt
        stop_cmd = self.create_twist(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
        self.cmd_vel_pub.publish(stop_cmd)
        
        self.is_sequence_running = False
        self.get_logger().info('Séquence de commandes arrêtée')
    
    def execute_sequence(self):
        """Exécute la séquence de commandes selon les timings"""
        # Vérifier si annulation demandée
        if self.current_goal_handle is not None and self.current_goal_handle.is_cancel_requested:
            self.get_logger().info('Annulation demandée - Arrêt de la séquence')
            self.stop_sequence()
            result = Spielberg.Result()
            result.success = False
            result.message = 'Séquence annulée par l\'utilisateur'
            self.current_goal_handle.canceled(result)
            self.current_goal_handle = None
            return
        
        # Calculer le temps écoulé
        if self.current_goal_handle is not None and self.sequence_start_time is not None:
            current_time = self.get_clock().now()
            elapsed = (current_time - self.sequence_start_time).nanoseconds / 1e9
            
            # Envoyer le feedback
            feedback_msg = Spielberg.Feedback()
            feedback_msg.current_step = self.sequence_index
            feedback_msg.total_steps = len(self.command_sequence)
            feedback_msg.elapsed_time = float(elapsed)
            self.current_goal_handle.publish_feedback(feedback_msg)
        
        if self.sequence_index >= len(self.command_sequence):
            # Séquence terminée - arrêter le timer et marquer comme non-running
            self.get_logger().info('Toutes les étapes de la séquence terminées')
            if self.sequence_timer is not None:
                self.sequence_timer.cancel()
                self.sequence_timer = None
            
            # Envoyer une commande d'arrêt finale
            stop_cmd = self.create_twist(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
            self.cmd_vel_pub.publish(stop_cmd)
            
            # Marquer la séquence comme terminée et envoyer le résultat
            if self.current_goal_handle is not None:
                result = Spielberg.Result()
                result.success = True
                result.message = 'Séquence Spielberg terminée avec succès'
                self.current_goal_handle.succeed(result)
                self.get_logger().info('Séquence Spielberg terminée avec succès')
            
            self.is_sequence_running = False
            self.current_goal_handle = None
            return
        
        # Calculer le temps écoulé depuis le début de la séquence
        current_time = self.get_clock().now()
        elapsed = (current_time - self.sequence_start_time).nanoseconds / 1e9  # Convertir en secondes
        
        # Calculer le temps cumulé jusqu'à l'étape actuelle
        cumulative_time = sum(duration for duration, _ in self.command_sequence[:self.sequence_index])
        
        # Vérifier si on doit passer à l'étape suivante
        current_duration, current_command = self.command_sequence[self.sequence_index]
        
        if elapsed >= cumulative_time + current_duration:
            # Passer à l'étape suivante
            self.sequence_index += 1
            if self.sequence_index < len(self.command_sequence):
                next_duration, next_command = self.command_sequence[self.sequence_index]
                self.get_logger().info(f'Étape {self.sequence_index + 1}/{len(self.command_sequence)} - Durée: {next_duration}s')
        
        # Publier la commande actuelle
        if self.sequence_index < len(self.command_sequence):
            _, command = self.command_sequence[self.sequence_index]
            self.cmd_vel_pub.publish(command)
    

def main(args=None):
    rclpy.init(args=args)
    node = SpielbergNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()