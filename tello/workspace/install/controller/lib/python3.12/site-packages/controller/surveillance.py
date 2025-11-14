#!/home/alix.degironde/Public/ven_IROS/bin python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32
from geometry_msgs.msg import Twist


class Surveillance(Node):
    SURVEILLANCE_MODE = 3

    def __init__(self):
        super().__init__('surveillance')
        
        # État du mode actuel
        self.current_mode = 0
        
        # Timer pour envoyer des commandes à 20 Hz (toutes les 0.05 secondes)
        self.timer = self.create_timer(0.05, self.timer_callback)
        
        # Subscriber pour écouter le mode du drone
        self.mode_sub = self.create_subscription(
            Int32,
            '/drone_mode/state',
            self.mode_callback,
            10
        )
        
        # Publisher pour envoyer les commandes de mouvement
        self.cmd_vel_pub = self.create_publisher(
            Twist,
            '/control',
            10
        )
        
        self.get_logger().info('Noeud surveillance initialisé')
    
    def mode_callback(self, msg):
        """Callback qui reçoit les changements de mode"""
        old_mode = self.current_mode
        self.current_mode = msg.data
        
        if old_mode != self.current_mode:
            if self.current_mode == self.SURVEILLANCE_MODE:
                self.get_logger().info('Mode surveillance activé - Rotation démarrée')
            else:
                self.get_logger().info(f'Mode surveillance désactivé (mode actuel: {self.current_mode})')
    
    def timer_callback(self):
        """Appelé à 20 Hz pour envoyer les commandes de rotation"""
        if self.current_mode == self.SURVEILLANCE_MODE:
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
