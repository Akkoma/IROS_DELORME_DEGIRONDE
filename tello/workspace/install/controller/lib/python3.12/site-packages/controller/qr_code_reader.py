#!/home/alix.degironde/Public/ven_IROS/bin python3

import sys
import time
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from tello_msg.msg import TelloStatus
from std_msgs.msg import Int32
from geometry_msgs.msg import Twist
from tello_msg.srv import DroneMode
import cv2
from cv_bridge import CvBridge, CvBridgeError
import numpy as np

class QRCodeReader(Node):

    def __init__(self):
        super().__init__('qr_code_reader')
        self.bridge = CvBridge()
        self.qr_detector = cv2.QRCodeDetector()
        self.last_qr_code = None
        self.current_mode = 0
        
        # État du mode actuel
        self.available_mode = {'manual_control':0,'qr_code_follower':1,'spielberg':2,'surveillance':3}
        
        # Subscriber pour les images
        self.subscription = self.create_subscription(Image, '/image_raw', self.qr_callback, 10)
        
        # Client pour appeler le service de changement de mode
        self.mode_client = self.create_client(DroneMode, '/drone_mode')
        
        # Attendre que le service soit disponible
        while not self.mode_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('En attente du service /drone_mode...')
        
        self.get_logger().info('QR Code Reader prêt - Service /drone_mode disponible')
    
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
            
            if qr_data in self.available_mode and self.available_mode[qr_data] != self.current_mode:
                self.get_logger().info(f'Switching to mode: {qr_data}')
                # Appeler le service pour changer de mode
                self.call_mode_service(self.available_mode[qr_data])
                self.current_mode = self.available_mode[qr_data]


    
    def call_mode_service(self, mode):
        """Appelle le service pour changer de mode"""
        request = DroneMode.Request()
        request.mode = mode
        
        # Appel asynchrone du service
        future = self.mode_client.call_async(request)
        future.add_done_callback(self.mode_response_callback)
    
    def mode_response_callback(self, future):
        """Callback pour la réponse du service de changement de mode"""
        try:
            response = future.result()
            if response.success:
                self.get_logger().info(f'✓ {response.message}')
            else:
                self.get_logger().error(f'✗ Échec: {response.message}')
        except Exception as e:
            self.get_logger().error(f'Erreur lors de l\'appel au service: {e}')


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