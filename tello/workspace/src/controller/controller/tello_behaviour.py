#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from std_msgs.msg import Empty, String, Int32
from geometry_msgs.msg import Twist
from tello_msg.srv import DroneMode, Surveillance as SurveillanceSrv
from tello_msg.action import Spielberg


class DroneModes:
    """Énumération des modes disponibles pour le drone."""
    MANUAL = 0
    QR_FOLLOWER = 1
    SPIELBERG = 2
    SURVEILLANCE = 3

    NAMES = {
        MANUAL: "Manuel",
        QR_FOLLOWER: "QR Code Follower",
        SPIELBERG: "Spielberg",
        SURVEILLANCE: "Surveillance"
    }

    @classmethod
    def get_name(cls, mode):
        return cls.NAMES.get(mode, "Inconnu")

    @classmethod
    def is_valid(cls, mode):
        return mode in cls.NAMES


class TelloBehaviour(Node):
    """
    Noeud de filtrage des commandes du drone selon le mode actif.
    
    En mode Manuel : toutes les commandes passent.
    En mode filtré (QR Follower, Spielberg, Surveillance) : seuls
    emergency, takeoff et land sont autorisés depuis le joystick.
    """

    ALLOWED_COMMANDS_FILTERED = {'emergency', 'takeoff', 'land'}

    def __init__(self):
        super().__init__('tello_behaviour')

        self.current_mode = DroneModes.MANUAL
        self._spielberg_goal_handle = None

        # Publisher pour diffuser l'état du mode
        self.mode_pub = self.create_publisher(Int32, '/drone_mode/state', 10)

        # Service de changement de mode
        self.mode_service = self.create_service(DroneMode, '/drone_mode', self.handle_mode_change)

        # Clients
        self._spielberg_action_client = ActionClient(self, Spielberg, 'spielberg')
        self.surveillance_client = self.create_client(SurveillanceSrv, '/surveillance/control')

        # Subscribers depuis manual_control
        self.sub_takeoff = self.create_subscription(Empty, '/control/takeoff', self.callback_takeoff, 10)
        self.sub_land = self.create_subscription(Empty, '/control/land', self.callback_land, 10)
        self.sub_emergency = self.create_subscription(Empty, '/control/emergency', self.callback_emergency, 10)
        self.sub_flip = self.create_subscription(String, '/control/flip', self.callback_flip, 10)
        self.sub_control = self.create_subscription(Twist, '/control/cmd_vel', self.callback_control, 10)
        self.sub_surveillance = self.create_subscription(Twist, '/surveillance/cmd_vel', self.callback_surveillance_control, 10)

        # Publishers vers le drone Tello
        self.pub_takeoff = self.create_publisher(Empty, '/takeoff', 10)
        self.pub_land = self.create_publisher(Empty, '/land', 10)
        self.pub_emergency = self.create_publisher(Empty, '/emergency', 10)
        self.pub_flip = self.create_publisher(String, '/flip', 10)
        self.pub_control = self.create_publisher(Twist, '/control', 10)

        self.get_logger().info(f"TelloBehaviour initialisé en mode: {DroneModes.get_name(self.current_mode)}")
    
    def handle_mode_change(self, request, response):
        """Gère les demandes de changement de mode via le service drone_mode."""
        requested_mode = request.mode

        if not DroneModes.is_valid(requested_mode):
            response.success = False
            response.message = f"Mode invalide: {requested_mode}. Modes valides: 0-3"
            self.get_logger().error(response.message)
            return response

        old_mode = self.current_mode

        # Arrêter le mode précédent si nécessaire
        if old_mode == DroneModes.SURVEILLANCE and requested_mode != DroneModes.SURVEILLANCE:
            self._stop_surveillance_mode()
        if old_mode == DroneModes.SPIELBERG and requested_mode != DroneModes.SPIELBERG:
            self._stop_spielberg_mode()

        self.current_mode = requested_mode
        response.success = True
        response.message = f"Mode: {DroneModes.get_name(old_mode)} -> {DroneModes.get_name(self.current_mode)}"

        # Démarrer le nouveau mode
        if self.current_mode == DroneModes.QR_FOLLOWER:
            self._start_qr_follower_mode()
        elif self.current_mode == DroneModes.SPIELBERG:
            self._start_spielberg_mode()
        elif self.current_mode == DroneModes.SURVEILLANCE:
            self._start_surveillance_mode()

        # Publier l'état du mode (sauf Spielberg qui gère son propre état)
        if self.current_mode != DroneModes.SPIELBERG:
            mode_msg = Int32()
            mode_msg.data = self.current_mode
            self.mode_pub.publish(mode_msg)

        return response

    def _is_manual_mode(self):
        return self.current_mode == DroneModes.MANUAL

    def _is_command_allowed(self, command_type):
        """Vérifie si une commande est autorisée dans le mode actuel."""
        return self._is_manual_mode() or command_type in self.ALLOWED_COMMANDS_FILTERED
    
    # ========== CALLBACKS DES COMMANDES ==========

    def callback_takeoff(self, msg):
        if self._is_command_allowed('takeoff'):
            self.pub_takeoff.publish(msg)

    def callback_land(self, msg):
        if self._is_command_allowed('land'):
            self.pub_land.publish(msg)

    def callback_emergency(self, msg):
        if self._is_command_allowed('emergency'):
            self.pub_emergency.publish(msg)

    def callback_flip(self, msg):
        if self._is_manual_mode():
            self.pub_flip.publish(msg)

    def callback_control(self, msg):
        if self._is_manual_mode():
            self.pub_control.publish(msg)

    def callback_surveillance_control(self, msg):
        if self.current_mode == DroneModes.SURVEILLANCE:
            self.pub_control.publish(msg)
    
    # ========== GESTION DES MODES SPÉCIFIQUES ==========

    def _start_qr_follower_mode(self):
        """Initialise le mode QR Code Follower."""
        pass

    def _start_spielberg_mode(self):
        """Lance la séquence cinématique Spielberg via l'action server."""
        if not self._spielberg_action_client.wait_for_server(timeout_sec=2.0):
            self.get_logger().error("Action server Spielberg non disponible")
            return

        goal_msg = Spielberg.Goal()
        goal_msg.start = True

        send_goal_future = self._spielberg_action_client.send_goal_async(
            goal_msg, feedback_callback=self._spielberg_feedback_callback
        )
        send_goal_future.add_done_callback(self._spielberg_goal_response_callback)

    def _spielberg_goal_response_callback(self, future):
        """Callback pour la réponse d'acceptation du goal Spielberg."""
        goal_handle = future.result()
        if not goal_handle.accepted:
            self._spielberg_goal_handle = None
            return

        self._spielberg_goal_handle = goal_handle
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self._spielberg_result_callback)

    def _spielberg_feedback_callback(self, feedback_msg):
        """Callback pour les feedbacks de l'action Spielberg."""
        pass

    def _spielberg_result_callback(self, future):
        """Callback pour le résultat de l'action Spielberg."""
        self._spielberg_goal_handle = None

    def _stop_spielberg_mode(self):
        """Annule la séquence Spielberg en cours."""
        if self._spielberg_goal_handle is not None:
            try:
                cancel_future = self._spielberg_goal_handle.cancel_goal_async()
                cancel_future.add_done_callback(self._spielberg_cancel_callback)
            except Exception as e:
                self.get_logger().error(f"Erreur annulation Spielberg: {e}")
                self._spielberg_goal_handle = None

    def _spielberg_cancel_callback(self, future):
        """Callback pour l'annulation de l'action Spielberg."""
        self._spielberg_goal_handle = None

    def _start_surveillance_mode(self):
        """Active le mode surveillance via le service."""
        if not self.surveillance_client.wait_for_service(timeout_sec=2.0):
            self.get_logger().error("Service /surveillance/control non disponible")
            return

        request = SurveillanceSrv.Request()
        request.data = True
        future = self.surveillance_client.call_async(request)
        future.add_done_callback(self._surveillance_response_callback)

    def _stop_surveillance_mode(self):
        """Désactive le mode surveillance via le service."""
        if not self.surveillance_client.service_is_ready():
            return

        request = SurveillanceSrv.Request()
        request.data = False
        future = self.surveillance_client.call_async(request)
        future.add_done_callback(self._surveillance_response_callback)

    def _surveillance_response_callback(self, future):
        """Callback pour la réponse du service surveillance."""
        try:
            response = future.result()
            if not response.success:
                self.get_logger().warn("Commande surveillance échouée")
        except Exception as e:
            self.get_logger().error(f"Erreur service surveillance: {e}")


def main(args=None):
    rclpy.init(args=args)
    node = TelloBehaviour()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
