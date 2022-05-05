#include "r2_arm/r2_arm_node.hpp"

namespace r2_arm
{


    R2ArmNode::R2ArmNode(const rclcpp::NodeOptions &options): R2ArmNode("", options) {

    }

    R2ArmNode::R2ArmNode(const std::string &name_space, const rclcpp::NodeOptions &options) : Node(
            "R2_arm_node", options) {

    }
}  // namespace r2_arm
