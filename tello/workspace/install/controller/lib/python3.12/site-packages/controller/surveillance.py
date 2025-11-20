#!/home/alix.degironde/Public/ven_IROS/bin python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from tello_msg.srv import Surveillance as SurveillanceSrv


class Surveillance(Node):
    def __init__(self):
        super().__init__('surveillance')
        
        # État de surveillance (activé/désactivé)
        self.is_active = False
        
        # Timer pour envoyer des commandes à 20 Hz (toutes les 0.05 secondes)
        self.timer = self.create_timer(0.05, self.timer_callback)
        
        # Service pour activer/désactiver la surveillance
        self.surveillance_service = self.create_service(
            SurveillanceSrv,
            '/surveillance/control',
            self.handle_surveillance_request
        )
        
        # Publisher pour envoyer les commandes de mouvement
        self.cmd_vel_pub = self.create_publisher(
            Twist,
            '/control',
            10
        )
        
        self.get_logger().info('noeud surveillance initialisé')
    
    def handle_surveillance_request(self, request, response):
        """Gère les demandes d'activation/désactivation de la surveillance"""
        old_state = self.is_active
        self.is_active = request.data
        
        if old_state != self.is_active:
            if self.is_active:
                self.get_logger().info('Mode surveillance ACTIVÉ - Rotation démarrée')
            else:
                self.get_logger().info('Mode surveillance DÉSACTIVÉ')
                # Arrêter le drone quand on désactive
                self.send_stop_command()
        
        response.success = True
        return response
    
    def send_stop_command(self):
        """Envoie une commande d'arrêt au drone"""
        twist = Twist()
        self.cmd_vel_pub.publish(twist)
    
    def timer_callback(self):
        """Appelé à 20 Hz pour envoyer les commandes de rotation"""
        if self.is_active:
            # Créer un message Twist pour la rotation
            twist = Twist()
            twist.linear.x = 0.0
            twist.linear.y = 0.0
            twist.linear.z = 0.0
            twist.angular.x = 0.0
            twist.angular.y = 0.0
            twist.angular.z = 100.0  # Rotation angulaire sur l'axe Z
            
            # Publier la commande
            self.cmd_vel_pub.publish(twist)


def main(args=None):
    rclpy.init(args=args)
    node = Surveillance()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
