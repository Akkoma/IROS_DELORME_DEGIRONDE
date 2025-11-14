# IROS_DELORME_DEGIRONDE


# IROS_DELORME_DEGIRONDE — Résumé et guide rapide

## Objectif
Ce document récapitule le comportement attendu du projet, répond aux questions posées et fournit une documentation claire du nœud `tello_behaviour` et des interactions entre les packages du workspace.

---

## Questions & réponses rapides

### 1) Quelles sont les quatre commandes classiques d’un drone quadrirotor ?
- Gaz (thrust / altitude)
- Tangage (pitch — déplacement avant/arrière)
- Roulis (roll — déplacement gauche/droite)
- Lacet (yaw — rotation autour de l’axe vertical)

### 2) Contrôle de trajectoire (résumé)
- Choisir un repère (ex : X avant, Y droit, Z haut).  
- Commander les quatre axes ci‑dessus — combiner pitch/roll/yaw/thrust pour suivre une trajectoire.  
- Utiliser une boucle de contrôle : mesures (IMU, odom, distance), calcul d’erreurs, loi de contrôle (PID ou MPC), et sortie sur les commandes moteurs ou sur une interface de haut niveau (Twist).

### 3) Organisation du dépôt / bonnes pratiques
- Dans un workspace ROS2, on clone généralement un package dans `src/`.  
- Ici le dépôt cloné contient tout un projet (avec son propre workspace). Bonne pratique : travailler dans le `workspace` fourni (ex : `workspace/src/...`) et ne pas imbriquer plusieurs workspaces.

### 4) Topics liés à la commande du drone (exécutables dans le workspace)
Liste obtenue par `ros2 topic list` (exemples) :
- /control
- /emergency
- /flip
- /land
- /parameter_events
- /rosout
- /takeoff

Topic d’affichage altitude : `/status` (champ `distance_tof` dans le message custom)

---

## Pourquoi modifier la sortie de `manual_control` (topic change)
- Changer le topic sortant de `manual_control` permet de centraliser l’arbitrage (via `tello_behaviour`) entre commandes manuelles et modes automatiques.  
- Intérêt : faire le filtrage au plus proche de l’entrée joystick garantit que les modes automatiques ne reçoivent pas de commandes manuelles non souhaitées.  
- Faire le remapping/filtrage dans `joy` serait moins clair et moins modulaire ; `tello_behaviour` devient le point unique d’arbitrage et de sécurité.

---

## Nœud `tello_behaviour` — vue synthétique

Chemin : `workspace/src/controller/controller/tello_behaviour.py`

But : filtrer et relayer les commandes manuelles vers le pilote Tello, exposer un service pour changer le mode.

Contrat (entrées / sorties)
- Subscriptions (entrées) :
    - `/control/takeoff` : std_msgs/Empty
    - `/control/land` : std_msgs/Empty
    - `/control/emergency` : std_msgs/Empty
    - `/control/flip` : std_msgs/String
    - `/control/cmd_vel` : geometry_msgs/Twist
- Service exposé :
    - `/drone_mode` : tello_msg/srv/DroneMode (request int32 mode → response bool success, string message)
- Publications (sorties) :
    - `/takeoff`, `/land`, `/emergency` : std_msgs/Empty
    - `/flip` : std_msgs/String
    - `/control` : geometry_msgs/Twist

Logique fonctionnelle
- Maintien d’un `current_mode` : MANUAL, QR_FOLLOWER, SPIELBERG, SURVEILLANCE.  
- En MANUAL : tout est relayé vers le pilote.  
- En modes automatiques : seuls `takeoff`, `land`, `emergency` sont autorisés — les Twists et flips peuvent être bloqués.  
- Les méthodes pour les modes automatiques (ex : `start_qr_follower_mode`) sont à implémenter (squelettes TODO).

Remarques sur les noms de topics
- Certains nœuds publient avec un slash initial (`/takeoff`) alors que d’autres s’abonnent sans slash (`takeoff`). Si tous les nœuds sont au namespace racine, cela fonctionne ; sinon harmoniser ou utiliser des remaps dans les launch files.

---

## Qui communique avec `tello_behaviour` ?
- `manual_control.py` (workspace/src/controller) : lit `/joy`, publie `/control/*` → entrées de `tello_behaviour`.  
- `test_drone_mode.py` : client test pour `/drone_mode`.  
- `tello/node.py` (driver) : s’abonne à `/takeoff`, `/land`, `/emergency`, `/control`, `/flip` et exécute les actions via djitellopy.  
- `tello_msg/srv/DroneMode.srv` : définition du service.

Flux simplifié : Joystick → manual_control → /control/* → tello_behaviour (filtre) → /takeoff, /control, etc. → driver tello.

---

## Tests et commandes utiles

Tester le service `/drone_mode` :
```bash
ros2 service call /drone_mode tello_msg/srv/DroneMode "{mode: 1}"
```

Simuler un décollage manuel :
```bash
ros2 topic pub /control/takeoff std_msgs/msg/Empty '{}' --once
```

Lister topics :
```bash
ros2 topic list
```

Echo d’un topic :
```bash
ros2 topic echo /control
```

---

## Pièges, points d’attention et recommandations
- Démarrage : attendre que `/drone_mode` soit disponible (utiliser `wait_for_service` côté client).  
- Concurrence : le driver utilise des threads (vidéo, status). Veiller au thread-safety lors de l’envoi de commandes.  
- Harmoniser les chemins de topics (préférence : noms relatifs + remaps, ou tout absolu documenté).  
- Ajouter des logs DEBUG dans `tello_behaviour` pour tracer messages bloqués/relaisés.  
- Écrire des tests automatisés : publier un `Twist` sur `/control/cmd_vel` et vérifier le comportement selon le mode.

Prochaines étapes suggérées
1. Implémenter un test unitaire pour le relais/blocage de Twist selon le mode.  
2. Prototyper `start_qr_follower_mode` : s’abonner à `image_raw`, détecter QR, publier `Twist`.  
3. Uniformiser les noms de topics et documenter la convention.

---

## Fichiers clés à consulter
- workspace/src/controller/controller/tello_behaviour.py  
- workspace/src/controller/controller/manual_control.py  
- workspace/src/tello/tello/node.py  
- workspace/src/tello_msg/srv/DroneMode.srv  
- workspace/src/controller/MODES_README.md

---

Résumé : `tello_behaviour` centralise l’arbitrage entre commandes manuelles et modes automatiques, permet un basculement sûr via `/drone_mode` et nécessite l’implémentation des modes automatiques et l’uniformisation des noms de topics pour une utilisation robuste.







