#ifndef BNO055_IO__BNO055_IO_NODE_HPP_
#define BNO055_IO__BNO055_IO_NODE_HPP_

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/imu.hpp>

#include "bno055_io/visibility_control.h"
#include "socketcan_interface_msg/msg/socketcan_if.hpp"
#include "visibility_control.h"

#define AccelX_CanId 0x0312
#define AccelY_CanId 0x0313
#define AccelZ_CanId 0x0314

#define GyroX_CanId 0x0322
#define GyroY_CanId 0x0323
#define GyroZ_CanId 0x0324

#define QuatX_CanId 0x0332
#define QuatY_CanId 0x0333
#define QuatZ_CanId 0x0334
#define QuatW_CanId 0x0335


namespace bno055_io {

    class Bno055Io : public rclcpp::Node {
    private:

        bool Axinit, AyInit, AzInit, GxInit, GyInit, GzInit, QxInit, QyInit, QzInit, QwInit;

        rclcpp::Subscription<socketcan_interface_msg::msg::SocketcanIF>::SharedPtr _subscriber_AccelX;
        rclcpp::Subscription<socketcan_interface_msg::msg::SocketcanIF>::SharedPtr _subscriber_AccelY;
        rclcpp::Subscription<socketcan_interface_msg::msg::SocketcanIF>::SharedPtr _subscriber_AccelZ;
        rclcpp::Subscription<socketcan_interface_msg::msg::SocketcanIF>::SharedPtr _subscriber_GyroX;
        rclcpp::Subscription<socketcan_interface_msg::msg::SocketcanIF>::SharedPtr _subscriber_GyroY;
        rclcpp::Subscription<socketcan_interface_msg::msg::SocketcanIF>::SharedPtr _subscriber_GyroZ;
        rclcpp::Subscription<socketcan_interface_msg::msg::SocketcanIF>::SharedPtr _subscriber_QuatX;
        rclcpp::Subscription<socketcan_interface_msg::msg::SocketcanIF>::SharedPtr _subscriber_QuatY;
        rclcpp::Subscription<socketcan_interface_msg::msg::SocketcanIF>::SharedPtr _subscriber_QuatZ;
        rclcpp::Subscription<socketcan_interface_msg::msg::SocketcanIF>::SharedPtr _subscriber_QuatW;

        rclcpp::TimerBase::SharedPtr _pub_timer;

        rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr bno055_imu_publisher;

        std::shared_ptr<sensor_msgs::msg::Imu> imu_msg;
        rclcpp::QoS _qos = rclcpp::QoS(1).best_effort();

        void _publisher_callback();

        void _subscriber_callback_AccelX(socketcan_interface_msg::msg::SocketcanIF msg);
        void _subscriber_callback_AccelY(socketcan_interface_msg::msg::SocketcanIF msg);
        void _subscriber_callback_AccelZ(socketcan_interface_msg::msg::SocketcanIF msg);
        void _subscriber_callback_GyroX(socketcan_interface_msg::msg::SocketcanIF msg);
        void _subscriber_callback_GyroY(socketcan_interface_msg::msg::SocketcanIF msg);
        void _subscriber_callback_GyroZ(socketcan_interface_msg::msg::SocketcanIF msg);
        void _subscriber_callback_QuatX(socketcan_interface_msg::msg::SocketcanIF msg);
        void _subscriber_callback_QuatY(socketcan_interface_msg::msg::SocketcanIF msg);
        void _subscriber_callback_QuatZ(socketcan_interface_msg::msg::SocketcanIF msg);
        void _subscriber_callback_QuatW(socketcan_interface_msg::msg::SocketcanIF msg);

    public:
        BNO055_IO_PUBLIC
        explicit Bno055Io(const rclcpp::NodeOptions& options = rclcpp::NodeOptions());

        BNO055_IO_PUBLIC
        explicit Bno055Io(const std::string& name_space, const rclcpp::NodeOptions& options = rclcpp::NodeOptions());
    };

}  // namespace bno055_io

#endif  // BNO055_IO__BNO055_IO_NODE_HPP_
