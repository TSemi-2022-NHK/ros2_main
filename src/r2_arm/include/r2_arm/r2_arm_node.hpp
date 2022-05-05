#ifndef R2_ARM__R2_ARM_NODE_HPP_
#define R2_ARM__R2_ARM_NODE_HPP_

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <chrono>
#include <regex>

#include "r2_arm/visibility_control.h"
#include "utilities/json11.hpp"
#include "utilities/can_utils.hpp"
#include "socketcan_interface_msg/msg/socketcan_if.hpp"

namespace r2_arm {

    class R2ArmNode : public rclcpp::Node {
    private:

        int arm_open_shut_movement = 0; //0:stop, 1:open, -1or2:close
        int arm_rotating_movement = 0;  //0:stop, 1:cw, 2:ccw
        int arm_up_down_movement = 0;   //0:stop, 1:up, -1or2:down
        int arm_front_or_back = 0;  //0:nothing, 1:front, 2:back

        bool arm_cw_flag = false;
        bool arm_ccw_flag = false;
        bool arm_stop_flag = false;

        bool arm_front = false;
        bool arm_back = false;

        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr _subscriber;
        rclcpp::QoS _qos = rclcpp::ServicesQoS();

        void _subscriber_callback(std_msgs::msg::String msg);

        rclcpp::TimerBase::SharedPtr _pub_timer;
        rclcpp::Publisher<socketcan_interface_msg::msg::SocketcanIF>::SharedPtr _publisher;
        rclcpp::QoS _qos_can = rclcpp::QoS(10).keep_all();
        void _publisher_callback();

    public:
        R2_ARM_PUBLIC
        R2ArmNode(const rclcpp::NodeOptions &options = rclcpp::NodeOptions());

        RCLCPP_PUBLIC
        R2ArmNode(const std::string &name_space,
                  const rclcpp::NodeOptions &options = rclcpp::NodeOptions());

    };

}  // namespace r2_arm

#endif  // R2_ARM__R2_ARM_NODE_HPP_
