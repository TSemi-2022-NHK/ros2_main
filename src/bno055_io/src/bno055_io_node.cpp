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
        Ainit = GInit = QInit = false;

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
        
        _subscriber_Accel = this->create_subscription<socketcan_interface_msg::msg::SocketcanIF>(
                std::string("can_rx_" + std::to_string(Accel_CanId)),
                _qos,
                std::bind(&Bno055Io::_subscriber_callback_Accel, this, std::placeholders::_1));

        _subscriber_Gyro = this->create_subscription<socketcan_interface_msg::msg::SocketcanIF>(
                std::string("can_rx_" + std::to_string(Gyro_CanId)),
                _qos,
                std::bind(&Bno055Io::_subscriber_callback_Gyro, this, std::placeholders::_1));

        _subscriber_Quat = this->create_subscription<socketcan_interface_msg::msg::SocketcanIF>(
                std::string("can_rx_" + std::to_string(Quat_CanId)),
                _qos,
                std::bind(&Bno055Io::_subscriber_callback_Quat, this, std::placeholders::_1));
    }

    void Bno055Io::_publisher_callback() {
        if (Ainit and GInit and QInit){
            //if all data is read at least once, publish imu_msg
            bno055_imu_publisher->publish(*imu_msg);
        }else{
            RCLCPP_INFO(this->get_logger(), "BNO055 not initilized yet.");
            //do nothing
        }
    }

    void Bno055Io::_subscriber_callback_Accel(socketcan_interface_msg::msg::SocketcanIF msg) {
        Ainit = true;
        uint8_t lin_as_bytes[8];
        for (int i = 0; i < 8; ++i) {
            lin_as_bytes[i] = msg.candata[i];
        }
        uint8_t tmp_arr[2];

        tmp_arr[0] = lin_as_bytes[0];
        tmp_arr[1] = lin_as_bytes[1];
        imu_msg->linear_acceleration.set__x( can_utils::f16tof32(can_utils::convert_byte_to_f16(tmp_arr)));

        tmp_arr[0] = lin_as_bytes[2];
        tmp_arr[1] = lin_as_bytes[3];
        imu_msg->linear_acceleration.set__y(can_utils::f16tof32(can_utils::convert_byte_to_f16(tmp_arr)));

        tmp_arr[0] = lin_as_bytes[0];
        tmp_arr[1] = lin_as_bytes[1];
        imu_msg->linear_acceleration.set__z(can_utils::f16tof32(can_utils::convert_byte_to_f16(tmp_arr)));
    }

    void Bno055Io::_subscriber_callback_Gyro(socketcan_interface_msg::msg::SocketcanIF msg) {
        GInit = true;
        uint8_t Gyro_as_bytes[8];
        for (int i = 0; i < 8; ++i) {
            Gyro_as_bytes[i] = msg.candata[i];
        }
        uint8_t tmp_arr[2];

        tmp_arr[0] = Gyro_as_bytes[0];
        tmp_arr[1] = Gyro_as_bytes[1];
        imu_msg->angular_velocity.set__x(can_utils::f16tof32(can_utils::convert_byte_to_f16(tmp_arr)));

        tmp_arr[0] = Gyro_as_bytes[2];
        tmp_arr[1] = Gyro_as_bytes[3];
        imu_msg->angular_velocity.set__y(can_utils::f16tof32(can_utils::convert_byte_to_f16(tmp_arr)));

        tmp_arr[0] = Gyro_as_bytes[4];
        tmp_arr[1] = Gyro_as_bytes[5];
        imu_msg->angular_velocity.set__z(can_utils::f16tof32(can_utils::convert_byte_to_f16(tmp_arr)));
    }

    void Bno055Io::_subscriber_callback_Quat(socketcan_interface_msg::msg::SocketcanIF msg) {
        QInit = true;
        uint8_t Quat_as_bytes[8];
        for (int i = 0; i < 8; ++i) {
            Quat_as_bytes[i] = msg.candata[i];
        }
        uint8_t tmp_arr[2];

        tmp_arr[0] = Quat_as_bytes[0];
        tmp_arr[1] = Quat_as_bytes[1];
        imu_msg->orientation.set__x(can_utils::f16tof32(can_utils::convert_byte_to_f16(tmp_arr)));

        tmp_arr[0] = Quat_as_bytes[2];
        tmp_arr[1] = Quat_as_bytes[3];
        imu_msg->orientation.set__y(can_utils::f16tof32(can_utils::convert_byte_to_f16(tmp_arr)));

        tmp_arr[0] = Quat_as_bytes[4];
        tmp_arr[1] = Quat_as_bytes[5];
        imu_msg->orientation.set__z(can_utils::f16tof32(can_utils::convert_byte_to_f16(tmp_arr)));

        tmp_arr[0] = Quat_as_bytes[6];
        tmp_arr[1] = Quat_as_bytes[7];
        imu_msg->orientation.set__w(can_utils::f16tof32(can_utils::convert_byte_to_f16(tmp_arr)));
    }


}  // namespace bno055_io
