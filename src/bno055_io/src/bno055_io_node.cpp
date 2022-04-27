//
// Created by ryuzo on 2022/04/15.
//
#include <rclcpp/rclcpp.hpp>
#include <chrono>

#include "socketcan_interface_msg/msg/socketcan_if.hpp"
#include "socketcan_interface/socketcan_interface_node.hpp"
#include "bno055_io/bno055_io_node.hpp"

namespace bno055_io {

    Bno055Io::Bno055Io(const rclcpp::NodeOptions &options) : Bno055Io("", options){}

    Bno055Io::Bno055Io(const std::string &name_space, const rclcpp::NodeOptions &options) : rclcpp::Node(
            "bno055_node", options) {
        using namespace std::chrono_literals;

        declare_parameter("interval_ms", 50);
        auto interval_ms = this->get_parameter("interval_ms").as_int();

        // init imu msg type.
        // disable cov
        Axinit = AyInit = AzInit = GxInit = GyInit = GzInit = QxInit = QyInit = QzInit = false;

        imu_msg = std::make_shared<sensor_msgs::msg::Imu>();
        for(int i=0; i < 9; ++i){
            imu_msg->orientation_covariance[i] = 0.0;
            imu_msg->angular_velocity_covariance[i] = 0.0;
            imu_msg->linear_acceleration_covariance[i] = 0.0;
        }

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
        _subscriber_QuatW = this->create_subscription<socketcan_interface_msg::msg::SocketcanIF>(
                std::string("can_rx_" + std::to_string(QuatW_CanId)),
                _qos,
                std::bind(&Bno055Io::_subscriber_callback_QuatW, this, std::placeholders::_1));
    }

    void Bno055Io::_publisher_callback() {
        if (Axinit and AyInit and AzInit and GxInit and GyInit and GzInit and QxInit and QyInit and QzInit and QwInit){
            //if all data is read at least once, publish imu_msg
            bno055_imu_publisher->publish(*imu_msg);
        }else{
            RCLCPP_INFO(this->get_logger(), "BNO055 not initilized yet.");
            //do nothing
        }
    }

    void Bno055Io::_subscriber_callback_AccelX(socketcan_interface_msg::msg::SocketcanIF msg) {
        Axinit = true;
        uint8_t linX_as_bytes[8];
        for (int i = 0; i < 8; ++i) {
            linX_as_bytes[i] = msg.candata[i];
        }
        double linX_as_double = can_utils::convert_byte_to_double(linX_as_bytes);
        imu_msg->linear_acceleration.set__x(linX_as_double);
    }

    void Bno055Io::_subscriber_callback_AccelY(socketcan_interface_msg::msg::SocketcanIF msg) {
        AyInit = true;
        uint8_t linY_as_bytes[8];
        for (int i = 0; i < 8; ++i) {
            linY_as_bytes[i] = msg.candata[i];
        }
        double linY_as_double = can_utils::convert_byte_to_double(linY_as_bytes);
        imu_msg->linear_acceleration.set__y(linY_as_double);
    }

    void Bno055Io::_subscriber_callback_AccelZ(socketcan_interface_msg::msg::SocketcanIF msg) {
        AzInit = true;
        uint8_t linZ_as_bytes[8];
        for (int i = 0; i < 8; ++i) {
            linZ_as_bytes[i] = msg.candata[i];
        }
        double linZ_as_double = can_utils::convert_byte_to_double(linZ_as_bytes);
        imu_msg->linear_acceleration.set__z(linZ_as_double);
    }

    void Bno055Io::_subscriber_callback_GyroX(socketcan_interface_msg::msg::SocketcanIF msg) {
        GxInit = true;
        uint8_t GyroX_as_bytes[8];
        for (int i = 0; i < 8; ++i) {
            GyroX_as_bytes[i] = msg.candata[i];
        }
        double GyroX_as_double = can_utils::convert_byte_to_double(GyroX_as_bytes);
        imu_msg->angular_velocity.set__x(GyroX_as_double);
    }

    void Bno055Io::_subscriber_callback_GyroY(socketcan_interface_msg::msg::SocketcanIF msg) {
        GyInit = true;
        uint8_t GyroY_as_bytes[8];
        for (int i = 0; i < 8; ++i) {
            GyroY_as_bytes[i] = msg.candata[i];
        }
        double GyroY_as_double = can_utils::convert_byte_to_double(GyroY_as_bytes);
        imu_msg->angular_velocity.set__x(GyroY_as_double);

    }

    void Bno055Io::_subscriber_callback_GyroZ(socketcan_interface_msg::msg::SocketcanIF msg) {
        GzInit = true;
        uint8_t GyroZ_as_bytes[8];
        for (int i = 0; i < 8; ++i) {
            GyroZ_as_bytes[i] = msg.candata[i];
        }
        double GyroZ_as_double = can_utils::convert_byte_to_double(GyroZ_as_bytes);
        imu_msg->angular_velocity.set__z(GyroZ_as_double);

    }

    void Bno055Io::_subscriber_callback_QuatX(socketcan_interface_msg::msg::SocketcanIF msg) {
        QxInit = true;
        uint8_t QuatX_as_bytes[8];
        for (int i = 0; i < 8; ++i) {
            QuatX_as_bytes[i] = msg.candata[i];
        }
        double QuatX_as_double = can_utils::convert_byte_to_double(QuatX_as_bytes);
        imu_msg->orientation.set__x(QuatX_as_double);
    }

    void Bno055Io::_subscriber_callback_QuatY(socketcan_interface_msg::msg::SocketcanIF msg) {
        QyInit = true;
        uint8_t QuatY_as_bytes[8];
        for (int i = 0; i < 8; ++i) {
            QuatY_as_bytes[i] = msg.candata[i];
        }
        double QuatY_as_double = can_utils::convert_byte_to_double(QuatY_as_bytes);
        imu_msg->orientation.set__y(QuatY_as_double);

    }

    void Bno055Io::_subscriber_callback_QuatZ(socketcan_interface_msg::msg::SocketcanIF msg) {
        QzInit = true;
        uint8_t QuatZ_as_bytes[8];
        for (int i = 0; i < 8; ++i) {
            QuatZ_as_bytes[i] = msg.candata[i];
        }
        double QuatZ_as_double = can_utils::convert_byte_to_double(QuatZ_as_bytes);
        imu_msg->orientation.set__z(QuatZ_as_double);

    }

    void Bno055Io::_subscriber_callback_QuatW(socketcan_interface_msg::msg::SocketcanIF msg) {
        QwInit = true;
        uint8_t QuatW_as_bytes[8];
        for (int i = 0; i < 8; ++i) {
            QuatW_as_bytes[i] = msg.candata[i];
        }
        double QuatW_as_double = can_utils::convert_byte_to_double(QuatW_as_bytes);
        imu_msg->orientation.set__z(QuatW_as_double);
    }


}  // namespace bno055_io
