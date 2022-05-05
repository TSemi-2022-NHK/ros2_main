#ifndef R2_OMNI__R2_OMNI_NODE_HPP_
#define R2_OMNI__R2_OMNI_NODE_HPP_

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <chrono>
#include <regex>
#include <cmath>

#include "r2_omni/visibility_control.h"
#include "utilities/json11.hpp"
#include "utilities/can_utils.hpp"
#include "socketcan_interface_msg/msg/socketcan_if.hpp"

#define  Pi 3.14159265

namespace r2_omni{

    class R2OmniNode : public rclcpp::Node {
    private:

        double omni_moter[4];

        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr _subscriber;
        rclcpp::QoS _qos = rclcpp::ServicesQoS();

        void _subscriber_callback(std_msgs::msg::String msg);

        rclcpp::TimerBase::SharedPtr _pub_timer;
        rclcpp::Publisher<socketcan_interface_msg::msg::SocketcanIF>::SharedPtr _publisher;
        rclcpp::QoS _qos_can = rclcpp::QoS(40).keep_all();
        void _publisher_callback();

    public:
        R2_OMNI_PUBLIC
        R2OmniNode(const rclcpp::NodeOptions &options = rclcpp::NodeOptions());

        R2_OMNI_PUBLIC
        R2OmniNode(const std::string &name_space,
                   const rclcpp::NodeOptions &options = rclcpp::NodeOptions());
    };

    class wheel {
    public:
        wheel();
        double Motor[4]{};//各タイヤの各速度
        void motor_main(float v, float direction, float w);

    private:
        double l = 0.3;//機体中心から各タイヤまでの距離[m]
        double r = 0.08;//タイヤの半径[m]
    };

}  // namespace r2_omni

#endif  // R2_OMNI__R2_OMNI_NODE_HPP_
