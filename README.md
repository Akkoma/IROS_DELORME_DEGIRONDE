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
