#include "tcp_joystick_handler/tcp_joystick_handler_node.hpp"

namespace tcp_joystick_handler {

    TcpJoystickHandlerNode::TcpJoystickHandlerNode(const rclcpp::NodeOptions &options): TcpJoystickHandlerNode("", options) {

    }

    TcpJoystickHandlerNode::TcpJoystickHandlerNode(const std::string &name_space, const rclcpp::NodeOptions &options)
            : Node("tcp_joystick_node", options) {
        using namespace std::chrono_literals;

        _is_connected = false;
        _tcp.receive_setup();

        declare_parameter("interval_ms", 1);
        auto interval_ms = this->get_parameter("interval_ms").as_int();
        _msg = std::make_shared<std_msgs::msg::String>();

        _joystick_publisher = this->create_publisher<std_msgs::msg::String>("joystick", _qos);

        _pub_timer = this->create_wall_timer(
                std::chrono::milliseconds(interval_ms),
                [this] { _publisher_callback(); }
        );

    }

    void TcpJoystickHandlerNode::_publisher_callback() {
        if (!_is_connected){    // before anything had been connected.
            std::string ret;
            ret = _tcp.connect();
            if (ret == "0"){
                // no connection are available.
                return;
            } else if (ret == "-1"){
                RCLCPP_ERROR(this->get_logger(), "connection error");
                return;
            } else {
                connected_address = ret;
                _is_connected = true;
            }
        }
        // after connected
        std::basic_string<char> recieved_data = _tcp.recieveLines();
        if (recieved_data == ""){   // nothing have been received. refer that this is non-blocking mode.
            return;
        } else{
            _msg->data = recieved_data;
            RCLCPP_INFO(this->get_logger(), "PUBLISHING FROM TCP:'%s'", _msg->data.c_str());
            _joystick_publisher->publish(*_msg);
        }
    }
}  // namespace tcp_joystick_handler
