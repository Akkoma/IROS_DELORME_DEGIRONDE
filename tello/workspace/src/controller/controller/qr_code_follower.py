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
    QRFOLLOWER_MODE = 1

    def __init__(self):
        super().__init__('spielberg')
        self.bridge = CvBridge()
        self.qr_detector = cv2.QRCodeDetector()
        
        # État du mode actuel
        self.current_mode = 0
        
        # Paramètres de contrôle PID
        self.kp_x = 0.3  # Gain proportionnel pour l'axe X (gauche-droite)
        self.kp_y = 0.3  # Gain proportionnel pour l'axe Y (haut-bas)
        self.kp_z = 0.5  # Gain proportionnel pour l'axe Z (avant-arrière)
        
        # Seuils de tolérance (en pixels)
        self.tolerance_x = 30
        self.tolerance_y = 30
        
        # Zone morte pour éviter les oscillations
        self.deadzone = 20
        
        # Dernière position du QR code
        self.last_qr_position = None
        self.last_qr_code = None
        
        # Subscriber pour les images
        self.subscription = self.create_subscription(
            Image, 
            '/image_raw', 
            self.qr_callback, 
            10
        )
        
        # Subscriber pour écouter le mode du drone
        self.mode_sub = self.create_subscription(
            Int32,
            '/drone_mode/state',
            self.mode_callback,
            10
        )
        
        # Publisher pour envoyer les commandes de mouvement
        self.cmd_vel_pub = self.create_publisher(
            Twist,
            '/control',
            10
        )
        
        self.get_logger().info('QR Follower initialisé')
    
    def mode_callback(self, msg):
        """Callback qui reçoit les changements de mode"""
        old_mode = self.current_mode
        self.current_mode = msg.data
        
        if old_mode != self.current_mode:
            if self.current_mode == self.QRFOLLOWER_MODE:
                self.get_logger().info('Mode QR Follower activé')
            else:
                self.get_logger().info(f'Mode QR Follower désactivé (mode actuel: {self.current_mode})')

    
    def get_qr_center(self, bbox):
        """Calcule le centre du QR code à partir de sa bounding box"""
        points = bbox[0]
        x_coords = [p[0] for p in points]
        y_coords = [p[1] for p in points]
        
        center_x = int(np.mean(x_coords))
        center_y = int(np.mean(y_coords))
        
        # Calculer la taille du QR code pour estimer la distance
        width = max(x_coords) - min(x_coords)
        height = max(y_coords) - min(y_coords)
        size = (width + height) / 2
        
        return center_x, center_y, size
    
    def calculate_control_command(self, qr_center_x, qr_center_y, qr_size, img_width, img_height):
        """Calcule les commandes de contrôle pour recentrer le QR code"""
        # Centre de l'image
        img_center_x = img_width / 2
        img_center_y = img_height / 2
        
        # Erreur de position
        error_x = qr_center_x - img_center_x
        error_y = qr_center_y - img_center_y
        
        # Créer le message Twist
        twist = Twist()
        
        # Contrôle horizontal (axe Y du drone - mouvement gauche/droite)
        if abs(error_x) > self.deadzone:
            # Positive error_x = QR à droite -> drone va à droite
            twist.linear.y = np.clip(self.kp_x * error_x, -100.0, 100.0)
        else:
            twist.linear.y = 0.0
        
        # Contrôle vertical (axe Z du drone - mouvement haut/bas)
        if abs(error_y) > self.deadzone:
            # Positive error_y = QR en bas -> drone descend
            # On inverse car l'axe Z positif va vers le haut
            twist.linear.z = np.clip(-self.kp_y * error_y, -100.0, 100.0)
        else:
            twist.linear.z = 0.0
        
        # Contrôle de profondeur (axe X du drone - mouvement avant/arrière)
        # Basé sur la taille du QR code
        # Taille cible approximative (à ajuster selon vos besoins)
        target_size = 200.0
        size_error = target_size - qr_size
        
        if abs(size_error) > 20:
            # Si QR trop petit -> avancer, si trop grand -> reculer
            twist.linear.x = np.clip(self.kp_z * size_error, -100.0, 100.0)
        else:
            twist.linear.x = 0.0
        
        # Pas de rotation pour l'instant
        twist.angular.x = 0.0
        twist.angular.y = 0.0
        twist.angular.z = 0.0
        
        return twist

    def display(self, img, bbox, qr_center_x, qr_center_y):
        """Affiche le QR code détecté avec des informations de suivi"""
        n = len(bbox)

        pt1 = int(bbox[0][0][0]), int(bbox[0][0][1])    # angle en haut à gauche
        pt2 = int(bbox[0][2][0]), int(bbox[0][2][1])    # angle en bas à droite
        
        color = (255, 0, 0)
        cv2.rectangle(img, pt1, pt2, color, 2)
        
        # Dessiner le centre du QR code
        cv2.circle(img, (qr_center_x, qr_center_y), 5, (0, 255, 0), -1)
        
        # Dessiner le centre de l'image
        img_center_x = img.shape[1] // 2
        img_center_y = img.shape[0] // 2
        cv2.circle(img, (img_center_x, img_center_y), 5, (0, 0, 255), -1)
        
        # Dessiner une ligne entre les deux centres
        cv2.line(img, (qr_center_x, qr_center_y), (img_center_x, img_center_y), (255, 255, 0), 2)
        
        # Afficher l'erreur
        error_x = qr_center_x - img_center_x
        error_y = qr_center_y - img_center_y
        text = f"Error X: {error_x:.1f}, Y: {error_y:.1f}"
        cv2.putText(img, text, (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)


    def qr_callback(self, msg):
        """Callback principal pour traiter les images et suivre le QR code"""
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        except CvBridgeError as e:
            self.get_logger().error(f'Failed to convert image: {e}')
            return

        img_height, img_width = cv_image.shape[:2]
        data, bbox, rectified_image = self.qr_detector.detectAndDecode(cv_image)

        # Réinitialiser la commande si pas en mode QR Follower
        if self.current_mode != self.QRFOLLOWER_MODE:
            cv2.imshow("Results", cv_image)
            cv2.waitKey(3)
            return

        if len(data) > 0 and bbox is not None:
            qr_data = data.strip()

            if qr_data != self.last_qr_code:
                self.last_qr_code = qr_data
                self.get_logger().info(f'QR Code detected: {qr_data}')
            
            # Calculer le centre et la taille du QR code
            qr_center_x, qr_center_y, qr_size = self.get_qr_center(bbox)
            self.last_qr_position = (qr_center_x, qr_center_y, qr_size)
            
            # Calculer et envoyer les commandes de contrôle
            twist = self.calculate_control_command(
                qr_center_x, qr_center_y, qr_size, img_width, img_height
            )
            self.cmd_vel_pub.publish(twist)
            
            # Affichage avec informations de suivi
            self.display(cv_image, bbox, qr_center_x, qr_center_y)
            
            # Afficher les commandes envoyées
            cmd_text = f"Cmd - X:{twist.linear.x:.1f} Y:{twist.linear.y:.1f} Z:{twist.linear.z:.1f}"
            cv2.putText(cv_image, cmd_text, (10, 60), 
                       cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 255), 2)
            
            cv2.imshow("Results", cv_image)
            
            if rectified_image is not None and rectified_image.size > 0:
                rectified_image = np.uint8(rectified_image)
                cv2.imshow("Rectified QRCode", rectified_image)
        else:
            # Aucun QR code détecté - arrêter le drone
            if self.current_mode == self.QRFOLLOWER_MODE:
                twist = Twist()  # Toutes les valeurs à 0
                self.cmd_vel_pub.publish(twist)
                
                # Afficher un message
                cv2.putText(cv_image, "QR Code non detecte - Arret", (10, 30),
                           cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)
            
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
