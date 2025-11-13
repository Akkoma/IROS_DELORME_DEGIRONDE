#!/usr/bin/env python3
"""
Script de test pour le service de changement de mode du drone
Usage: python3 test_drone_mode.py [mode_number]
"""

import sys
import rclpy
from rclpy.node import Node
from tello_msg.srv import DroneMode


def main():
    if len(sys.argv) < 2:
        print("Usage: python3 test_drone_mode.py [mode_number]")
        print("Modes disponibles:")
        print("  0 - Manuel")
        print("  1 - QR Follower")
        print("  2 - Spielberg")
        print("  3 - Surveillance")
        sys.exit(1)
    
    mode = int(sys.argv[1])
    
    if mode < 0 or mode > 3:
        print(f"Erreur: Mode {mode} invalide. Utilisez 0-3.")
        sys.exit(1)
    
    rclpy.init()
    node = Node('test_drone_mode_client')
    
    client = node.create_client(DroneMode, '/drone_mode')
    
    print(f"Attente du service /drone_mode...")
    if not client.wait_for_service(timeout_sec=5.0):
        print("Erreur: Service /drone_mode non disponible")
        print("Assurez-vous que le noeud tello_behaviour est lancé:")
        print("  ros2 run controller tello_behaviour")
        node.destroy_node()
        rclpy.shutdown()
        sys.exit(1)
    
    request = DroneMode.Request()
    request.mode = mode
    
    mode_names = {0: "Manuel", 1: "QR Follower", 2: "Spielberg", 3: "Surveillance"}
    print(f"Envoi de la requête pour passer en mode {mode_names[mode]} (ID: {mode})...")
    
    future = client.call_async(request)
    rclpy.spin_until_future_complete(node, future)
    
    response = future.result()
    
    if response.success:
        print(f"✅ Succès: {response.message}")
    else:
        print(f"❌ Échec: {response.message}")
    
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
