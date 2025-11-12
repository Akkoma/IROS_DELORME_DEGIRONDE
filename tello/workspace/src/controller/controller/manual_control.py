#!/home/alix.degironde/Public/ven_IROS/bin python3
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import rclpy
from rclpy.node import Node

from tutorial_interfaces.msg import Num                        # CHANGE

#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy

class ManualControl(Node):
    def __init__(self):
        super().__init__('manual_control')
        self.subscription = self.create_subscription(
            Joy,
            '/joy',
            self.joy_callback,
            10)
        self.subscription  # prevent unused variable warning

        # Exemple de mapping des boutons (à adapter selon ton joystick)
        self.BTN_TAKEOFF = 9       # décollage
        self.BTN_LAND = 7          # atterrissage
        self.BTN_EMERGENCY = 8     # arrêt d’urgence
        self.BTN_FLIP = 4          # optionnel

        # Joysticks pour les déplacements
        self.AXIS_LR = 0           # gauche/droite (axe horizontal du stick gauche)
        self.AXIS_FB = 1           # avant/arrière (axe vertical du stick gauche)
        self.AXIS_YAW = 3          # rotation (stick droit horizontal)
        self.AXIS_ALT = 4          # montée/descente (stick droit vertical)

        self.get_logger().info('🕹️  Manual Control node started — waiting for joystick input...')

    def joy_callback(self, msg: Joy):
        buttons = msg.buttons
        axes = msg.axes

        # === Boutons ===
        if buttons[self.BTN_TAKEOFF]:
            self.get_logger().info("🚁 Décollage demandé")
            # Ici tu pourrais publier une commande de décollage

        if buttons[self.BTN_LAND]:
            self.get_logger().info("🛬 Atterrissage demandé")
            # Ici tu pourrais publier une commande d'atterrissage

        if buttons[self.BTN_EMERGENCY]:
            self.get_logger().warn("⛔ Arrêt d’urgence demandé !")
            # Ici tu pourrais publier un arrêt d’urgence

        if self.BTN_FLIP < len(buttons) and buttons[self.BTN_FLIP]:
            self.get_logger().info("🤸 Flip demandé (optionnel)")

        # === Déplacements ===
        lr = axes[self.AXIS_LR]     # gauche/droite
        fb = axes[self.AXIS_FB]     # avant/arrière
        yaw = axes[self.AXIS_YAW]   # rotation
        alt = axes[self.AXIS_ALT]   # altitude

        # On affiche seulement si il y a un mouvement significatif
        if abs(lr) > 0.2 or abs(fb) > 0.2 or abs(yaw) > 0.2 or abs(alt) > 0.2:
            self.get_logger().info(
                f"Déplacement -> LR: {lr:.2f}, FB: {fb:.2f}, Yaw: {yaw:.2f}, Alt: {alt:.2f}"
            )

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

class MinimalSubscriber(Node):

    def __init__(self):
        super().__init__('minimal_subscriber')
        self.subscription = self.create_subscription(
            Num,                                               # CHANGE
            'topic',
            self.listener_callback,
            10)
        self.subscription

    def listener_callback(self, msg):
        self.get_logger().info('I heard: "%d"' % msg.num)  # CHANGE