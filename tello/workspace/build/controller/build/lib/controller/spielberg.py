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
    # Définition des modes
    SPIELBERG_MODE = 2
    
    def __init__(self):
        super().__init__('spielberg')
        
        # Mode actuel
        self.current_mode = 0
        self.current_goal_handle = None
        self._action_server = ActionServer(
            self,
            Spielberg,
            'spielberg',
            self.execute_callback)
        
        # Publisher pour envoyer les commandes de mouvement
        self.cmd_vel_pub = self.create_publisher(
            Twist,
            '/control',
            10
        )
        
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
        self.get_logger().info('Action Spielberg reçue - Séquence démarrée')
        self.current_goal_handle = goal_handle
        
        # Démarrer la séquence
        self.start_sequence()
        
        # L'action continue en arrière-plan via le timer
        # On retourne le goal_handle pour qu'il reste actif
        return goal_handle
    
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
        self.get_logger().info('Séquence de commandes arrêtée')
    
    def execute_sequence(self):
        """Exécute la séquence de commandes selon les timings"""
        # Envoyer le feedback si on a un goal actif
        if self.current_goal_handle is not None:
            feedback_msg = Spielberg.Feedback()
            feedback_msg.time_remaining = len(self.command_sequence) - self.sequence_index
            self.current_goal_handle.publish_feedback(feedback_msg)
        
        if self.sequence_index >= len(self.command_sequence):
            # Séquence terminée
            self.get_logger().info('Séquence terminée')
            self.stop_sequence()
            
            # Envoyer le résultat de l'action
            if self.current_goal_handle is not None:
                result = Spielberg.Result()
                result.success = True
                self.current_goal_handle.succeed()
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