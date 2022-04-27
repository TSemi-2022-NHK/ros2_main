#ifndef BNO055_IO__BNO055_IO_NODE_HPP_
#define BNO055_IO__BNO055_IO_NODE_HPP_

#include <rclcpp/rclcpp.hpp>

#include "bno055_io/visibility_control.h"
#include "visibility_control.h"

namespace bno055_io {

    class Bno055Io : public rclcpp::Node {
    public:
        BNO055_IO_PUBLIC
        explicit Bno055Io(const rclcpp::NodeOptions& options = rclcpp::NodeOptions());

        BNO055_IO_PUBLIC
        explicit Bno055Io(const std::string& name_space, const rclcpp::NodeOptions& options = rclcpp::NodeOptions());
    };

}  // namespace bno055_io

#endif  // BNO055_IO__BNO055_IO_NODE_HPP_
