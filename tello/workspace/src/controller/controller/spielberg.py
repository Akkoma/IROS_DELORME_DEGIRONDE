#!/usr/bin/env python3

import time

import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, CancelResponse, GoalResponse
from geometry_msgs.msg import Twist
from tello_msg.action import Spielberg


class SpielbergActionServer(Node):
    """
    Action Server ROS2 pour exécuter une séquence cinématique "Spielberg".
    Séquence : Avancer -> Rotation -> Reculer
    """

    TOTAL_STEPS = 3
    FORWARD_SPEED = 50.0
    ROTATION_SPEED = 40.0

    def __init__(self):
        super().__init__('spielberg_action_server')

        self._action_server = ActionServer(
            self,
            Spielberg,
            'spielberg',
            goal_callback=self.goal_callback,
            cancel_callback=self.cancel_callback,
            execute_callback=self.execute_callback,
        )

        self.cmd_vel_pub = self.create_publisher(Twist, '/control', 10)

        self.get_logger().info('Spielberg Action Server initialisé')

    def goal_callback(self, goal_request):
        """Accepte tous les goals entrants."""
        return GoalResponse.ACCEPT

    def cancel_callback(self, goal_handle):
        """Accepte les demandes d'annulation."""
        return CancelResponse.ACCEPT

    def execute_callback(self, goal_handle):
        """Exécute la séquence cinématique Spielberg en 3 étapes."""
        start_time = time.time()

        # Définition des étapes : (linear_y, angular_z, durée)
        steps = [
            (self.FORWARD_SPEED, 0.0, 2.0),   # Étape 1 : Avancer
            (0.0, self.ROTATION_SPEED, 1.0),  # Étape 2 : Rotation
            (-self.FORWARD_SPEED, 0.0, 2.0),  # Étape 3 : Reculer
        ]

        try:
            for step_num, (linear_y, angular_z, duration) in enumerate(steps, start=1):
                twist = Twist()
                twist.linear.y = linear_y
                twist.angular.z = angular_z
                self.cmd_vel_pub.publish(twist)

                self._publish_feedback(goal_handle, step_num, time.time() - start_time)
                time.sleep(duration)

                if goal_handle.is_cancel_requested:
                    return self._cancel_sequence(goal_handle)

            self._send_stop_command()

            result = Spielberg.Result()
            result.success = True
            result.message = f"Séquence complétée en {time.time() - start_time:.1f}s"
            goal_handle.succeed()
            return result

        except Exception as e:
            self.get_logger().error(f"Erreur Spielberg: {e}")
            self._send_stop_command()

            result = Spielberg.Result()
            result.success = False
            result.message = f"Erreur: {str(e)}"
            goal_handle.abort()
            return result

    def _cancel_sequence(self, goal_handle):
        """Annule la séquence et retourne le résultat approprié."""
        self._send_stop_command()
        goal_handle.canceled()

        result = Spielberg.Result()
        result.success = False
        result.message = "Séquence annulée"
        return result

    def _send_stop_command(self):
        """Envoie une commande d'arrêt au drone."""
        self.cmd_vel_pub.publish(Twist())

    def _publish_feedback(self, goal_handle, current_step, elapsed_time):
        """Publie le feedback de progression."""
        feedback_msg = Spielberg.Feedback()
        feedback_msg.current_step = current_step
        feedback_msg.total_steps = self.TOTAL_STEPS
        feedback_msg.elapsed_time = elapsed_time
        goal_handle.publish_feedback(feedback_msg)


def main(args=None):
    rclpy.init(args=args)
    node = SpielbergActionServer()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()