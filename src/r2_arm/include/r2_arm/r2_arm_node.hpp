#ifndef R2_ARM__R2_ARM_NODE_HPP_
#define R2_ARM__R2_ARM_NODE_HPP_

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include "r2_arm/visibility_control.h"
#include "utilities/json11.hpp"
#include "utilities/can_utils.hpp"
#include "socketcan_interface_msg/msg/socketcan_if.hpp"

namespace r2_arm {

    class R2ArmNode : public rclcpp::Node {
    public:
        R2_ARM_PUBLIC
        R2ArmNode(const rclcpp::NodeOptions &options = rclcpp::NodeOptions());

        RCLCPP_PUBLIC
        R2ArmNode(const std::string &name_space,
                  const rclcpp::NodeOptions &options = rclcpp::NodeOptions());

    };

}  // namespace r2_arm

#endif  // R2_ARM__R2_ARM_NODE_HPP_
