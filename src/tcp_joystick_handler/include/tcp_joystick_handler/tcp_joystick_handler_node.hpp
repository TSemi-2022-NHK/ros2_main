#ifndef TCP_JOYSTICK_HANDLER__TCP_JOYSTICK_HANDLER_NODE_HPP_
#define TCP_JOYSTICK_HANDLER__TCP_JOYSTICK_HANDLER_NODE_HPP_

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <chrono>

#include "visibility_control.h"
#include "tcp_nonblocking.hpp"

namespace tcp_joystick_handler {

    class TcpJoystickHandlerNode : public rclcpp::Node {
    private:

        bool _is_connected;
        tcp _tcp = tcp(8000);
        std::string connected_address;

        rclcpp::TimerBase::SharedPtr _pub_timer;

        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr _joystick_publisher;

        std::shared_ptr<std_msgs::msg::String> _msg;
        rclcpp::QoS _qos = rclcpp::SensorDataQoS();

        void _publisher_callback();

    public:
        TCP_JOYSTICK_HANDLER_PUBLIC
        TcpJoystickHandlerNode(const rclcpp::NodeOptions &options = rclcpp::NodeOptions());

        TCP_JOYSTICK_HANDLER_PUBLIC
        TcpJoystickHandlerNode(const std::string &name_space,
                               const rclcpp::NodeOptions &options = rclcpp::NodeOptions());

    };

}  // namespace tcp_joystick_handler

#endif  // TCP_JOYSTICK_HANDLER__TCP_JOYSTICK_HANDLER_NODE_HPP_
