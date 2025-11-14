#!/home/alix.degironde/Public/ven_IROS/bin python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from tello_msg.msg import TelloStatus
from std_msgs.msg import Empty, String
from geometry_msgs.msg import Twist
import cv2
from cv_bridge import CvBridge, CvBridgeError

class Spielberg(Node):
    def __init__(self):
        super().__init__('spielberg')
        self.bridge = CvBridge()
        self.subscription = self.create_subscription(Image, '/image_raw', self.qr_callback, 10)
        self.last_qr_code = None

    def qr_callback(self, msg):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        except CvBridgeError as e:
            self.get_logger().error(f'Failed to convert image: {e}')
            return

        annotated_image = cv_image.copy()

        data, points, _ = self.qr_detector.detectAndDecode(cv_image)

        if data:
            qr_data = data.strip()

            if qr_data != self.last_qr_code:
                self.last_qr_code = qr_data

                self.get_logger().info(f'QR Code detected : {qr_data}')
        cv2.imshow("Image window", cv_image)
        cv2.waitKey(3)

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