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
