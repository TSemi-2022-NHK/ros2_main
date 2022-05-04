cmake_minimum_required(VERSION 3.5)

project(lidar_vel)

find_package(ament_cmake REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(rcutils REQUIRED)
find_package(PkgConfig)
find_package(csm REQUIRED)
find_package(Eigen3 REQUIRED)

find_package(Boost COMPONENTS thread REQUIRED)

include_directories(
  include
  ${EIGEN3_INCLUDE_DIRS}
  )

add_library(lidar_vel SHARED
  src/lidar_vel.cpp
)
rclcpp_components_register_nodes(lidar_vel "lidar_velocity::LidarVel")

target_include_directories(lidar_vel
  PRIVATE
  "include"
)

ament_target_dependencies(lidar_vel
  rclcpp
  rclcpp_components
  sensor_msgs
  rcutils
  Eigen3
  tf2_ros
  tf2
  tf2_geometry_msgs
  csm
  Boost
  nav_msgs
)

install(TARGETS lidar_vel DESTINATION lib/${PROJECT_NAME})


ament_package()


