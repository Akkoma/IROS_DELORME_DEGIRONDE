import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/alix.degironde/Public/tello-ros2/workspace/install/controller'
