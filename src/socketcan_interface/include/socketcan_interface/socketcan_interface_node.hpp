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

        rclcpp::QoS _qos = rclcpp::QoS(40).keep_all();

        void _publisher_callback();
        void _subscriber_callback(socketcan_interface_msg::msg::SocketcanIF msg);
    public:
        SOCKETCAN_INTERFACE_PUBLIC
        explicit SocketcanInterface(const rclcpp::NodeOptions& options = rclcpp::NodeOptions());

        SOCKETCAN_INTERFACE_PUBLIC
        explicit SocketcanInterface(const std::string& name_space, const rclcpp::NodeOptions& options = rclcpp::NodeOptions());
    };
}


#endif //BUILD_SOCKETCAN_INTERFACE_NODE_HPP
