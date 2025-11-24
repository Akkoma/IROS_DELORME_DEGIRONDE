# IROS_DELORME_DEGIRONDE

## Question 1

Après lecture de cet extrait, répondez aux questions suivantes :
Quelles sont les quatre commandes classiques d’un drone quadrirotor ?
A l’aide de schémas et de repères que vous aurez fixés, expliquez comment
peut-on contrôler la trajectoire d’un drone quadricoptère.


## Question 2

tello_control

node:
/control

topic :
/control
/emergency
/flip
/land
/parameter_events
/rosout
/takeoff

tello

topic :
/battery
/camera_info
/control
/emergency
/flip
/id
/image_raw
/imu
/land
/odom
/parameter_events
/rosout
/status
/takeoff
/temperature
/wifi_config

node :
/rqt_gui_py_node_83791
/tello

ros2 topic pub /takeoff std_msgs/msg/Empty {} --once
ros2 topic pub /land std_msgs/msg/Empty {} --once

colcon build
source install/local_setup.bash
ros2 run controller tello_behaviour
ros2 run controller qr_code_reader
ros2 run controller qr_code_follower
ros2 run controller spielberg
ros2 run controller spielberg
ros2 run controller manual_control
ros2 run joy joy_node
ros2 run tello tello


ros2 topic info /joy
ros2 service call /drone_mode tello_msg/srv/DroneMode "{mode: 0}"

[INFO] tello.py - 438 - Send command: 'wifi?'
[INFO] tello.py - 471 - Send command (no response expected): 'rc 0 0 0 0'
[INFO] tello.py - 471 - Send command (no response expected): 'rc 0 0 0 0'
[INFO] tello.py - 462 - Response wifi?: '90'
[INFO] tello.py - 471 - Send command (no response expected): 'rc 0 0 0 0'
[INFO] tello.py - 471 - Send command (no response expected): 'rc 0 0 0 0'
[INFO] tello.py - 438 - Send command: 'takeoff'
[INFO] tello.py - 438 - Send command: 'wifi?'
[INFO] tello.py - 462 - Response takeoff: '90'


colcon build --packages-select 

#!/home/alix.degironde/Public/ven_IROS/bin python3



TOUT LANCER EN 1 lignes

scripts/launch.sh
workspace/src/controller/launch/tello.launch.py
workspace/src/controller/setup.py 

dans terminal:
ros2 launch controller tello.launch.py


TODO : 

2.2 --> 3
3 serait plus une overview, 6 = deep dive dans le projet

4 et 5 merge, faire une grosse partie 4 avec tout les modes

Parler du tof distance (pb, mettre videos)

refactor comment on organise le readme : peut etre inclure partie 6 dans les parties correspondantes (ex: service pour surveillance, action pour spielberg...), d'abord parler des noeuds en overview comment il communiquent avec tello behaviour puis faire détail des noeuds avec les différents modes de vol 
On peut prendre partie 7 (a restructurer) et utiliser screen rqt pour expliquer comment la communication se fait avec de deep dive dans chaque mode

A GARDER type :
1. Utilisateur : ros2 service call /drone_mode "{mode: 2}"
         ↓
2. [tello_behaviour] : Reçoit requête DroneMode
         ↓
3. [tello_behaviour] : Arrête mode actuel (si nécessaire)
         ↓
4. [tello_behaviour] : Change current_mode = SPIELBERG
         ↓
5. [tello_behaviour] : Envoie Goal à Action Server spielberg
         ↓
6. [spielberg] : Accepte le Goal
         ↓
7. [spielberg] : Exécute séquence (avance → rotation → recul)
         │
         ├─> Feedback après chaque étape
         │   (reçu par tello_behaviour et loggé)
         │
8. [spielberg] : Publie Result (success=true)
         ↓
9. [tello_behaviour] : Reçoit Result et affiche confirmation

parler du lancement en 1 ligne de commande : 
TOUT LANCER EN 1 lignes

crée: scripts/launch.sh
crée: workspace/src/controller/launch/tello.launch.py
modfié: workspace/src/controller/setup.py 