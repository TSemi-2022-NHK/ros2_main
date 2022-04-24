//
// Created by ryuzo on 2022/04/15.
//

#include <rclcpp/rclcpp.hpp>
#include <rcl/rcl.h>
#include "socketcan_interface/socketcan_interface_node.hpp"
#include <iostream>

int main(int argc, char * argv[]){
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<socketcan_interface::SocketcanInterface>());
    rclcpp::shutdown();
    return 0;
}