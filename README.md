# IROS_DELORME_DEGIRONDE


❓ Question 1 ❓
Après lecture de cet extrait, répondez aux questions suivantes :
Quelles sont les quatre commandes classiques d’un drone quadrirotor ?
A l’aide de schémas et de repères que vous aurez fixés, expliquez comment
peut-on contrôler la trajectoire d’un drone quadricoptère.



❓ Question : ❓
L'organisation du dossier cloné ne semble pas correspondre à ce que les standards ROS2 imposent.. A moins que ?
Appelez le professeur si besoin 😃

La bonne pratique veut qu'on clone uniquement un package dans le /src de notre workspace. Or dans ce cas le clone du git associé contiens tout un projet, avac notamment un workspace. Nous allons donc directement travailler dans le workspace fourni `workspace`



❓ Question 2 : ❓

Quels topics correspondent à la commande du drone ?
Quel est respectivement le type de chacun des messages associés ?

`ros2 topic list`
/control
/emergency
/flip
/land
/parameter_events
/rosout
/takeoff


mise en route du drone : 

📉 Affichage de l'altitude mesuré : topic /status distance_tof, 

Quesiton
Vous remarquerez que le topic sortant de manual_control a changé. Comment aller procéder pour faire cela ? Quel est l'interet ? Pourquoi effectuer le changement en sorti de joy est interessant plutot qu'autre part ?





## Explication du nœud `tello_behaviour` et ses communications

Ce document décrit le rôle de `tello_behaviour.py`, les topics et services utilisés, et comment ce fichier communique avec les autres nœuds/packages du projet.

### Vue d'ensemble

- Fichier principal analysé : `workspace/src/controller/controller/tello_behaviour.py`
- Objet : nœud ROS2 qui filtre et relaie les commandes manuelles vers le pilote du drone (Tello). Il expose aussi un service pour changer le mode de comportement du drone.

### Contrat (entrées / sorties)

- Entrées (subscriptions) :
	- `/control/takeoff` : `std_msgs/Empty`
	- `/control/land` : `std_msgs/Empty`
	- `/control/emergency` : `std_msgs/Empty`
	- `/control/flip` : `std_msgs/String`
	- `/control/cmd_vel` : `geometry_msgs/Twist`

- Service exposé :
	- `/drone_mode` : `tello_msg/srv/DroneMode` (request `int32 mode`, response `bool success`, `string message`)
## IROS_DELORME_DEGIRONDE

## Vue d'ensemble
Ce dépôt contient un projet ROS2 pour piloter un drone Tello via une architecture en packages. Le projet sépare le driver matériel, le contrôle manuel et la logique de comportement (modes automatiques / filtrage).

Résumé rapide :
- Packages (sous `src`) : regroupent code ROS (nodes, messages, services, CMake/setup).
- Nœuds : programmes Python/C++ qui publient/s’abonnent à des topics ou exposent des services.
- Topics : canaux nommés pour l’échange de messages (std_msgs, geometry_msgs, ou custom).

---

## Arborescence logique (packages clés)
- `controller` (workspace/src/controller) — logique de contrôle manuel et modes (filtrage).
- `tello` (workspace/src/tello) — driver/communication avec la librairie djitellopy et le drone.
- `tello_control` (workspace/src/tello_control) — alternative de contrôle (C++ clavier/OpenCV).
- `tello_msg` (workspace/src/tello_msg) — messages/services custom (msg/ et srv/).

---

## Package `controller`
But : centraliser la logique manuelle et les comportements automatiques, filtrer et router les commandes vers le pilote.

Fichiers/nœuds principaux :
- `manual_control.py` — nœud `manual_control`
	- Souscriptions : `/joy` (sensor_msgs/Joy), `/status` (tello_msg/TelloStatus)
	- Publications (vers `tello_behaviour`) :
		- `/control/takeoff` : std_msgs/Empty
		- `/control/land` : std_msgs/Empty
		- `/control/emergency` : std_msgs/Empty
		- `/control/flip` : std_msgs/String
		- `/control/cmd_vel` : geometry_msgs/Twist
	- Rôle : lire le joystick et convertir en commandes (axes → Twist, boutons → actions).

- `tello_behaviour.py` — nœud `tello_behaviour`
	- Service exposé :
		- `/drone_mode` : `tello_msg/srv/DroneMode` (request: int32 mode → response: bool success, string message)
	- Souscriptions :
		- `/control/takeoff` : std_msgs/Empty
		- `/control/land` : std_msgs/Empty
		- `/control/emergency` : std_msgs/Empty
		- `/control/flip` : std_msgs/String
		- `/control/cmd_vel` : geometry_msgs/Twist
	- Publications (vers le pilote) :
		- `/takeoff`, `/land`, `/emergency` : std_msgs/Empty
		- `/flip` : std_msgs/String
		- `/control` : geometry_msgs/Twist
	- Logique : maintien d’un `current_mode` (MANUAL, QR_FOLLOWER, SPIELBERG, SURVEILLANCE).
		- En mode MANUAL : relais complet des commandes reçues.
		- En modes automatiques : seules les commandes critiques (takeoff/land/emergency) sont autorisées ; commandes de mouvement et flip sont bloquées (automates contrôlent le drone).
		- Remarque : les méthodes `start_qr_follower_mode`, `start_spielberg_mode`, `start_surveillance_mode` sont des squelettes à implémenter.

- `test_drone_mode.py` — client de test : crée un client ROS2 pour `/drone_mode` et appelle le service pour basculer de mode.

---

## Package `tello`
But : driver et interface avec `djitellopy` (ou équivalent) pour contrôler le drone et publier ses capteurs/vidéo.

Fichiers/nœud principal :
- `node.py` — `TelloNode` (rclpy)
	- Publications :
		- `image_raw` : sensor_msgs/Image
		- `camera_info` : sensor_msgs/CameraInfo
		- `status` : tello_msg/TelloStatus
		- `id` : tello_msg/TelloID
		- `imu` : sensor_msgs/Imu
		- `battery` : sensor_msgs/BatteryState
		- `temperature` : sensor_msgs/Temperature
		- `odom` : nav_msgs/Odometry
	- Souscriptions (commandes) :
		- `takeoff` : std_msgs/Empty → self.tello.takeoff()
		- `land` : std_msgs/Empty → self.tello.land()
		- `emergency` : std_msgs/Empty → self.tello.emergency()
		- `control` : geometry_msgs/Twist → self.tello.send_rc_control(...)
		- `flip` : std_msgs/String → self.tello.flip(...)
		- `wifi_config` : tello_msg/TelloWifiConfig → config Wi‑Fi
	- Rôle : gérer la connexion, publier capteurs/vidéo, exécuter commandes.

Remarque : les modes automatiques (ex. QR follower) doivent s’abonner à `image_raw` pour réaliser la détection vision et publier des Twist de correction sur `/control`.

---

## Package `tello_control`
But : contrôle via clavier (C++), interface alternative à `manual_control`.

- `main.cpp` — node `TelloControl`
	- Publications : `takeoff`, `land`, `emergency`, `flip`, `control` (geometry_msgs::msg::Twist)
	- Remarque sur les noms : certains nœuds utilisent des noms relatifs (ex : `takeoff`) et d’autres des chemins absolus (`/takeoff`). Harmoniser ou utiliser des remaps dans les launch files.

---

## Package `tello_msg`
But : définir messages et services custom.

Contenu :
- `msg/` : `TelloStatus.msg`, `TelloID.msg`, `TelloWifiConfig.msg`
- `srv/` : `DroneMode.srv` (int32 mode → bool success, string message)

---

## Flux de communication simplifié
Joystick → `manual_control` publie `/control/*` → `tello_behaviour` filtre → publie `/takeoff`, `/control`, etc. → `tello` (driver) exécute les commandes.

Alternative : `tello_control` publie directement les topics consommés par `tello`.

---

## Topics & types (extraits utiles)
Topics observés :
- `/control` (geometry_msgs/Twist)
- `/emergency` (std_msgs/Empty)
- `/flip` (std_msgs/String)
- `/land` (std_msgs/Empty)
- `/takeoff` (std_msgs/Empty)
- `/status` (tello_msg/TelloStatus) — contient altitude `distance_tof`
- `/image_raw` (sensor_msgs/Image)

Exemples utiles :
```bash
ros2 topic list
```

Publier un décollage simulé :
```bash
ros2 topic pub /control/takeoff std_msgs/msg/Empty '{}' --once
```

Appeler le service de changement de mode :
```bash
ros2 service call /drone_mode tello_msg/srv/DroneMode "{mode: 1}"
```

---

## Remarques pratiques et pièges courants
- Slash initial dans les noms : `/takeoff` (absolu) vs `takeoff` (relatif). Préférence : noms relatifs + remaps, ou convention documentée.
- Redondance des sources de commandes : `tello_behaviour` centralise l’arbitrage.
- Ordre de démarrage : attendre que `/drone_mode` soit exposé (`wait_for_service`).
- Concurrence : le driver peut utiliser des threads (vidéo/status). Assurer thread-safety.
- Implémentations manquantes : modes automatiques à implémenter (vision → Twist → /control).

---

## Recommandations rapides
- Harmoniser les noms de topics (éviter mélange absolu/relatif).
- Ajouter des logs DEBUG dans `tello_behaviour` pour tracer les messages bloqués/relaisés.
- Écrire un test automatisé simple : lancer `tello_behaviour`, publier un `Twist` sur `/control/cmd_vel` et vérifier la publication sur `/control` en mode MANUAL.

---

## Tests et vérifications rapides
- Lister topics :
```bash
ros2 topic list
```
- Echo d’un topic :
```bash
ros2 topic echo /status
```
- Tester service `/drone_mode` :
```bash
ros2 service call /drone_mode tello_msg/srv/DroneMode "{mode: 0}"
```

---

## Suggestions / prochaines étapes (valeur ajoutée)
1. Implémenter un prototype minimal pour `start_qr_follower_mode` : s’abonner à `image_raw`, détecter un QR (OpenCV/pyzbar), publier un `Twist` de correction sur `/control`.
2. Ajouter des tests unitaires/ROS2 integration tests (happy path + 1-2 edge cases).
3. Fournir un `launch` file qui remappe proprement les topics et répare les conventions de noms.
4. (Optionnel) Ajouter un diagramme (PNG/SVG) dans `screenshots/` montrant le flux topics/services.

---

## Annexes — Contrat minimal (pour `tello_behaviour`)
- Inputs : `/control/*` (takeoff/land/emergency/flip/cmd_vel), service `/drone_mode`.
- Outputs : `/takeoff`, `/land`, `/emergency`, `/flip`, `/control`.
- Modes : MANUAL (tout relayé), modes automatiques (seulement takeoff/land/emergency autorisés manuellement).
- Success criteria : en MANUAL, une publication sur `/control/cmd_vel` → message publié sur `/control`. En mode auto, ce même message doit être bloqué.

Edge cases :
- Absence du driver `tello` (messages publiés mais personne pour consommer).
- Remapping / namespaces différents (topics absolus vs relatifs).
- Joystick défectueux / messages erronés (sanity-checks sur Twist).
- Délai / latence de la vidéo pour les modes vision.

---

## Fichiers clés à consulter
- `workspace/src/controller/controller/tello_behaviour.py`
- `workspace/src/controller/controller/manual_control.py`
- `workspace/src/tello/tello/node.py`
- `workspace/src/tello_msg/srv/DroneMode.srv`
- `workspace/src/controller/MODES_README.md`

---

Fin — résumé
La documentation a été reformattée et clarifiée. Si tu veux que j’applique d’autres modifications (diagramme, tests, launch files), dis‑le et je m’en occupe.
