#!/home/alix.degironde/Public/ven_IROS/bin python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32
from geometry_msgs.msg import Twist


class Surveillance(Node):
    SURVEILLANCE_MODE = 3

    def __init__(self):
        super().__init__('surveillance')

        # état local
        self.current_mode = None
        # flag indiquant si la rotation de surveillance est active
        self.surveillance_active = False

        # Subscription: on écoute l'état du mode (expose /drone_mode/state depuis tello_behaviour)
        self.mode_sub = self.create_subscription(Int32, '/drone_mode/state', self._mode_cb, 10)

        # Publisher: publie des Twist de rotation sur /control
        self.pub_control = self.create_publisher(Twist, '/control', 10)

        # Timer permanent à 20 Hz ; on choisit de créer le timer dès l'initialisation
        # et de n'envoyer la commande que si self.surveillance_active est True.
        self.surveillance_timer = self.create_timer(1.0 / 20.0, self._publish_rotate)

        self.get_logger().info('Noeud surveillance initialisé (timer 20Hz créé)')

    def _mode_cb(self, msg: Int32):
        old_mode = self.current_mode
        self.current_mode = int(msg.data)
        self.get_logger().info(f'Mode changé : {old_mode} -> {self.current_mode}')

        # activation/désactivation de la rotation uniquement selon le mode
        if self.current_mode == self.SURVEILLANCE_MODE:
            self.start_surveillance_rotation()
        elif old_mode == self.SURVEILLANCE_MODE and self.current_mode != self.SURVEILLANCE_MODE:
            self.stop_surveillance_rotation()

    def start_surveillance_rotation(self):
        if self.surveillance_active:
            self.get_logger().info('start_surveillance_rotation appelé, déjà actif')
            return
        self.surveillance_active = True
        self.get_logger().info('Rotation de surveillance ACTIVÉE (publishing à 20Hz)')

    def stop_surveillance_rotation(self):
        if not self.surveillance_active:
            self.get_logger().info('stop_surveillance_rotation appelé, déjà inactif')
            return
        self.surveillance_active = False
        self.get_logger().info('Rotation de surveillance DÉSACTIVÉE')

    def _publish_rotate(self):
        # Ce timer tourne 20 Hz en permanence ; on publie seulement si le mode est actif.
        if not self.surveillance_active or self.current_mode != self.SURVEILLANCE_MODE:
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
