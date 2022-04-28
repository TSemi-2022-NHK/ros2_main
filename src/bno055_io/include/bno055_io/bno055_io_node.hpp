#ifndef BNO055_IO__BNO055_IO_NODE_HPP_
#define BNO055_IO__BNO055_IO_NODE_HPP_

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/imu.hpp>

#include "bno055_io/visibility_control.h"
#include "socketcan_interface_msg/msg/socketcan_if.hpp"
#include "visibility_control.h"

#define Accel_CanId 0x0312

#define Gyro_CanId 0x0312

#define Quat_CanId 0x0314


namespace bno055_io {

    class Bno055Io : public rclcpp::Node {
    private:

        bool Ainit, GInit, QInit;

        rclcpp::Subscription<socketcan_interface_msg::msg::SocketcanIF>::SharedPtr _subscriber_Accel;
        rclcpp::Subscription<socketcan_interface_msg::msg::SocketcanIF>::SharedPtr _subscriber_Gyro;
        rclcpp::Subscription<socketcan_interface_msg::msg::SocketcanIF>::SharedPtr _subscriber_Quat;

        rclcpp::TimerBase::SharedPtr _pub_timer;

        rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr bno055_imu_publisher;

        std::shared_ptr<sensor_msgs::msg::Imu> imu_msg;
        rclcpp::QoS _qos = rclcpp::QoS(1).best_effort();

        void _publisher_callback();

        void _subscriber_callback_Accel(socketcan_interface_msg::msg::SocketcanIF msg);
        void _subscriber_callback_Gyro(socketcan_interface_msg::msg::SocketcanIF msg);
        void _subscriber_callback_Quat(socketcan_interface_msg::msg::SocketcanIF msg);

    public:
        BNO055_IO_PUBLIC
        explicit Bno055Io(const rclcpp::NodeOptions& options = rclcpp::NodeOptions());

        BNO055_IO_PUBLIC
        explicit Bno055Io(const std::string& name_space, const rclcpp::NodeOptions& options = rclcpp::NodeOptions());
    };

}  // namespace bno055_io

#endif  // BNO055_IO__BNO055_IO_NODE_HPP_
