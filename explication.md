
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

- Sorties (publishers) :
	- `/takeoff`, `/land`, `/emergency` : `std_msgs/Empty`
	- `/flip` : `std_msgs/String`
	- `/control` : `geometry_msgs/Twist`

### Logique fonctionnelle

- `tello_behaviour` maintient un `current_mode` (MANUAL, QR_FOLLOWER, SPIELBERG, SURVEILLANCE).
- En mode `MANUAL` : toutes les commandes reçues sur `/control/*` sont republiées vers les topics consommés par le pilote (`/takeoff`, `/land`, `/control`, etc.).
- En modes automatiques (QR_FOLLOWER, SPIELBERG, SURVEILLANCE) : seules les commandes critiques `takeoff`, `land` et `emergency` sont autorisées manuellement ; les commandes de mouvement (Twist) et `flip` sont bloquées, car les modes automatiques doivent piloter le drone eux-mêmes.
- Les méthodes `start_qr_follower_mode`, `start_spielberg_mode`, `start_surveillance_mode` sont actuellement des squelettes (TODO) et doivent implémenter la logique spécifique (ex : abonner à `image_raw`, détection QR, génération de Twist, trajectoires, etc.).

### Qui communique avec `tello_behaviour` ?

- `workspace/src/controller/controller/manual_control.py` : nœud `manual_control` qui lit le joystick (`/joy`) et publie sur :
	- `/control/takeoff`, `/control/land`, `/control/emergency` (Empty)
	- `/control/flip` (String)
	- `/control/cmd_vel` (Twist)
	Ces topics sont les entrées de `tello_behaviour`.

- `workspace/src/controller/test_drone_mode.py` : petit client qui appelle le service `/drone_mode` pour changer le mode (exécutable de test).

- `workspace/src/tello/tello/node.py` : pilote/driver Tello qui s'abonne aux topics publiés par `tello_behaviour` :
	- `takeoff`, `land`, `emergency`, `control`, `flip` (callbacks qui appellent les méthodes de `djitellopy` pour agir sur le drone).

- `workspace/src/tello_msg/srv/DroneMode.srv` : définition du service utilisé pour changer le mode.

### Flux simplifié des messages

Manual joystick -> `manual_control` publishes `/control/*` -> `tello_behaviour` filtre et (si autorisé) publie `/takeoff`, `/control`, etc. -> `tello` (driver) exécute la commande sur le drone.

### Remarques sur les noms de topics (slash initial)

- `tello_behaviour` publie sur des noms commençant par `/` (ex: `/takeoff`) alors que certains nœuds s'abonnent à `takeoff` (sans slash). En ROS2, si tous les nœuds sont dans le namespace racine, ces noms résolvent au même topic ; si vous utilisez des namespaces ou du remapping, assurez-vous de les harmoniser ou d'utiliser des remaps au lancement.

### Tests rapides recommandés

- Tester le service `/drone_mode` :

```bash
ros2 service call /drone_mode tello_msg/srv/DroneMode "{mode: 1}"
```

- Simuler un décollage manuel (publier sur `/control/takeoff`) :

```bash
ros2 topic pub /control/takeoff std_msgs/msg/Empty '{}' --once
```

Si le mode autorise, `tello_behaviour` republiera sur `/takeoff` et le pilote `tello` exécutera le décollage.

### Pièges et points d'attention

- Ordre de démarrage : le client qui appelle `/drone_mode` doit attendre que `tello_behaviour` expose le service (voir `test_drone_mode.py` qui attend le service avec `wait_for_service`).
- Concurrence : le pilote `tello` utilise des threads pour la vidéo et les status ; assurez-vous que l'envoi de commandes est thread-safe si vous modifiez le driver.
- Implémentations manquantes : les modes automatiques sont à implémenter (détection image, trajectoire, contrôle) — prévoir des topics d'entrée (ex: `image_raw` publié par `tello/node.py`) et sortie (`/control`).

### Suggestions / prochaines étapes possibles

1. Écrire un test automatique qui publie un `Twist` sur `/control/cmd_vel` et vérifie si `tello_behaviour` le relaie ou le bloque selon le mode.
2. Implémenter un prototype minimal pour `start_qr_follower_mode` : s'abonner à `image_raw`, détecter un QR statique et publier un `Twist` de correction sur `/control`.
3. Uniformiser les noms de topics (retrait du slash initial ou usage cohérent de remapping) pour éviter des problèmes de namespace.

---

Fichier(s) clés à consulter dans le workspace :

- `workspace/src/controller/controller/tello_behaviour.py` — nœud de comportement et service `/drone_mode`.
- `workspace/src/controller/controller/manual_control.py` — émetteur des commandes manuelles (`/control/*`).
- `workspace/src/tello/tello/node.py` — pilote Tello qui exécute les commandes reçues.
- `workspace/src/tello_msg/srv/DroneMode.srv` — définition du service de changement de mode.
- `workspace/src/controller/MODES_README.md` — documentation des modes et exemples d'utilisation.

Résumé : `tello_behaviour` agit comme un garde-fou central entre le contrôle manuel et le pilote hardware, permettant de basculer entre pilotage manuel et comportements autonomes tout en laissant les commandes critiques accessibles quand c'est nécessaire.

