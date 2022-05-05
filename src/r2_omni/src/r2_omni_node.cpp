#include "r2_omni/r2_omni_node.hpp"

namespace r2_omni {

    R2OmniNode::R2OmniNode(const rclcpp::NodeOptions &options) : R2OmniNode("", options) {

    }

    R2OmniNode::R2OmniNode(const std::string &name_space, const rclcpp::NodeOptions &options) : Node(
            "R2_omni_node", options) {
        using namespace std::chrono_literals;

        declare_parameter("interval_ms", 50);
        auto interval_ms = this->get_parameter("interval_ms").as_int();

        for (double & i : omni_moter) {
            i = 0;
        }

        _publisher = this->create_publisher<socketcan_interface_msg::msg::SocketcanIF>("can_tx", _qos_can);
        _pub_timer = this->create_wall_timer(
                std::chrono::milliseconds(interval_ms),
                [this] { _publisher_callback(); }
        );
        _subscriber = this->create_subscription<std_msgs::msg::String>("joystick", _qos,
                                                                       std::bind(&R2OmniNode::_subscriber_callback,
                                                                                 this, std::placeholders::_1));
    }

    void R2OmniNode::_subscriber_callback(std_msgs::msg::String msg) {
        const std::string _string = std::regex_replace(msg.data, std::regex("\'"), "\"");
        std::string err;
        auto _json = json11::Json::parse(_string, err);
        int joy_rad = _json["joy_rad"].int_value();
        int joy_deg = _json["joy_deg"].int_value();
        RCLCPP_INFO(this->get_logger(), "joy_rad:%d, joy:deg:%d", joy_rad, joy_deg);
        int w = 0;
        wheel wheel;
        wheel.motor_main(joy_rad, joy_deg, w);
        for (int i = 0; i < 4; ++i) {
            omni_moter[i] = wheel.Motor[i];
        }
    }

    void R2OmniNode::_publisher_callback() {
        auto msg = std::make_shared<socketcan_interface_msg::msg::SocketcanIF>();
        uint8_t _tmp_bytes[4];

        msg->canid = 0x100;
        convert_float_to_byte(omni_moter[0], _tmp_bytes);
        for (int i = 0; i < 4; ++i) {
            msg->candata[i] = _tmp_bytes[i];
        }
        msg->candlc = 8;
        _publisher->publish(*msg);

        msg->canid = 0x101;
        convert_float_to_byte(omni_moter[1], _tmp_bytes);
        for (int i = 0; i < 4; ++i) {
            msg->candata[i] = _tmp_bytes[i];
        }
        msg->candlc = 8;
        _publisher->publish(*msg);

        msg->canid = 0x102;
        convert_float_to_byte(omni_moter[2], _tmp_bytes);
        for (int i = 0; i < 4; ++i) {
            msg->candata[i] = _tmp_bytes[i];
        }
        msg->candlc = 8;
        _publisher->publish(*msg);

        msg->canid = 0x103;
        convert_float_to_byte(omni_moter[3], _tmp_bytes);
        for (int i = 0; i < 4; ++i) {
            msg->candata[i] = _tmp_bytes[i];
        }
        msg->candlc = 8;
        _publisher->publish(*msg);
    }

    wheel::wheel() = default;

//速度[m/s]、行きたい方向[degree],機体の角速度[rad/s]を受け取り、最後に各タイヤの角速度[rad/s]を返す
    void wheel::motor_main(float v, float direction, float w){
        using namespace std;

        if (direction > 360) {
            direction = 360;
        }
        double x = v * cos((direction - 45)*Pi/180);
        double y = v * sin((direction - 45)*Pi/180);

        //角速度計算
        Motor[0] = y / (2 * r) + l * w / r;
        Motor[1] = -x / (2 * r) + l * w / r;
        Motor[2] = -y / (2 * r) + l * w / r;
        Motor[3] = x / (2 * r) + l * w / r;

        //各タイヤの各速度が定格rpmを上回らないようにする
        if (Motor[0] > 1926 ) {
            Motor[0] = 1800;
        }
        else if (Motor[0] < -1926){
            Motor[0] = -1800;
        }

        if (Motor[1] > 1926 ) {
            Motor[1] = 1800;
        }
        else if (Motor[1] < -1926){
            Motor[1] = -1800;
        }

        if (Motor[2] > 1926 ) {
            Motor[2] = 1800;
        }
        else if (Motor[2] < -1926){
            Motor[2] = -1800;
        }

        if (Motor[3] > 1926 ) {
            Motor[3] = 1800;
        }
        else if (Motor[3] < -1926){
            Motor[3] = -1800;
        }

    }

}  // namespace r2_omni
