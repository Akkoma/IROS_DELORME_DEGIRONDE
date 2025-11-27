#!/usr/bin/env python3
"""
Launch file pour le système complet Tello
Lance tous les nœuds nécessaires au contrôle du drone

Usage:
    ros2 launch controller tello.launch.py
    ros2 launch controller tello.launch.py log_level:=debug
"""

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, TimerAction
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    # Déclaration des arguments
    log_level_arg = DeclareLaunchArgument(
        'log_level',
        default_value='info',
        description='Niveau de log pour tous les nœuds (debug, info, warn, error)'
    )
    
    # Configuration
    log_level = LaunchConfiguration('log_level')
    
    # Liste des nœuds à lancer
    nodes = [
        # 1. Driver Tello - doit démarrer en premier
        Node(
            package='tello',
            executable='tello',
            name='tello_driver',
            output='screen',
            arguments=['--ros-args', '--log-level', log_level],
            respawn=False
        ),
    ]
    
    # 2. Attendre 2 secondes que le driver soit prêt, puis lancer les autres nœuds
    delayed_nodes = TimerAction(
        period=2.0,
        actions=[
            # Behaviour Manager - gère les différents modes du drone
            Node(
                package='controller',
                executable='tello_behaviour',
                name='tello_behaviour',
                output='screen',
                arguments=['--ros-args', '--log-level', log_level],
                respawn=False
            ),
            
            # QR Code Reader - détecte les QR codes pour changer de mode
            Node(
                package='controller',
                executable='qr_code_reader',
                name='qr_code_reader',
                output='screen',
                arguments=['--ros-args', '--log-level', log_level],
                respawn=False
            ),
            
            # QR Code Follower - suit un QR code détecté
            Node(
                package='controller',
                executable='qr_code_follower',
                name='qr_code_follower',
                output='screen',
                arguments=['--ros-args', '--log-level', log_level],
                respawn=False
            ),
            
            # Spielberg Action Server - séquence cinématique
            Node(
                package='controller',
                executable='spielberg',
                name='spielberg',
                output='screen',
                arguments=['--ros-args', '--log-level', log_level],
                respawn=False
            ),
            
            # Manual Control - contrôle manuel via joystick
            Node(
                package='controller',
                executable='manual_control',
                name='manual_control',
                output='screen',
                arguments=['--ros-args', '--log-level', log_level],
                respawn=False
            ),
            
            # Joy Node - interface pour le joystick
            Node(
                package='joy',
                executable='joy_node',
                name='joy_node',
                output='screen',
                parameters=[{
                    'dev': '/dev/input/js0',
                    'deadzone': 0.12,
                    'autorepeat_rate': 20.0
                }],
                respawn=False
            ),
            Node(
                package='controller',
                executable='surveillance',
                name='surveillance',
                output='screen',
                arguments=['--ros-args', '--log-level', log_level],
                respawn=False
            ),
            
        ]
    )
    
    # Retourner la description complète du launch
    return LaunchDescription([
        log_level_arg,
        *nodes,
        delayed_nodes
    ])
