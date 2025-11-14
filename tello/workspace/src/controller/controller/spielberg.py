#!/home/alix.degironde/Public/ven_IROS/bin python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from tello_msg.msg import TelloStatus
from std_msgs.msg import Empty, String
from geometry_msgs.msg import Twist
import opencv as cv2

class Spielberg(Node):
    def __init__(self):
        super().__init__('spielberg')

def main(args=None):
    rclpy.init(args=args)
    node = Spielberg()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()