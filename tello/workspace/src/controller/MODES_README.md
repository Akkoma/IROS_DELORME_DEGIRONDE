# Système de Modes du Drone Tello

## Architecture

Le système de contrôle du drone Tello a été amélioré avec un système de modes multiples:

```
[Joystick] → [manual_control] → [/control/*] → [tello_behaviour] → [Drone Tello]
                                                      ↑
                                              [Service /drone_mode]
```

### Noeuds ROS2

1. **manual_control**: Lit les commandes du joystick et les publie sur `/control/*`
2. **tello_behaviour**: Filtre les commandes selon le mode actif et les transmet au drone

## Modes Disponibles

Le drone possède 4 modes de fonctionnement:

| Mode | ID | Description |
|------|----|-----------| 
| **Manuel** | 0 | Bypass complet - toutes les commandes du joystick passent directement |
| **QR Follower** | 1 | Le drone suit un QR code - seuls emergency/takeoff/land autorisés manuellement |
| **Spielberg** | 2 | Mode cinématique avec mouvements fluides - seuls emergency/takeoff/land autorisés manuellement |
| **Surveillance** | 3 | Mode patrouille automatique - seuls emergency/takeoff/land autorisés manuellement |

## Compilation

Pour compiler le workspace avec le nouveau service:

```bash
cd /home/alix.degironde/Public/tello-ros2/workspace
colcon build --packages-select tello_msg controller
source install/setup.bash
```

## Utilisation

### 1. Lancer le noeud de contrôle manuel

```bash
ros2 run controller manual_control
```

### 2. Lancer le noeud de comportement (dans un autre terminal)

```bash
ros2 run controller tello_behaviour
```

### 3. Changer de mode via le service

#### Mode Manuel (par défaut)
```bash
ros2 service call /drone_mode tello_msg/srv/DroneMode "{mode: 0}"
```

#### Mode QR Follower
```bash
ros2 service call /drone_mode tello_msg/srv/DroneMode "{mode: 1}"
```

#### Mode Spielberg
```bash
ros2 service call /drone_mode tello_msg/srv/DroneMode "{mode: 2}"
```

#### Mode Surveillance
```bash
ros2 service call /drone_mode tello_msg/srv/DroneMode "{mode: 3}"
```

## Filtrage des Commandes

### Mode Manuel (0)
- ✅ Toutes les commandes passent (bypass complet)
- ✅ Contrôle total du joystick: mouvement 3D + yaw
- ✅ Takeoff, land, emergency, flip

### Modes Automatiques (1, 2, 3)
- ✅ **Autorisés**: Takeoff, Land, Emergency
- ❌ **Bloqués**: Flip, Mouvements du joystick (Twist)
- Le comportement automatique du mode prend le contrôle des mouvements

## Topics ROS2

### Topics du noeud manual_control → tello_behaviour
- `/control/takeoff` (Empty)
- `/control/land` (Empty)
- `/control/emergency` (Empty)
- `/control/flip` (String)
- `/control/cmd_vel` (Twist)

### Topics du noeud tello_behaviour → Drone
- `/takeoff` (Empty)
- `/land` (Empty)
- `/emergency` (Empty)
- `/flip` (String)
- `/control` (Twist)

## Service

### /drone_mode

**Type**: `tello_msg/srv/DroneMode`

**Request**:
- `mode` (int32): ID du mode (0-3)

**Response**:
- `success` (bool): True si le changement a réussi
- `message` (string): Message de confirmation ou d'erreur

**Exemple**:
```bash
ros2 service call /drone_mode tello_msg/srv/DroneMode "{mode: 1}"
```

## Développement Futur

Les méthodes suivantes sont à implémenter dans `tello_behaviour.py`:

1. **start_qr_follower_mode()**: 
   - Détection de QR codes avec OpenCV/pyzbar
   - Suivi et centrage sur le QR code
   - Maintien d'une distance fixe

2. **start_spielberg_mode()**:
   - Mouvements cinématiques fluides (travelling, panoramique)
   - Trajectoires préprogrammées
   - Lissage des commandes

3. **start_surveillance_mode()**:
   - Patrouille avec waypoints
   - Détection de mouvement
   - Rotation panoramique

## Fichiers Modifiés/Créés

- ✅ `workspace/src/tello_msg/srv/DroneMode.srv` (nouveau)
- ✅ `workspace/src/tello_msg/CMakeLists.txt` (modifié)
- ✅ `workspace/src/controller/controller/tello_behaviour.py` (nouveau)
- ✅ `workspace/src/controller/controller/manual_control.py` (modifié)
- ✅ `workspace/src/controller/setup.py` (modifié)

## Tests

Pour tester le système:

1. Vérifier que le service est disponible:
   ```bash
   ros2 service list | grep drone_mode
   ```

2. Vérifier le type du service:
   ```bash
   ros2 service type /drone_mode
   ```

3. Tester les changements de mode et observer les logs

4. Vérifier le filtrage en mode non-manuel (essayer de bouger les joysticks)


1) Ce que fait tello_behaviour.py (récapitulatif)
C'est un nœud ROS2 (classe TelloBehaviour hérite de rclpy.node.Node) nommé tello_behaviour.
Il contient une petite « énumération » locale DroneModes (MANUAL, QR_FOLLOWER, SPIELBERG, SURVEILLANCE) et une méthode utilitaire get_name.
Il expose un service /drone_mode de type tello_msg/srv/DroneMode pour changer le mode du drone.
Il s'abonne à un ensemble de topics « control » (provenant du contrôle manuel) :
/control/takeoff (Empty)
/control/land (Empty)
/control/emergency (Empty)
/control/flip (String)
/control/cmd_vel (Twist)
Il publie vers les topics « drone » (consommés par le pilote Tello) :
/takeoff (Empty)
/land (Empty)
/emergency (Empty)
/flip (String)
/control (Twist)
Logique de filtrage : en mode MANUAL toutes les commandes passent ; en modes filtrés (QR_FOLLOWER, SPIELBERG, SURVEILLANCE) seuls takeoff, land et emergency sont autorisés manuellement — les commandes de mouvement et flips sont bloquées puisque les modes automatiques doivent contrôler le drone eux-mêmes.
Les méthodes start_qr_follower_mode, start_spielberg_mode, start_surveillance_mode sont des squelettes (TODO) : elles loggent l'initialisation mais n'implémentent pas encore la logique de détection/suivi/trajectoire.
2) Contrat minimal (entrées / sorties)
Entrées (souscriptions) :
/control/takeoff : std_msgs/Empty
/control/land : std_msgs/Empty
/control/emergency : std_msgs/Empty
/control/flip : std_msgs/String
/control/cmd_vel : geometry_msgs/Twist
Service exposé :
/drone_mode : tello_msg/srv/DroneMode (request: int32 mode, response: bool success, string message)
Sorties (publications) :
/takeoff, /land, /emergency : std_msgs/Empty
/flip : std_msgs/String
/control : geometry_msgs/Twist
Modes d'erreur / succès :
Le service renvoie success True/False et un message explicatif.
3) Comment il communique avec les autres fichiers / nœuds / packages
Carte de communication (simplifiée, flux des messages) :

Joystick / manuel -> manual_control (node: manual_control)

manual_control lit le joystick (/joy) et publie :
/control/takeoff, /control/land, /control/emergency (Empty)
/control/flip (String)
/control/cmd_vel (Twist) — tous ces topics vont vers tello_behaviour (subscription).
Preuve : manual_control.py montre les publishers vers /control/....
Filtrage / logique de comportement -> tello_behaviour (node: tello_behaviour)

Reçoit /control/..., applique le filtre selon current_mode.
Si autorisé, republie sur les topics « drone » :
/takeoff, /land, /emergency, /flip, /control.
Expose /drone_mode pour changer le mode. Client d'exemple : test_drone_mode.py (node client qui appelle /drone_mode).
Pilote / driver -> tello (node: tello)

node.py (classe TelloNode) crée des subscriptions sur les topics que tello_behaviour publie :
self.sub_takeoff = create_subscription(Empty, 'takeoff', cb_takeoff, ...)
self.sub_land = create_subscription(Empty, 'land', cb_land, ...)
self.sub_emergency = create_subscription(Empty, 'emergency', cb_emergency, ...)
self.sub_control = create_subscription(Twist, 'control', cb_control, ...)
self.sub_flip = create_subscription(String, 'flip', cb_flip, ...)
Dans ces callbacks, le code appelle la bibliothèque djitellopy (ex: self.tello.takeoff(), self.tello.emergency(), self.tello.send_rc_control(...)).
Preuve : node.py (méthodes cb_takeoff, cb_emergency, cb_control, cb_flip).
Client/service pour changer le mode

tello_behaviour fournit le service /drone_mode (type tello_msg/srv/DroneMode). Exemple de client : test_drone_mode.py qui crée un client et appelle /drone_mode avec un champ mode (0..3).
Documentation / README

MODES_README.md décrit les modes, les topics /control/... attendus et les commandes ROS2 pour appeler le service /drone_mode.
Remarque sur les noms de topics avec ou sans slash initial :

tello_behaviour crée des publishers sur /takeoff, /land, etc. (chemins absolus commençant par '/').
node.py s'abonne à takeoff, land, etc. (noms relatifs).
En ROS2, si les deux nœuds sont dans la racine (namespace par défaut), /takeoff et takeoff finiront par référer au même topic; sinon un problème de namespace/remapping peut survenir. Vérifie le remapping ou les namespaces si tu as des comportements inattendus.
4) Fichiers/nœuds clés impliqués (localisés dans le workspace)
tello_behaviour.py — nœud de filtrage / service /drone_mode.
manual_control.py — nœud de contrôle manuel (joystick) ; publie sur /control/....
test_drone_mode.py — client de test pour appeler /drone_mode.
node.py — driver Tello qui exécute les commandes physiques via djitellopy.
DroneMode.srv — définition du service (request: int32 mode; response: bool success, string message).
MODES_README.md — doc décrivant les modes et topics.
(J’ai localisé ces fichiers dans le workspace et les extraits pertinents.)

5) Points importants / pièges à surveiller
Namespace / leading slash :
Si tello_behaviour publie sur /takeoff (absolu) et tello s'abonne à takeoff (relatif), tout ira bien si les deux sont en namespace racine. Mais si tu lances des nœuds sous des namespaces différents, il faudra remapper ou uniformiser les noms.
Ordre de démarrage :
Le client /drone_mode attend que le service apparaisse. test_drone_mode.py gère cela (wait_for_service).
Concurrence / délais :
tello_node utilise des threads pour vidéo/status/publishing. Les messages de contrôle doivent être envoyés à la cadence souhaitée (ici manual_control publie messages Twist).
Messages bloqués en mode filtré :
En modes automatiques, tello_behaviour bloque les commandes cmd_vel et flip venant du manuel. Assure-toi que les modules automatiques publient eux-mêmes sur /control si nécessaire (ou utilisent d'autres topics internes).
Implémentations manquantes :
start_qr_follower_mode, start_spielberg_mode, start_surveillance_mode sont des squelettes — il faut implémenter les subscriptions vers la caméra, la logique OpenCV/pyzbar, et la génération des commandes de mouvement (publish sur /control) pour que ces modes fonctionnent.
6) Tests et débogage rapides
Tester le changement de mode (existant) :
Lancer tello_behaviour, puis exécuter :
python3 [test_drone_mode.py](http://_vscodecontentref_/59) 1 (ou utiliser ros2 service call /drone_mode tello_msg/srv/DroneMode "{mode: 1}")
Simuler une commande manuel :
Publier sur /control/takeoff :
ros2 topic pub /control/takeoff std_msgs/msg/Empty '{}' — si le mode autorise, tello_behaviour republiera sur /takeoff et le driver tello exécutera takeoff.
Vérifier les topics existants :
ros2 topic list et ros2 service list pendant l'exécution pour s'assurer que /drone_mode, /takeoff, /control, etc. existent.
Vérifier que le driver reçoit bien :
ros2 topic echo /status ou autre message publié par tello pour valider la communication.
7) Suggestions / next steps pratiques
Implémenter un petit test automatisé (ros2 node + publisher) pour valider le filtrage : publier cmd_vel et vérifier s’il est relayé ou pas selon le mode.
Compléter start_qr_follower_mode :
Souscrire à image_raw publié par node.py.
Utiliser cv_bridge + OpenCV/pyzbar pour détecter un QR.
Publier des corrections sur /control (Twist).
Uniformiser les noms de topics (recommander) : utiliser des noms sans slash ou configurer les namespaces pour éviter des confusions.
Ajouter des logs plus détaillés (niveau debug) pour tracer quand tello_behaviour bloque ou repasse des commandes (utile pour debug).
8) Résumé rapide
tello_behaviour.py est le nœud filtre entre le contrôle manuel (manual_control) et le pilote Tello (node.py).
Il expose /drone_mode pour changer le comportement (test possible via test_drone_mode.py).
En MANUAL, tout passe ; en modes automatiques, seules les commandes critiques (takeoff/land/emergency) sont relayées.
Pour que les modes automatiques fonctionnent, il faut implémenter les méthodes TODO (détection QR, trajectoires, etc.) et s'assurer que ces modules publient les commandes de mouvement sur /control.
Si tu veux, je peux :

Générer un petit script de test qui automatise la validation du filtrage (publie cmd_vel, observe si relayé selon le mode).
Implémenter un prototype minimal du mode QR Follower (abonnement à image_raw, détection d’un QR statique et publication d’un Twist de correction).
Uniformiser les noms de topics (retirer/ajouter slash) et t'expliquer comment remapper si tu veux garder les noms actuels.
