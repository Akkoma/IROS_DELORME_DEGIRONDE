#!/usr/bin/env python3

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

class Spielberg(Node):
    def __init__(self):
        super().__init__('spielberg')
        self.bridge = CvBridge()
        self.qr_detector = cv2.QRCodeDetector()
        self.subscription = self.create_subscription(Image, '/image_raw', self.qr_callback, 10)
        self.last_qr_code = None

        # Subscriber pour écouter le mode du drone
        self.mode_sub = self.create_subscription(
            Int32,
            '/drone_mode/state',
            self.mode_callback,
            10
        )

    def display(self, img, bbox):
        n = len(bbox)

        pt1 = int(bbox[0][0][0]), int(bbox[0][0][1])    # angle en haut à gauche
        pt2 = int(bbox[0][2][0]), int(bbox[0][2][1])    # angle en bas à droite
        
        color = (255, 0, 0)

        cv2.rectangle(img, pt1, pt2, color, 2)

    def qr_callback(self, msg):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        except CvBridgeError as e:
            self.get_logger().error(f'Failed to convert image: {e}')
            return

        data, bbox, rectified_image = self.qr_detector.detectAndDecode(cv_image)

        if len(data) > 0:
            qr_data = data.strip()

            if qr_data != self.last_qr_code:
                self.last_qr_code = qr_data
                self.get_logger().info(f'QR Code detected : {qr_data}')

            self.display(cv_image, bbox)
            cv2.imshow("Results", cv_image)
            
            if rectified_image is not None and rectified_image.size > 0:
                rectified_image = np.uint8(rectified_image)
                cv2.imshow("Rectified QRCode", rectified_image)
        else:
            cv2.imshow("Results", cv_image)

        cv2.waitKey(3)

def main(args=None):
    rclpy.init(args=args)
    node = Spielberg()
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
