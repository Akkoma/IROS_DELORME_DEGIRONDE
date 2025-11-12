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

📉 Affichage de l'altitude mesuré : topic /status, 

