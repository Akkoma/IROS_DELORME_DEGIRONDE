#!/usr/bin/env python3

import time

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from std_msgs.msg import Empty, String
from geometry_msgs.msg import Twist


class ManualControl(Node):
    """Noeud ROS2 pour le contrôle manuel du drone Tello via joystick."""

    # Mapping des boutons du joystick
    BTN_TAKEOFF = 0
    BTN_LAND = 1
    BTN_FLIP_B = 2
    BTN_FLIP_F = 3
    BTN_FLIP_L = 4
    BTN_FLIP_R = 5
    BTN_EMERGENCY = 8

    # Mapping des axes du joystick
    AXIS_FB = 0
    AXIS_LR = 1
    AXIS_YAW = 3
    AXIS_ALT = 4

    # Constantes de configuration
    DEBOUNCE_DELAY = 1.0
    DEADZONE_THRESHOLD = 10.0
    AXIS_SCALE = 100.0

    def __init__(self):
        super().__init__('manual_control')

        # Subscription au joystick
        self.subscription = self.create_subscription(Joy, '/joy', self.joy_callback, 10)

        # Publishers vers tello_behaviour
        self.pub_takeoff = self.create_publisher(Empty, '/control/takeoff', 10)
        self.pub_land = self.create_publisher(Empty, '/control/land', 10)
        self.pub_emergency = self.create_publisher(Empty, '/control/emergency', 10)
        self.pub_flip = self.create_publisher(String, '/control/flip', 10)
        self.pub_control = self.create_publisher(Twist, '/control/cmd_vel', 10)

        # État pour le debounce et la détection des fronts montants
        self.last_button_time = {}
        self.prev_buttons = []

        self.get_logger().info("Manual control pour drone Tello initialisé")

    def joy_callback(self, msg: Joy):
        """Traite les entrées du joystick pour contrôler le drone."""
        self._handle_buttons(msg.buttons)
        self._handle_movement(msg.axes)
        self.prev_buttons = list(msg.buttons)

    def _handle_buttons(self, buttons):
        """Gère les appuis boutons avec debounce et détection de front montant."""
        now = time.monotonic()

        if not self.prev_buttons or len(self.prev_buttons) != len(buttons):
            self.prev_buttons = [0] * len(buttons)

        for btn_index in range(len(buttons)):
            is_pressed = bool(buttons[btn_index])
            was_pressed = bool(self.prev_buttons[btn_index]) if btn_index < len(self.prev_buttons) else False

            # Détection du front montant avec debounce
            if is_pressed and not was_pressed:
                if self._is_debounce_elapsed(btn_index, now):
                    self._process_button(btn_index, now)

    def _is_debounce_elapsed(self, btn_index, now):
        """Vérifie si le délai de debounce est écoulé pour un bouton."""
        last_time = self.last_button_time.get(btn_index, 0)
        return (now - last_time) >= self.DEBOUNCE_DELAY

    def _process_button(self, btn_index, now):
        """Traite l'appui d'un bouton et publie la commande correspondante."""
        # Mapping bouton -> (publisher, message, direction_flip)
        button_actions = {
            self.BTN_TAKEOFF: (self.pub_takeoff, Empty(), None),
            self.BTN_LAND: (self.pub_land, Empty(), None),
            self.BTN_EMERGENCY: (self.pub_emergency, Empty(), None),
            self.BTN_FLIP_F: (self.pub_flip, String(), 'f'),
            self.BTN_FLIP_B: (self.pub_flip, String(), 'b'),
            self.BTN_FLIP_L: (self.pub_flip, String(), 'l'),
            self.BTN_FLIP_R: (self.pub_flip, String(), 'r'),
        }

        if btn_index not in button_actions:
            return

        publisher, message, flip_direction = button_actions[btn_index]

        if flip_direction:
            message.data = flip_direction

        publisher.publish(message)
        self.last_button_time[btn_index] = now

    def _handle_movement(self, axes):
        """Gère les axes du joystick pour le mouvement du drone."""
        # Conversion des axes joystick (-1 à 1) vers échelle drone (-100 à 100)
        twist = Twist()
        twist.linear.x = axes[self.AXIS_FB] * self.AXIS_SCALE
        twist.linear.y = axes[self.AXIS_LR] * self.AXIS_SCALE
        twist.linear.z = axes[self.AXIS_ALT] * self.AXIS_SCALE
        twist.angular.z = axes[self.AXIS_YAW] * self.AXIS_SCALE

        has_movement = any(
            abs(v) > self.DEADZONE_THRESHOLD
            for v in [twist.linear.x, twist.linear.y, twist.linear.z, twist.angular.z]
        )

        if has_movement:
            self.pub_control.publish(twist)
        else:
            self.pub_control.publish(Twist())


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
