import sys
import time
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from tello_msg.msg import TelloStatus
from std_msgs.msg import Int32
from geometry_msgs.msg import Twist
import cv2
from cv_bridge import CvBridge, CvBridgeError
import numpy as np

class QRCodeReader(Node):

    def __init__(self):
        super().__init__('qr_code_reader')
        self.bridge = CvBridge()
        self.qr_detector = cv2.QRCodeDetector()
        
        # État du mode actuel
        self.available_mode = {'qr_code_follower':1,'spielberg':2,'surveillance':3}
        
        # Subscriber pour les images
        self.subscription = self.create_subscription(Image, '/image_raw', self.qr_callback, 10)
        
        self.mode_pub = self.create_publisher(Int32, '/drone_mode/state', 10)
    
    def qr_callback(self, msg):
        """Callback principal pour traiter les images et suivre le QR code"""
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        except CvBridgeError as e:
            self.get_logger().error(f'Failed to convert image: {e}')
            return

        data, bbox, rectified_image = self.qr_detector.detectAndDecode(cv_image)

        if len(data) > 0 and bbox is not None:
            qr_data = data.strip()

            if qr_data != self.last_qr_code:
                self.last_qr_code = qr_data
                self.get_logger().info(f'QR Code detected: {qr_data}')
            
            if qr_data in self.available_mode:
                self.get_logger().info(f'Switching to mode: {qr_data}')
                mode_msg = Int32()
                mode_msg.data = self.available_mode[qr_data]
                self.mode_pub.publish(mode_msg)
            
            cv2.imshow("Results", cv_image)

        cv2.waitKey(3)


def main(args=None):
    rclpy.init(args=args)
    node = QRCodeReader()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        cv2.destroyAllWindows()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()