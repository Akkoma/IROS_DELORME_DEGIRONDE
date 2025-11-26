#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from tello_msg.srv import DroneMode
import cv2
from cv_bridge import CvBridge, CvBridgeError


class QRCodeReader(Node):
    """
    Noeud ROS2 qui lit les QR codes pour changer le mode du drone.
    Les QR codes reconnus déclenchent un changement de mode via le service /drone_mode.
    """

    AVAILABLE_MODES = {
        'manual_control': 0,
        'qr_code_follower': 1,
        'spielberg': 2,
        'surveillance': 3
    }

    def __init__(self):
        super().__init__('qr_code_reader')

        self.bridge = CvBridge()
        self.qr_detector = cv2.QRCodeDetector()
        self.last_qr_code = None
        self.current_mode = 0

        self.subscription = self.create_subscription(Image, '/image_raw', self.qr_callback, 10)
        self.mode_client = self.create_client(DroneMode, '/drone_mode')

        while not self.mode_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('En attente du service /drone_mode...')

        self.get_logger().info('QR Code Reader prêt')
    
    def qr_callback(self, msg):
        """Détecte les QR codes et déclenche un changement de mode si nécessaire."""
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        except CvBridgeError as e:
            self.get_logger().error(f'Échec de conversion image: {e}')
            return

        data, bbox, _ = self.qr_detector.detectAndDecode(cv_image)

        if data and bbox is not None:
            qr_data = data.strip()
            self.last_qr_code = qr_data

            if qr_data in self.AVAILABLE_MODES and self.AVAILABLE_MODES[qr_data] != self.current_mode:
                self._call_mode_service(self.AVAILABLE_MODES[qr_data])
                self.current_mode = self.AVAILABLE_MODES[qr_data]


    def _call_mode_service(self, mode):
        """Appelle le service de changement de mode de manière asynchrone."""
        request = DroneMode.Request()
        request.mode = mode
        future = self.mode_client.call_async(request)
        future.add_done_callback(self._mode_response_callback)

    def _mode_response_callback(self, future):
        """Traite la réponse du service de changement de mode."""
        try:
            response = future.result()
            if not response.success:
                self.get_logger().error(f'Échec changement de mode: {response.message}')
        except Exception as e:
            self.get_logger().error(f'Erreur service drone_mode: {e}')


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