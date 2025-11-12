#!/home/alix.degironde/Public/ven_IROS/bin python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from std_msgs.msg import Empty, String
from geometry_msgs.msg import Twist
import time


class ManualControl(Node):
    def __init__(self):
        super().__init__('manual_control')

        # --- Souscription au joystick ---
        self.subscription = self.create_subscription(Joy, '/joy', self.joy_callback, 10)
        self.subscription  # empêche le warning

        # --- Publishers pour le drone Tello ---
        self.pub_takeoff = self.create_publisher(Empty, '/takeoff', 10)
        self.pub_land = self.create_publisher(Empty, '/land', 10)
        self.pub_emergency = self.create_publisher(Empty, '/emergency', 10)
        self.pub_flip = self.create_publisher(String, '/flip', 10)
        self.pub_cmd_vel = self.create_publisher(Twist, '/cmd_vel', 10)

        # --- Mapping des boutons ---
        self.BTN_TAKEOFF = 0       # bouton décollage
        self.BTN_LAND = 1          # bouton atterrissage
        self.BTN_EMERGENCY = 2     # bouton arrêt d’urgence
        self.BTN_FLIP_F = 3          # optionnel
        self.BTN_FLIP_L = 4          # optionnel
        self.BTN_FLIP_R = 5          # optionnel

        # --- Mapping des axes ---
        self.AXIS_LR = 0           # gauche/droite
        self.AXIS_FB = 1           # avant/arrière
        self.AXIS_YAW = 3          # rotation (yaw)
        self.AXIS_ALT = 4          # montée/descente

        self.get_logger().info("Manual control pour drone Tello initialisé !")

        # --- Debounce / anti-rebond pour boutons ---
        # Durée minimale entre deux envois pour le même bouton (en secondes)
        self.button_debounce = 1.0
        # Dictionnaire button_index -> last send time (monotonic)
        self.last_button_time = {}
        # État précédent des boutons pour détecter le front montant (rising edge)
        self.prev_buttons = []
        # Compteur pour debug
        self.button_send_count = {}

    def joy_callback(self, msg: Joy):
        buttons = msg.buttons
        axes = msg.axes

        # --- Gestion des boutons avec debounce et front montant ---
        now = time.monotonic()

        # S'assurer que prev_buttons a la même taille que buttons
        if not self.prev_buttons or len(self.prev_buttons) != len(buttons):
            # initialiser à des zéros (non appuyés)
            self.prev_buttons = [0] * len(buttons)

        # Helper pour vérifier et envoyer sur front montant en respectant le debounce
        def handle_button(btn_index: int, action_pub, log_level='info', log_msg=None):
            if btn_index >= len(buttons):
                return
            pressed = bool(buttons[btn_index])
            prev_pressed = bool(self.prev_buttons[btn_index])
            # front montant : maintenant appuyé, auparavant non
            if pressed and not prev_pressed:
                last = self.last_button_time.get(btn_index, 0)
                if now - last >= self.button_debounce:
                    # envoyer l'action
                    if log_level == 'warn':
                        self.get_logger().warn(log_msg if log_msg else "action envoyé")
                    else:
                        self.get_logger().info(log_msg if log_msg else "action envoyé")
                    action_pub.publish(Empty())
                    self.last_button_time[btn_index] = now
                else:
                    self.get_logger().debug(f"Bouton {btn_index} ignoré (debounce) - {now-last:.2f}s depuis dernier envoi")

        # Takeoff
        handle_button(self.BTN_TAKEOFF, self.pub_takeoff, 'info', "Décollage envoyé")
        # flip
        handle_button(self.BTN_FLIP, self.pub_flip, 'info', "Flip envoyé")
        # Land
        handle_button(self.BTN_LAND, self.pub_land, 'info', "Atterrissage envoyé")
        # Emergency
        handle_button(self.BTN_EMERGENCY, self.pub_emergency, 'warn', "Arrêt d’urgence envoyé !")

        # --- Mouvement du drone ---
        twist = Twist()
        # Les valeurs d’axes sont entre -1 et 1
        # À adapter selon la sensibilité souhaitée :
        twist.linear.x = axes[self.AXIS_FB]      # avant/arrière
        twist.linear.y = axes[self.AXIS_LR]      # gauche/droite
        twist.linear.z = axes[self.AXIS_ALT]     # monter/descendre
        twist.angular.z = axes[self.AXIS_YAW]    # rotation

        # Ne publie que s’il y a un mouvement significatif
        if any(abs(v) > 0.1 for v in [
            twist.linear.x, twist.linear.y, twist.linear.z, twist.angular.z
        ]):
            self.pub_cmd_vel.publish(twist)
            self.get_logger().debug(
                f"Déplacement publié: x={twist.linear.x:.2f}, y={twist.linear.y:.2f}, z={twist.linear.z:.2f}, yaw={twist.angular.z:.2f}"
            )

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
