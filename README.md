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

ros2 run controller tello_behaviour
ros2 run controller manual_control
ros2 run joy joy_node
ros2 run tello tello
ros2 topic info /joy
