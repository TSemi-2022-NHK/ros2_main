//
// Created by ryuzo on 2022/04/15.
//

#include <rclcpp/rclcpp.hpp>
#include <rcl/rcl.h>
#include "socketcan_interface/socketcan_interface_node.hpp"
#include "bno055_io/bno055_io_node.hpp"
#include "tcp_joystick_handler/tcp_joystick_handler_node.hpp"
#include <iostream>

int main(int argc, char * argv[]){
    rclcpp::init(argc,argv);
    rclcpp::executors::MultiThreadedExecutor exec;

    auto socketcan_node = std::make_shared<socketcan_interface::SocketcanInterface>();
    exec.add_node(socketcan_node);
    auto bno055_node = std::make_shared<bno055_io::Bno055Io>();
    exec.add_node(bno055_node);
    auto joystick_node = std::make_shared<tcp_joystick_handler::TcpJoystickHandlerNode>();
    exec.add_node(joystick_node);

    exec.spin();
    rclcpp::shutdown();
    return 0;
}