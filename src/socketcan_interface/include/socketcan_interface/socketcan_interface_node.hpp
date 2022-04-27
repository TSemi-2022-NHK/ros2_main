//
// Created by ryuzo on 2022/04/15.
//

#ifndef BUILD_SOCKETCAN_INTERFACE_NODE_HPP
#define BUILD_SOCKETCAN_INTERFACE_NODE_HPP

#include <rclcpp/rclcpp.hpp>
#include <vector>
#include <net/if.h>
#include <sys/socket.h>

#include <linux/can.h>

#include "socketcan_interface_msg/msg/socketcan_if.hpp"
#include "visibility.h"

namespace socketcan_interface {

    class SocketcanInterface : public rclcpp::Node {
    private:
        rclcpp::Subscription<socketcan_interface_msg::msg::SocketcanIF>::SharedPtr _subscription;
        rclcpp::TimerBase::SharedPtr _pub_timer;

        std::map<uint16_t, rclcpp::Publisher<socketcan_interface_msg::msg::SocketcanIF>::SharedPtr> known_id_rx_publisher;
        struct sockaddr_can addr{};
        struct ifreq ifr{};
        int s;

        rclcpp::QoS _qos = rclcpp::QoS(10).keep_all();

        void _publisher_callback();
        void _subscriber_callback(socketcan_interface_msg::msg::SocketcanIF msg);
    public:
        SOCKETCAN_INTERFACE_PUBLIC
        explicit SocketcanInterface(const rclcpp::NodeOptions& options = rclcpp::NodeOptions());

        SOCKETCAN_INTERFACE_PUBLIC
        explicit SocketcanInterface(const std::string& name_space, const rclcpp::NodeOptions& options = rclcpp::NodeOptions());
    };
}

namespace can_utils{
    double convert_byte_to_double(uint8_t (&bytes)[8]);
    float convert_byte_to_float(uint8_t (&bytes)[4]);
    void convert_float_to_byte(float data, uint8_t (&bytes)[4]);
    void convert_double_to_byte(double data, uint8_t (&bytes)[8]);
}


#endif //BUILD_SOCKETCAN_INTERFACE_NODE_HPP
