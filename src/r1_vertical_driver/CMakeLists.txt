cmake_minimum_required(VERSION 3.8)
project(r1_vertical_driver)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_ros REQUIRED)
find_package(rclcpp REQUIRED)
find_package(socketcan_interface REQUIRED)

add_library(r1_vertical_driver_node src/r1_vertical_driver_node.cpp)
target_compile_features(r1_vertical_driver_node PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
target_include_directories(r1_vertical_driver_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
ament_target_dependencies(
  r1_vertical_driver_node
  "rclcpp"
  "socketcan_interface"
)

# Causes the visibility macros to use dllexport rather than dllimport,
# which is appropriate when building the dll but not consuming it.
target_compile_definitions(r1_vertical_driver_node PRIVATE "R1_VERTICAL_DRIVER_BUILDING_LIBRARY")

ament_export_targets(export_${PROJECT_NAME} HAS_LIBRARY_TARGET)
ament_export_dependencies(
        rclcpp
        socketcan_interface
)

install(
  DIRECTORY include/
  DESTINATION include
)
install(
  TARGETS r1_vertical_driver_node
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_export_include_directories(
  include
)
ament_export_libraries(
  r1_vertical_driver_node
)
ament_export_targets(
  export_${PROJECT_NAME}
)

ament_package()
