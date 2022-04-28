import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    param_file = os.path.join(
            get_package_share_directory('urg'), 'config',
            'config_urg.yaml')
    print(param_file)
    hokuyo_node = Node(
        package='urg_node', 
        node_executable='urg_node_driver', 
        output='screen',
        parameters=[param_file]
        )

    ld.add_action(hokuyo_node)
    return ld