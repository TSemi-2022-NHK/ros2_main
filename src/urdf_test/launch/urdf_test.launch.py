import os
import launch
from launch.substitutions import Command, LaunchConfiguration
import launch_ros
from launch.actions import IncludeLaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.parameter_descriptions import ParameterValue
import xacro
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    #パスを通す
    pkg_share = launch_ros.substitutions.FindPackageShare(package='urdf_test').find('urdf_test')
    default_model_path = os.path.join(pkg_share, 'urdf/urdf_test.urdf.xacro')
    urdf_path = os.path.join(pkg_share, 'urdf/urdf_test.urdf')
    default_rviz_config_path = os.path.join(pkg_share, 'rviz/urdf_config_show.rviz')

    doc = xacro.process_file(default_model_path)

    robot_desc = doc.toprettyxml(indent='  ')
    # urdf_pathに対してurdfを書き出し
    f = open(urdf_path, 'w')
    f.write(robot_desc)
    f.close()

    #robot_stateをpublishするノード
    robot_state_publisher_node = launch_ros.actions.Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='screen',
        arguments=[urdf_path]
    )
    
    #rvizを表示するノード
    rviz_node = launch_ros.actions.Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', default_rviz_config_path]
    )
    
    #センサ融合ノード
    robot_localization_node = launch_ros.actions.Node(
       package='robot_localization',
       executable='ekf_node',
       name='ekf_filter_node',
       output='screen',
       parameters=[os.path.join(pkg_share, 'config/ekf.yaml'), {'use_sim_time': LaunchConfiguration('use_sim_time')}]
    )

    return launch.LaunchDescription([
        launch.actions.DeclareLaunchArgument(name='use_sim_time', default_value='True',
                                            description='Flag to enable use_sim_time'),
        robot_state_publisher_node,
        rviz_node,
        robot_localization_node
    ])