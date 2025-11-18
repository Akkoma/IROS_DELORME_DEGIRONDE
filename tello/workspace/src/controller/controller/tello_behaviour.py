#!/home/alix.degironde/Public/ven_IROS/bin python3

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from std_msgs.msg import Empty, String, Int32
from geometry_msgs.msg import Twist
from tello_msg.srv import DroneMode
from tello_msg.action import Spielberg


class DroneModes:
    """Énumération des modes du drone"""
    MANUAL = 0
    QR_FOLLOWER = 1
    SPIELBERG = 2
    SURVEILLANCE = 3
    
    @staticmethod
    def get_name(mode):
        names = {
            DroneModes.MANUAL: "Manuel",
            DroneModes.QR_FOLLOWER: "QR Code Follower",
            DroneModes.SPIELBERG: "Spielberg",
            DroneModes.SURVEILLANCE: "Surveillance"
        }
        return names.get(mode, "Inconnu")


class TelloBehaviour(Node):
    """
    Noeud de filtrage des commandes du drone selon le mode actif.
    
    Modes:
    - Manuel (0): Bypass complet, toutes les commandes passent
    - QR Follower (1): Filtre actif, seuls emergency/takeoff/land passent
    - Spielberg (2): Filtre actif, seuls emergency/takeoff/land passent
    - Surveillance (3): Filtre actif, seuls emergency/takeoff/land passent
    """
    
    def __init__(self):
        super().__init__('tello_behaviour')
        
        # Mode actuel du drone
        self.current_mode = DroneModes.MANUAL
        ### AJOUT PAO
        # Publisher léger pour informer d'autres noeuds de l'état du mode
        self.mode_pub = self.create_publisher(Int32, '/drone_mode/state', 10)
        
        # --- Service pour changer de mode ---
        self.mode_service = self.create_service(
            DroneMode,
            '/drone_mode',
            self.handle_mode_change
        )
        
        self._action_client = ActionClient(self, Spielberg, 'spielberg')

        # --- Subscribers (depuis le noeud control/manual_control) ---
        self.sub_takeoff = self.create_subscription(
            Empty, '/control/takeoff', self.callback_takeoff, 10
        )
        self.sub_land = self.create_subscription(
            Empty, '/control/land', self.callback_land, 10
        )
        self.sub_emergency = self.create_subscription(
            Empty, '/control/emergency', self.callback_emergency, 10
        )
        self.sub_flip = self.create_subscription(
            String, '/control/flip', self.callback_flip, 10
        )
        self.sub_control = self.create_subscription(
            Twist, '/control/cmd_vel', self.callback_control, 10
        )
        
        # --- Subscriber pour les commandes du mode surveillance ---
        self.sub_surveillance = self.create_subscription(
            Twist, '/surveillance/cmd_vel', self.callback_surveillance_control, 10
        )
        
        # --- Publishers (vers le drone Tello) ---
        self.pub_takeoff = self.create_publisher(Empty, '/takeoff', 10)
        self.pub_land = self.create_publisher(Empty, '/land', 10)
        self.pub_emergency = self.create_publisher(Empty, '/emergency', 10)
        self.pub_flip = self.create_publisher(String, '/flip', 10)
        self.pub_control = self.create_publisher(Twist, '/control', 10)
        
        self.get_logger().info(
            f"Noeud tello_behaviour initialisé en mode: {DroneModes.get_name(self.current_mode)}"
        )
        self.get_logger().info("Service '/drone_mode' disponible pour changer de mode")
    
    def handle_mode_change(self, request, response):
        """
        Gère les demandes de changement de mode via le service drone_mode
        
        Args:
            request: DroneMode.Request avec le champ 'mode' (int)
            response: DroneMode.Response avec 'success' (bool) et 'message' (string)
        """
        requested_mode = request.mode
        
        # Vérifier que le mode est valide
        if requested_mode not in [DroneModes.MANUAL, DroneModes.QR_FOLLOWER, 
                                   DroneModes.SPIELBERG, DroneModes.SURVEILLANCE]:
            response.success = False
            response.message = f"Mode invalide: {requested_mode}. Modes valides: 0-3"
            self.get_logger().error(response.message)
            return response
        
        # Changer le mode
        old_mode = self.current_mode
        self.current_mode = requested_mode
        
        response.success = True
        response.message = (
            f"Mode changé: {DroneModes.get_name(old_mode)} -> "
            f"{DroneModes.get_name(self.current_mode)}"
        )
        
        self.get_logger().info(f"{response.message}")
        
        # Logique spécifique selon le mode
        if self.current_mode == DroneModes.MANUAL:
            self.get_logger().info("Mode MANUEL: Bypass actif, toutes commandes autorisées")
        elif self.current_mode == DroneModes.QR_FOLLOWER:
            self.get_logger().info("Mode QR FOLLOWER: Filtre actif, suivi de QR code activé")
            self.start_qr_follower_mode()
        elif self.current_mode == DroneModes.SPIELBERG:
            self.get_logger().info("Mode SPIELBERG: Filtre actif, mode cinématique activé")
            self.start_spielberg_mode()
        elif self.current_mode == DroneModes.SURVEILLANCE:
            self.get_logger().info("Mode SURVEILLANCE: Filtre actif, surveillance activée")
            self.start_surveillance_mode()

        # Publier l'état du mode pour les autres noeuds (ex: surveillance)
        try:
            if not self.current_mode == DroneModes.SPIELBERG:
                mode_msg = Int32()
                mode_msg.data = int(self.current_mode)
                self.mode_pub.publish(mode_msg)
        except Exception:
            # Ne doit pas bloquer la réponse du service
            self.get_logger().debug("Impossible de publier l'état du mode")
        
        return response
    
    def is_manual_mode(self):
        """Retourne True si le mode actuel est Manuel"""
        return self.current_mode == DroneModes.MANUAL
    
    def is_command_allowed_in_filtered_mode(self, command_type):
        """
        Vérifie si une commande est autorisée en mode filtré.
        
        En mode non-manuel, seuls emergency, takeoff et land sont autorisés.
        """
        allowed_commands = ['emergency', 'takeoff', 'land']
        return command_type in allowed_commands
    
    # ========== CALLBACKS POUR LES COMMANDES ==========
    
    def callback_takeoff(self, msg):
        """Callback pour la commande de décollage"""
        if self.is_manual_mode() or self.is_command_allowed_in_filtered_mode('takeoff'):
            self.get_logger().info("Décollage autorisé")
            self.pub_takeoff.publish(msg)
        else:
            self.get_logger().warn(
                f"Décollage bloqué en mode {DroneModes.get_name(self.current_mode)}"
            )
    
    def callback_land(self, msg):
        """Callback pour la commande d'atterrissage"""
        if self.is_manual_mode() or self.is_command_allowed_in_filtered_mode('land'):
            self.get_logger().info("Atterrissage autorisé")
            self.pub_land.publish(msg)
        else:
            self.get_logger().warn(
                f"Atterrissage bloqué en mode {DroneModes.get_name(self.current_mode)}"
            )
    
    def callback_emergency(self, msg):
        """Callback pour l'arrêt d'urgence"""
        if self.is_manual_mode() or self.is_command_allowed_in_filtered_mode('emergency'):
            self.get_logger().warn("ARRÊT D'URGENCE autorisé")
            self.pub_emergency.publish(msg)
        else:
            # L'urgence devrait toujours passer, mais on garde la logique cohérente
            self.get_logger().warn(
                f"Arrêt d'urgence bloqué en mode {DroneModes.get_name(self.current_mode)}"
            )
    
    def callback_flip(self, msg):
        """Callback pour la commande de flip"""
        if self.is_manual_mode():
            self.get_logger().info(f"Flip autorisé (direction: {msg.data})")
            self.pub_flip.publish(msg)
        else:
            self.get_logger().warn(
                f"Flip bloqué en mode {DroneModes.get_name(self.current_mode)}"
            )
    
    def callback_control(self, msg):
        """Callback pour les commandes de mouvement (Twist)"""
        if self.is_manual_mode():
            # En mode manuel, on laisse tout passer
            self.pub_control.publish(msg)
        else:
            # En mode filtré, on bloque les commandes de mouvement du joystick
            # (les modes automatiques gèrent leur propre mouvement)
            pass
    
    def callback_surveillance_control(self, msg):
        """Callback pour les commandes de mouvement du mode surveillance"""
        if self.current_mode == DroneModes.SURVEILLANCE:
            # En mode surveillance, on publie les commandes vers le drone
            self.pub_control.publish(msg)
        else:
            # Si on n'est pas en mode surveillance, on ignore les commandes
            pass
    
    # ========== MÉTHODES POUR LES MODES SPÉCIFIQUES ==========
    
    def start_qr_follower_mode(self):
        """
        Initialise le mode QR Code Follower.
        
        Dans ce mode, le drone doit:
        - Détecter et suivre un QR code
        - Maintenir une distance fixe
        - Se centrer sur le QR code
        """
        self.get_logger().info("Initialisation du mode QR Follower...")
        # TODO: Ajouter la logique de détection et suivi de QR code
        # - Subscription au topic de la caméra
        # - Détection de QR codes avec OpenCV/pyzbar
        # - Calcul de la position relative
        # - Envoi de commandes de correction via self.pub_control
        self.get_logger().info("Mode QR Follower: Implémentation à compléter")
    
    def send_goal(self):
        """Envoie le goal à l'action server Spielberg"""
        goal_msg = Spielberg.Goal()
        goal_msg.flag = True

        self._action_client.wait_for_server()
        
        # Envoyer le goal de manière asynchrone
        future = self._action_client.send_goal_async(goal_msg)
        future.add_done_callback(self.goal_response_callback)
    
    def goal_response_callback(self, future):
        """Callback quand le goal est accepté ou rejeté"""
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().error('Goal Spielberg rejeté')
            return
        
        self.get_logger().info('Goal Spielberg accepté')
        
        # Attendre le résultat
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.get_result_callback)
    
    def get_result_callback(self, future):
        """Callback quand l'action est terminée"""
        result = future.result().result
        if result.success:
            self.get_logger().info('Séquence Spielberg terminée avec succès')
        else:
            self.get_logger().warn('Séquence Spielberg échouée')

    def start_spielberg_mode(self):
        """
        Initialise le mode Spielberg (cinématique).
        
        Dans ce mode, le drone doit:
        - Effectuer des mouvements cinématiques fluides
        - Suivre des trajectoires prédéfinies ou contrôlées
        - Maintenir une stabilité optimale pour la prise de vue
        """
        self.get_logger().info("Initialisation du mode Spielberg...")
        self.send_goal()

    
    def start_surveillance_mode(self):
        """
        Initialise le mode Surveillance.
        
        Dans ce mode, le drone doit:
        - Patrouiller selon un schéma défini
        - Détecter les mouvements suspects
        - Enregistrer ou transmettre les images
        """
        self.get_logger().info("Initialisation du mode Surveillance...")
        # TODO: Ajouter la logique de surveillance
        # - Définition de waypoints pour la patrouille
        # - Détection de mouvement dans l'image
        # - Rotation panoramique pour scanner l'environnement
        self.get_logger().info("Mode Surveillance: Implémentation à compléter")
        


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
