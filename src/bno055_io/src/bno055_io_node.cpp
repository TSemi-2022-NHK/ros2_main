#include "bno055_io/bno055_io_node.hpp"

namespace bno055_io {

    Bno055Io::Bno055Io(const rclcpp::NodeOptions &options) : Bno055Io("", options){}

    Bno055Io::Bno055Io(const std::string &name_space, const rclcpp::NodeOptions &options) : rclcpp::Node(
            "socket_can_node", options) {
    }


}  // namespace bno055_io
