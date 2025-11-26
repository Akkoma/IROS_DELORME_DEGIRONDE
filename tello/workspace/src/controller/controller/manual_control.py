#!/home/alix.degironde/Public/ven_IROS/bin python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from tello_msg.msg import TelloStatus
from std_msgs.msg import Empty, String
from geometry_msgs.msg import Twist
import time


class ManualControl(Node):
    def __init__(self):
        super().__init__('manual_control')

        # --- Souscription au joystick ---
        self.subscription = self.create_subscription(Joy, '/joy', self.joy_callback, 10)
        #self.subscription_status = self.create_subscription(TelloStatus, '/status', self.status_callback, 10)
        #self.subscription_status
        self.subscription  # empêche le warning

        # --- Publishers pour le noeud tello_behaviour (préfixe /control/) ---
        self.pub_takeoff = self.create_publisher(Empty, '/control/takeoff', 10)
        self.pub_land = self.create_publisher(Empty, '/control/land', 10)
        self.pub_emergency = self.create_publisher(Empty, '/control/emergency', 10)
        self.pub_flip = self.create_publisher(String, '/control/flip', 10)
        self.pub_control = self.create_publisher(Twist, '/control/cmd_vel', 10)

        # --- Mapping des boutons ---
        self.BTN_TAKEOFF = 0       # bouton décollage
        self.BTN_LAND = 1          # bouton atterrissage
        self.BTN_EMERGENCY = 8     # bouton arrêt d'urgence
        self.BTN_FLIP_F = 3          # optionnel
        self.BTN_FLIP_L = 4          # optionnel
        self.BTN_FLIP_R = 5          # optionnel
        self.BTN_FLIP_B = 2          # optionnel

        # --- Mapping des axes ---
        self.AXIS_LR = 1           # gauche/droite
        self.AXIS_FB = 0           # avant/arrière
        self.AXIS_YAW = 3          # rotation (yaw)
        self.AXIS_ALT = 4          # montée/descente

        self.get_logger().info("Manual control pour drone Tello initialisé !")

        # --- Debounce / anti-rebond pour boutons ---
        # Durée minimale entre deux envois pour le même bouton (en secondes)
        self.button_debounce = 1.0  # 1 seconde de délai minimum entre chaque envoi
        # Dictionnaire button_index -> last send time (monotonic)
        self.last_button_time = {}
        # État précédent des boutons pour détecter le front montant (rising edge)
        self.prev_buttons = []
        # Compteur d'envois pour debug
        self.button_send_count = {}
        self.altitude_condition = 1

    #def status_callback(self, msg: TelloStatus):
    #    altitude = msg.distance_tof
    #    self.get_logger().info(f"Statut du drone reçu: Altitude à {altitude} cm")
    #    if altitude < 30 :
    #        self.altitude_condition = 1
    #    else:
    #        self.altitude_condition = 0
    # Fonction originale utilisant le ToF pour vérifier l'altitude, permettant ou non le décollage/atterrissage

    def joy_callback(self, msg: Joy):
        buttons = msg.buttons
        axes = msg.axes

        # --- Gestion des boutons avec debounce et front montant ---
        now = time.monotonic()

        # S'assurer que prev_buttons a la même taille que buttons
        if not self.prev_buttons or len(self.prev_buttons) != len(buttons):
            # initialiser à des zéros (non appuyés)
            self.prev_buttons = [0] * len(buttons)

        # --- Traitement de chaque bouton avec debounce et front montant ---
        for btn_index in range(len(buttons)):
            pressed = bool(buttons[btn_index])
            prev_pressed = bool(self.prev_buttons[btn_index]) if btn_index < len(self.prev_buttons) else False
            
            # Détection du front montant (transition de non-appuyé à appuyé)
            if pressed and not prev_pressed:
                # Vérifier le délai minimum (debounce)
                last_time = self.last_button_time.get(btn_index, 0)
                time_since_last = now - last_time
                
                if time_since_last >= self.button_debounce:
                    # Mettre à jour le compteur pour debug
                    self.button_send_count[btn_index] = self.button_send_count.get(btn_index, 0) + 1
                    count = self.button_send_count[btn_index]
                    
                    # ======== CASES: Traiter selon le bouton ========
                    
                    if btn_index == self.BTN_TAKEOFF:

                        # Commande Takeoff: envoie Empty
                        self.get_logger().info(f"[Commande #{count}] Décollage envoyé")
                        self.pub_takeoff.publish(Empty())
                        self.last_button_time[btn_index] = now
                        
                    elif btn_index == self.BTN_LAND:

                        # Commande Land: envoie Empty
                        self.get_logger().info(f"[Commande #{count}] Atterrissage envoyé")
                        self.pub_land.publish(Empty())
                        self.last_button_time[btn_index] = now
                        
                    elif btn_index == self.BTN_EMERGENCY:
                        # Commande Emergency: envoie Empty
                        self.get_logger().warn(f"[Commande #{count}] Arrêt d'urgence envoyé !")
                        self.pub_emergency.publish(Empty())
                        self.last_button_time[btn_index] = now
                        
                    elif btn_index == self.BTN_FLIP_F:
                        # Commande Flip: envoie String avec direction
                        self.get_logger().info(f"[Commande #{count}] Flip envoyé (direction: f)")
                        flip_msg = String()
                        flip_msg.data = 'f'  # b=backward, f=forward, l=left, r=right
                        self.pub_flip.publish(flip_msg)
                        self.last_button_time[btn_index] = now
                    
                    elif btn_index == self.BTN_FLIP_L:
                        # Commande Flip: envoie String avec direction
                        self.get_logger().info(f"[Commande #{count}] Flip envoyé (direction: l)")
                        flip_msg = String()
                        flip_msg.data = 'l'  # b=backward, f=forward, l=left, r=right
                        self.pub_flip.publish(flip_msg)
                        self.last_button_time[btn_index] = now
                    
                    elif btn_index == self.BTN_FLIP_R:
                        # Commande Flip: envoie String avec direction
                        self.get_logger().info(f"[Commande #{count}] Flip envoyé (direction: r)")
                        flip_msg = String()
                        flip_msg.data = 'r'  # b=backward, f=forward, l=left, r=right
                        self.pub_flip.publish(flip_msg)
                        self.last_button_time[btn_index] = now

                    elif btn_index == self.BTN_FLIP_B:
                        # Commande Flip: envoie String avec direction
                        self.get_logger().info(f"[Commande #{count}] Flip envoyé (direction: b)")
                        flip_msg = String()
                        flip_msg.data = 'b'  # b=backward, f=forward, l=left, r=right
                        self.pub_flip.publish(flip_msg)
                        self.last_button_time[btn_index] = now
                        
                    # ================================================
                else:
                    # Bouton ignoré à cause du debounce
                    wait_time = self.button_debounce - time_since_last
                    self.get_logger().warn(
                        f"Bouton {btn_index} BLOQUÉ (anti-spam) - "
                        f"attendez encore {wait_time:.1f}s"
                    )

        # --- Mouvement du drone ---
        twist = Twist()
        # Les valeurs d'axes du joystick sont entre -1 et 1
        # Le drone Tello attend des valeurs entre -100 et 100
        # On multiplie par 100 pour convertir l'échelle
        twist.linear.x = axes[self.AXIS_FB] * 100.0      # avant/arrière
        twist.linear.y = axes[self.AXIS_LR] * 100.0      # gauche/droite
        twist.linear.z = axes[self.AXIS_ALT] * 100.0     # monter/descendre
        twist.angular.z = axes[self.AXIS_YAW] * 100.0    # rotation

        # Vérifier si les joysticks sont au centre (zone morte de 10%)
        deadzone = 10.0  # Seuil de 10 sur 100
        has_movement = any(abs(v) > deadzone for v in [
            twist.linear.x, twist.linear.y, twist.linear.z, twist.angular.z
        ])
        
        if has_movement:
            # Publier les commandes de mouvement
            self.pub_control.publish(twist)
            self.get_logger().debug(
                f"Déplacement: x={twist.linear.x:.0f}, y={twist.linear.y:.0f}, z={twist.linear.z:.0f}, yaw={twist.angular.z:.0f}"
            )
        else:
            # Joysticks relâchés : envoyer commande d'arrêt (tous les axes à 0)
            stop_twist = Twist()
            stop_twist.linear.x = 0.0
            stop_twist.linear.y = 0.0
            stop_twist.linear.z = 0.0
            stop_twist.angular.z = 0.0
            self.pub_control.publish(stop_twist)
            # Pas de log pour éviter de spammer quand le joystick est au repos

        # Mettre à jour l'état précédent des boutons
        self.prev_buttons = list(buttons)


def main(args=None):
    rclpy.init(args=args)
    node = ManualControl()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
