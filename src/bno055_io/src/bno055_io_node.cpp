//
// Created by ryuzo on 2022/04/15.
//
#include <rclcpp/rclcpp.hpp>
#include <chrono>

#include "socketcan_interface_msg/msg/socketcan_if.hpp"
#include "bno055_io/bno055_io_node.hpp"

namespace bno055_io {

    Bno055Io::Bno055Io(const rclcpp::NodeOptions &options) : Bno055Io("", options){}

    Bno055Io::Bno055Io(const std::string &name_space, const rclcpp::NodeOptions &options) : rclcpp::Node(
            "bno055_node", options) {
        using namespace std::chrono_literals;

        declare_parameter("interval_ms", 50);
        auto interval_ms = this->get_parameter("interval_ms").as_int();

        _pub_timer = this->create_wall_timer(
                std::chrono::milliseconds(interval_ms),
                [this] { _publisher_callback(); }
        );
        
        _subscriber_AccelX = this->create_subscription<socketcan_interface_msg::msg::SocketcanIF>(
                std::string("can_rx_" + std::to_string(AccelX_CanId)),
                _qos,
                std::bind(&Bno055Io::_subscriber_callback_AccelX, this, std::placeholders::_1));
        _subscriber_AccelY = this->create_subscription<socketcan_interface_msg::msg::SocketcanIF>(
                std::string("can_rx_" + std::to_string(AccelY_CanId)),
                _qos,
                std::bind(&Bno055Io::_subscriber_callback_AccelY, this, std::placeholders::_1));
        _subscriber_AccelZ = this->create_subscription<socketcan_interface_msg::msg::SocketcanIF>(
                std::string("can_rx_" + std::to_string(AccelZ_CanId)),
                _qos,
                std::bind(&Bno055Io::_subscriber_callback_AccelZ, this, std::placeholders::_1));

        _subscriber_GyroX = this->create_subscription<socketcan_interface_msg::msg::SocketcanIF>(
                std::string("can_rx_" + std::to_string(GyroX_CanId)),
                _qos,
                std::bind(&Bno055Io::_subscriber_callback_GyroX, this, std::placeholders::_1));
        _subscriber_GyroY = this->create_subscription<socketcan_interface_msg::msg::SocketcanIF>(
                std::string("can_rx_" + std::to_string(GyroY_CanId)),
                _qos,
                std::bind(&Bno055Io::_subscriber_callback_GyroY, this, std::placeholders::_1));
        _subscriber_GyroZ = this->create_subscription<socketcan_interface_msg::msg::SocketcanIF>(
                std::string("can_rx_" + std::to_string(GyroZ_CanId)),
                _qos,
                std::bind(&Bno055Io::_subscriber_callback_GyroZ, this, std::placeholders::_1));

        _subscriber_QuatX = this->create_subscription<socketcan_interface_msg::msg::SocketcanIF>(
                std::string("can_rx_" + std::to_string(QuatX_CanId)),
                _qos,
                std::bind(&Bno055Io::_subscriber_callback_QuatX, this, std::placeholders::_1));
        _subscriber_QuatY = this->create_subscription<socketcan_interface_msg::msg::SocketcanIF>(
                std::string("can_rx_" + std::to_string(QuatY_CanId)),
                _qos,
                std::bind(&Bno055Io::_subscriber_callback_QuatY, this, std::placeholders::_1));
        _subscriber_QuatZ = this->create_subscription<socketcan_interface_msg::msg::SocketcanIF>(
                std::string("can_rx_" + std::to_string(QuatZ_CanId)),
                _qos,
                std::bind(&Bno055Io::_subscriber_callback_QuatZ, this, std::placeholders::_1));
    }

    void Bno055Io::_publisher_callback() {

    }

    void Bno055Io::_subscriber_callback_AccelX(socketcan_interface_msg::msg::SocketcanIF msg) {

    }

    void Bno055Io::_subscriber_callback_AccelY(socketcan_interface_msg::msg::SocketcanIF msg) {

    }

    void Bno055Io::_subscriber_callback_AccelZ(socketcan_interface_msg::msg::SocketcanIF msg) {

    }

    void Bno055Io::_subscriber_callback_GyroX(socketcan_interface_msg::msg::SocketcanIF msg) {

    }

    void Bno055Io::_subscriber_callback_GyroY(socketcan_interface_msg::msg::SocketcanIF msg) {

    }

    void Bno055Io::_subscriber_callback_GyroZ(socketcan_interface_msg::msg::SocketcanIF msg) {

    }

    void Bno055Io::_subscriber_callback_QuatX(socketcan_interface_msg::msg::SocketcanIF msg) {

    }

    void Bno055Io::_subscriber_callback_QuatY(socketcan_interface_msg::msg::SocketcanIF msg) {

    }

    void Bno055Io::_subscriber_callback_QuatZ(socketcan_interface_msg::msg::SocketcanIF msg) {

    }


}  // namespace bno055_io
