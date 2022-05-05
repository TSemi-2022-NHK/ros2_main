#include "r2_arm/r2_arm_node.hpp"

namespace r2_arm
{


    R2ArmNode::R2ArmNode(const rclcpp::NodeOptions &options): R2ArmNode("", options) {

    }

    R2ArmNode::R2ArmNode(const std::string &name_space, const rclcpp::NodeOptions &options) : Node(
            "R2_arm_node", options) {
        using namespace std::chrono_literals;

        declare_parameter("interval_ms", 100);
        auto interval_ms = this->get_parameter("interval_ms").as_int();

        _publisher = this->create_publisher<socketcan_interface_msg::msg::SocketcanIF>("can_tx", _qos_can);
        _pub_timer = this->create_wall_timer(
                std::chrono::milliseconds(interval_ms),
                [this] { _publisher_callback(); }
        );
        _subscriber = this->create_subscription<std_msgs::msg::String>("joystick", _qos,
                                                                       std::bind(&R2ArmNode::_subscriber_callback,
                                                                                 this, std::placeholders::_1));
    }

    void R2ArmNode::_subscriber_callback(std_msgs::msg::String msg) {
        const std::string _string = std::regex_replace(msg.data, std::regex("\'"), "\"");
        std::string err;
        auto _json = json11::Json::parse(_string, err);

        arm_open_shut_movement = _json["hat_x"].int_value();
        arm_up_down_movement = _json["hat_y"].int_value();

        arm_cw_flag = _json["btn_b"].int_value();
        arm_ccw_flag = _json["btn_x"].int_value();
        arm_stop_flag = not(arm_ccw_flag and arm_cw_flag);
        if (arm_stop_flag){
            arm_rotating_movement = 0;
        } else if (arm_cw_flag){
            arm_rotating_movement = 1;
        } else if (arm_ccw_flag){
            arm_rotating_movement = 2;
        }

        arm_front = _json["btn_y"].int_value();
        arm_back = _json["btn_a"].int_value();

        if (arm_front and not arm_back){
            arm_front_or_back = 1;
        } else if(not arm_front and arm_back){
            arm_front_or_back = 2;
        } else{
            arm_front_or_back = 0;
        }
    }

    void R2ArmNode::_publisher_callback() {
        auto msg = std::make_shared<socketcan_interface_msg::msg::SocketcanIF>();

        msg->canid = 0x611;
        msg->candlc = 1;
        if (arm_open_shut_movement == -1){
            arm_open_shut_movement = 2;
        }
        msg->candata[0] = arm_open_shut_movement;
        _publisher->publish(*msg);

        msg->canid = 0x612;
        msg->candlc = 1;
        if (arm_up_down_movement == -1){
            arm_up_down_movement = 2;
        }
        msg->candata[0] = arm_up_down_movement;
        _publisher->publish(*msg);

        /*msg->canid = 0x613;
        msg->candlc = 2;
        msg->candata[0] = arm_front_or_back;
        msg->candata[1] = arm_rotating_movement;
        _publisher->publish(*msg);
        */
    }
}  // namespace r2_arm
