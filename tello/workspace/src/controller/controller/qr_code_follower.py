#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import Int32
from geometry_msgs.msg import Twist
import cv2
from cv_bridge import CvBridge, CvBridgeError
import numpy as np


class QRCodeFollower(Node):
    """Noeud ROS2 pour le suivi automatique de QR codes par le drone."""

    QRFOLLOWER_MODE = 1
    CONTROL_SPEED = 30.0

    def __init__(self):
        super().__init__('qr_code_follower')

        self.bridge = CvBridge()
        self.qr_detector = cv2.QRCodeDetector()
        self.current_mode = 0
        self.last_qr_code = None

        # Subscribers
        self.subscription = self.create_subscription(
            Image, '/image_raw', self.qr_callback, 10
        )
        self.mode_sub = self.create_subscription(
            Int32, '/drone_mode/state', self.mode_callback, 10
        )

        # Publisher pour les commandes de mouvement
        self.cmd_vel_pub = self.create_publisher(Twist, '/control', 10)

        self.get_logger().info('QR Follower initialisé')

    def mode_callback(self, msg):
        """Met à jour le mode actuel du drone."""
        self.current_mode = msg.data

    def get_qr_center(self, bbox):
        """Calcule le centre et la taille du QR code à partir de sa bounding box."""
        points = bbox[0]
        x_coords = [p[0] for p in points]
        y_coords = [p[1] for p in points]

        center_x = int(np.mean(x_coords))
        center_y = int(np.mean(y_coords))
        size = ((max(x_coords) - min(x_coords)) + (max(y_coords) - min(y_coords))) / 2

        return center_x, center_y, size

    def calculate_control_command(self, qr_center_x, qr_center_y, img_width, img_height):
        """
        Calcule les commandes de contrôle pour recentrer le QR code.
        Divise l'image en 9 zones (3x3) pour déterminer la direction.
        """
        img_center_x = img_width / 2
        img_center_y = img_height / 2
        zone_x = img_width / 3
        zone_y = img_height / 3

        twist = Twist()

        # Contrôle horizontal
        if qr_center_x < img_center_x - zone_x / 2:
            twist.linear.x = -self.CONTROL_SPEED
        elif qr_center_x > img_center_x + zone_x / 2:
            twist.linear.x = self.CONTROL_SPEED

        # Contrôle vertical
        if qr_center_y < img_center_y - zone_y / 2:
            twist.linear.z = self.CONTROL_SPEED
        elif qr_center_y > img_center_y + zone_y / 2:
            twist.linear.z = -self.CONTROL_SPEED

        return twist

    def display(self, img, bbox, qr_center_x, qr_center_y):
        """Affiche le QR code détecté avec des informations de suivi."""
        pt1 = int(bbox[0][0][0]), int(bbox[0][0][1])
        pt2 = int(bbox[0][2][0]), int(bbox[0][2][1])
        img_center_x = img.shape[1] // 2
        img_center_y = img.shape[0] // 2

        # Rectangle autour du QR code
        cv2.rectangle(img, pt1, pt2, (255, 0, 0), 2)

        # Centre du QR code (vert) et centre de l'image (rouge)
        cv2.circle(img, (qr_center_x, qr_center_y), 5, (0, 255, 0), -1)
        cv2.circle(img, (img_center_x, img_center_y), 5, (0, 0, 255), -1)

        # Ligne entre les deux centres
        cv2.line(img, (qr_center_x, qr_center_y), (img_center_x, img_center_y), (255, 255, 0), 2)

        # Affichage de l'erreur de position
        error_x = qr_center_x - img_center_x
        error_y = qr_center_y - img_center_y
        cv2.putText(img, f"Error X: {error_x:.1f}, Y: {error_y:.1f}",
                    (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)


    def qr_callback(self, msg):
        """Traite les images pour détecter et suivre un QR code."""
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        except CvBridgeError as e:
            self.get_logger().error(f'Échec de conversion image: {e}')
            return

        img_height, img_width = cv_image.shape[:2]
        data, bbox, _ = self.qr_detector.detectAndDecode(cv_image)

        if self.current_mode != self.QRFOLLOWER_MODE:
            cv2.imshow("Results", cv_image)
            cv2.waitKey(3)
            return

        if data and bbox is not None:
            qr_data = data.strip()
            self.last_qr_code = qr_data

            qr_center_x, qr_center_y, _ = self.get_qr_center(bbox)

            twist = self.calculate_control_command(qr_center_x, qr_center_y, img_width, img_height)
            self.cmd_vel_pub.publish(twist)

            self.display(cv_image, bbox, qr_center_x, qr_center_y)
            cv2.putText(cv_image, f"Cmd - X:{twist.linear.x:.1f} Z:{twist.linear.z:.1f}",
                        (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 255), 2)
        else:
            # Aucun QR code détecté : arrêt du drone
            self.cmd_vel_pub.publish(Twist())
            cv2.putText(cv_image, "QR Code non detecte - Arret",
                        (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)

        cv2.imshow("Results", cv_image)
        cv2.waitKey(3)

def main(args=None):
    rclpy.init(args=args)
    node = QRCodeFollower()
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
