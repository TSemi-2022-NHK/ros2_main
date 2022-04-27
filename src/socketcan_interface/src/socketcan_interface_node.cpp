//
// Created by ryuzo on 2022/04/15.
//
#include <rclcpp/rclcpp.hpp>
#include <net/if.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <linux/can.h>
#include <cerrno>
#include <fcntl.h>
#include <cstdio>

#include "socketcan_interface/socketcan_interface_node.hpp"
#include "socketcan_interface_msg/msg/socketcan_if.hpp"

namespace socketcan_interface {

    SocketcanInterface::SocketcanInterface(const rclcpp::NodeOptions &options) : SocketcanInterface("", options) {}

    SocketcanInterface::SocketcanInterface(const std::string &name_space, const rclcpp::NodeOptions &options)
            : rclcpp::Node("socket_can_node", options) {
        using namespace std::chrono_literals;

        declare_parameter("interval_ms", 1);
        auto interval_ms = this->get_parameter("interval_ms").as_int();

        if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
            perror("Socket");
            RCLCPP_ERROR(this->get_logger(), "Socket error");
        }

        strcpy(ifr.ifr_name, "vcan0");
        ioctl(s, SIOCGIFINDEX, &ifr);

        memset(&addr, 0, sizeof(addr));
        addr.can_family = AF_CAN;
        addr.can_ifindex = ifr.ifr_ifindex;

        if (bind(s, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
            perror("Bind");
            RCLCPP_ERROR(this->get_logger(), "Bind error");
        }

        if (fcntl(s, F_SETFL, O_NONBLOCK) < 0) {    //Set can socket to non-blocking mode.
            perror("Setting");
            RCLCPP_ERROR(this->get_logger(), "Can setting error");
        }


        _pub_timer = this->create_wall_timer(
                std::chrono::milliseconds(interval_ms),
                [this] { _publisher_callback(); }
        );
        _subscription = this->create_subscription<socketcan_interface_msg::msg::SocketcanIF>(
                "can_tx",
                _qos,
                std::bind(&SocketcanInterface::_subscriber_callback, this, std::placeholders::_1)
        );

    }

    void SocketcanInterface::_publisher_callback() {
        auto msg = std::make_shared<socketcan_interface_msg::msg::SocketcanIF>();

        int nbytes;
        struct can_frame frame{};
        errno = 0;

        while (true) {
            nbytes = read(s, &frame, sizeof(struct can_frame));
            if (nbytes < 0) {
                if (errno !=
                    (EAGAIN | EWOULDBLOCK)) {   // these errors occur when nothing can be read in non-blocking mode.
                    RCLCPP_ERROR(this->get_logger(), "Unexpected read error.");
                }
                break;
            }
            RCLCPP_INFO(this->get_logger(), "Published ID:0x%03X [%d] ", frame.can_id, frame.can_dlc);
            msg->canid = frame.can_id;
            msg->candlc = frame.can_dlc;
            for (int i = 0; i < frame.can_dlc; i++) {
                msg->candata[i] = frame.data[i];
            }

            if (known_id_rx_publisher.find(frame.can_id) == known_id_rx_publisher.end()) {
                known_id_rx_publisher[frame.can_id] = this->create_publisher<socketcan_interface_msg::msg::SocketcanIF>(
                        std::string("can_rx_" + std::to_string(frame.can_id)), _qos);
            }
            known_id_rx_publisher[frame.can_id]->publish(*msg);
        }
    }

    void SocketcanInterface::_subscriber_callback(const socketcan_interface_msg::msg::SocketcanIF msg) {
        struct can_frame frame{};

        frame.can_id = msg.canid;
        if ((msg.candlc > 0) and (msg.candlc <= 9)) {
            frame.can_dlc = msg.candlc;
        } else {
            frame.can_dlc = 8;
        }
        std::string can_data_print;
        for (int i = 0; i < frame.can_dlc; ++i) {
            frame.data[i] = msg.candata[i];

            char str[64];
            sprintf(str, "0x%03X, ", msg.candata[i]);
            can_data_print = can_data_print + str;
        }
        RCLCPP_INFO(this->get_logger(), "Sending to can bus ID: 0x%03X, can data: %s", msg.canid, can_data_print.c_str());

        if (write(s, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
            perror("Write frame0");
            RCLCPP_ERROR(this->get_logger(), "Write error");
        }
    }
}

namespace can_utils{
    double convert_byte_to_double(uint8_t (&bytes)[8]) {
        union {
            uint8_t bytes[8];
            double data;
        }Data{};
        for (int i = 0; i < 8; ++i) {
            Data.bytes[i] = bytes[i];
        }
        return Data.data;
    }

    float convert_byte_to_float(uint8_t (&bytes)[4]) {
        union {
            uint8_t bytes[4];
            float data;
        }Data{};
        for (int i = 0; i < 4; ++i) {
            Data.bytes[i] = bytes[i];
        }
        return Data.data;
    }

    void convert_float_to_byte(float data, uint8_t (&bytes)[4]) {
        union {
            uint8_t bytes[4];
            float data;
        }Data{};
        Data.data = data;
        for (int i = 0; i < 4; ++i) {
            bytes[i] = Data.bytes[i];
        }
    }

    void convert_double_to_byte(double data, uint8_t (&bytes)[8]) {
        union {
            uint8_t bytes[8];
            double data;
        }Data{};
        Data.data = data;
        for (int i = 0; i < 8; ++i) {
            bytes[i] = Data.bytes[i];
        }
    }
}