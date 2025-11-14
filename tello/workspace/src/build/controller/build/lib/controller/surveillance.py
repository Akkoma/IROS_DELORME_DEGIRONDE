#!/home/alix.degironde/Public/ven_IROS/bin python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Empty, Int32
from geometry_msgs.msg import Twist


class Surveillance(Node):
    SURVEILLANCE_MODE = 3

    def __init__(self):
        super().__init__('surveillance')

        # état local
        self.current_mode = None
        self.is_airborne = True
        self.surveillance_timer = None

        # Subscriptions: on écoute le mode et les commandes takeoff/land
        self.mode_sub = self.create_subscription(
            Int32, '/drone_mode/state', self._mode_cb, 10
        )
        self.sub_takeoff = self.create_subscription(
            Empty, '/control/takeoff', self._takeoff_cb, 10
        )
        self.sub_land = self.create_subscription(
            Empty, '/control/land', self._land_cb, 10
        )

        # Publisher: publie des Twist de rotation sur /control
        self.pub_control = self.create_publisher(Twist, '/control', 10)

        self.get_logger().info('Noeud surveillance initialisé')

    def _mode_cb(self, msg: Int32):
        old_mode = self.current_mode
        self.current_mode = int(msg.data)
        # Si on vient d'entrer en mode surveillance et qu'on est airborne -> start
        if self.current_mode == self.SURVEILLANCE_MODE and self.is_airborne:
            self.start_surveillance_rotation()
        # Si on quitte le mode surveillance, arrêter la rotation
        if old_mode == self.SURVEILLANCE_MODE and self.current_mode != self.SURVEILLANCE_MODE:
            self.stop_surveillance_rotation()

    def _takeoff_cb(self, msg: Empty):
        # On considère que la commande takeoff signifie que l'appareil est maintenant en vol
        self.is_airborne = True
        if self.current_mode == self.SURVEILLANCE_MODE:
            self.start_surveillance_rotation()

    def _land_cb(self, msg: Empty):
        # On considère que la commande land signifie fin de vol
        self.is_airborne = False
        self.stop_surveillance_rotation()

    def start_surveillance_rotation(self):
        if self.surveillance_timer is not None:
            return
        self.surveillance_timer = self.create_timer(1.0, self._publish_rotate)
        self.get_logger().info('Rotation de surveillance démarrée (1 Hz)')

    def stop_surveillance_rotation(self):
        if self.surveillance_timer is None:
            return
        try:
            self.destroy_timer(self.surveillance_timer)
        except Exception:
            self.get_logger().debug('Erreur lors de la destruction du timer de surveillance')
        self.surveillance_timer = None
        self.get_logger().info('Rotation de surveillance arrêtée')

    def _publish_rotate(self):
        if self.current_mode != self.SURVEILLANCE_MODE or not self.is_airborne:
            return
        twist = Twist()
        twist.angular.z = 50
        twist.linear.x = 0.0
        twist.linear.y = 0.0
        twist.linear.z = 0.0
        self.pub_control.publish(twist)
        self.get_logger().debug('Commande rotation publiée (surveillance)')


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
