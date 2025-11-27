#!/home/alix.degironde/Public/ven_IROS/bin python3

import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, CancelResponse, GoalResponse
from geometry_msgs.msg import Twist
from tello_msg.action import Spielberg
import time


class SpielbergActionServer(Node):
    def __init__(self):
        super().__init__('spielberg_action_server')
        
        # Action Server
        self._action_server = ActionServer(
            self,
            Spielberg,
            'spielberg',
            goal_callback=self.goal_callback,
            cancel_callback=self.cancel_callback,
            execute_callback=self.execute_callback,
        )
        
        # Publisher pour envoyer les commandes de mouvement
        self.cmd_vel_pub = self.create_publisher(
            Twist,
            '/control',
            10
        )
        
        self.get_logger().info('Noeud spielberg_action_server initialisé')
        self.get_logger().info("Action server 'spielberg' disponible")
    
    def goal_callback(self, goal_request):
        """Accepte ou rejette un goal reçu"""
        self.get_logger().info('Réception d\'un goal Spielberg...')
        return GoalResponse.ACCEPT
    
    def cancel_callback(self, goal_handle):
        """Gère l'annulation d'un goal en cours"""
        self.get_logger().info('Réception d\'une demande d\'annulation Spielberg')
        return CancelResponse.ACCEPT
    
    def execute_callback(self, goal_handle):
        """Exécute la séquence Spielberg cinématique"""
        self.get_logger().info('Exécution de la séquence Spielberg...')
        
        # Paramètres de la séquence
        total_steps = 3
        start_time = time.time()
        
        try:
            # Étape 1 : Avancer
            self.get_logger().info('[Étape 1/3] Avancement...')
            twist = Twist()
            twist.linear.x = float(0.0)
            twist.linear.y = float(50.0)
            twist.linear.z = float(0.0)
            twist.angular.x = float(0.0)
            twist.angular.y = float(0.0)
            twist.angular.z = float(0.0)
            self.cmd_vel_pub.publish(twist)
            self.publish_feedback(goal_handle, 1, total_steps, float(0.0))
            time.sleep(2)
            
            if goal_handle.is_cancel_requested:
                self.send_stop_command()
                goal_handle.canceled()
                self.get_logger().warn('Séquence Spielberg annulée')
                result = Spielberg.Result()
                result.success = False
                result.message = "Séquence annulée"
                return result
            
            # Étape 2 : Rotation (tourner la caméra)
            self.get_logger().info('[Étape 2/3] Rotation caméra...')
            twist = Twist()
            twist.linear.x = float(0.0)
            twist.linear.y = float(0.0)
            twist.linear.z = float(0.0)
            twist.angular.x = float(0.0)
            twist.angular.y = float(0.0)
            twist.angular.z = float(40.0)
            self.cmd_vel_pub.publish(twist)
            self.publish_feedback(goal_handle, 2, total_steps, float(time.time() - start_time))
            time.sleep(1)
            
            if goal_handle.is_cancel_requested:
                self.send_stop_command()
                goal_handle.canceled()
                self.get_logger().warn('Séquence Spielberg annulée')
                result = Spielberg.Result()
                result.success = False
                result.message = "Séquence annulée"
                return result
            
            # Étape 3 : Reculer
            self.get_logger().info('[Étape 3/3] Recul...')
            twist = Twist()
            twist.linear.x = float(0.0)
            twist.linear.y = float(-50.0)
            twist.linear.z = float(0.0)
            twist.angular.x = float(0.0)
            twist.angular.y = float(0.0)
            twist.angular.z = float(0.0)
            self.cmd_vel_pub.publish(twist)
            self.publish_feedback(goal_handle, 3, total_steps, float(time.time() - start_time))
            time.sleep(2)
            
            # Arrêter le drone
            self.send_stop_command()
            
            # Succès
            result = Spielberg.Result()
            result.success = True
            result.message = f"Séquence Spielberg complétée en {time.time() - start_time:.1f}s"
            self.get_logger().info(f"✓ {result.message}")
            goal_handle.succeed()
            return result
            
        except Exception as e:
            self.get_logger().error(f"Erreur lors de l'exécution Spielberg: {e}")
            self.send_stop_command()
            result = Spielberg.Result()
            result.success = False
            result.message = f"Erreur: {str(e)}"
            goal_handle.abort()
            return result
    
    def send_stop_command(self):
        """Envoie une commande d'arrêt au drone"""
        twist = Twist()
        twist.linear.x = float(0.0)
        twist.linear.y = float(0.0)
        twist.linear.z = float(0.0)
        twist.angular.x = float(0.0)
        twist.angular.y = float(0.0)
        twist.angular.z = float(0.0)
        self.cmd_vel_pub.publish(twist)
    
    def publish_feedback(self, goal_handle, current_step, total_steps, elapsed_time):
        """Publie le feedback de progression"""
        feedback_msg = Spielberg.Feedback()
        feedback_msg.current_step = int(current_step)
        feedback_msg.total_steps = int(total_steps)
        feedback_msg.elapsed_time = float(elapsed_time)
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