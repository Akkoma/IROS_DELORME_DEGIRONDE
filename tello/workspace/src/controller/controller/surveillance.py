#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from tello_msg.srv import Surveillance as SurveillanceSrv


class Surveillance(Node):
    """Noeud ROS2 pour le mode surveillance du drone (rotation continue)."""

    ROTATION_SPEED = 100.0
    TIMER_PERIOD = 0.05  # 20 Hz

    def __init__(self):
        super().__init__('surveillance')

        self.is_active = False

        self.timer = self.create_timer(self.TIMER_PERIOD, self.timer_callback)
        self.surveillance_service = self.create_service(
            SurveillanceSrv, '/surveillance/control', self.handle_surveillance_request
        )
        self.cmd_vel_pub = self.create_publisher(Twist, '/control', 10)

        self.get_logger().info('Noeud surveillance initialisé')
    
    def handle_surveillance_request(self, request, response):
        """Active ou désactive le mode surveillance."""
        if self.is_active != request.data:
            self.is_active = request.data
            if not self.is_active:
                self.cmd_vel_pub.publish(Twist())

        response.success = True
        return response

    def timer_callback(self):
        """Envoie la commande de rotation à 20 Hz si le mode est actif."""
        if self.is_active:
            twist = Twist()
            twist.angular.z = self.ROTATION_SPEED
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
