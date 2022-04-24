// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from socketcan_interface_msg:msg/SocketcanIF.idl
// generated code does not contain a copyright notice

#ifndef SOCKETCAN_INTERFACE_MSG__MSG__DETAIL__SOCKETCAN_IF__BUILDER_HPP_
#define SOCKETCAN_INTERFACE_MSG__MSG__DETAIL__SOCKETCAN_IF__BUILDER_HPP_

#include "socketcan_interface_msg/msg/detail/socketcan_if__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace socketcan_interface_msg
{

namespace msg
{

namespace builder
{

class Init_SocketcanIF_candata
{
public:
  explicit Init_SocketcanIF_candata(::socketcan_interface_msg::msg::SocketcanIF & msg)
  : msg_(msg)
  {}
  ::socketcan_interface_msg::msg::SocketcanIF candata(::socketcan_interface_msg::msg::SocketcanIF::_candata_type arg)
  {
    msg_.candata = std::move(arg);
    return std::move(msg_);
  }

private:
  ::socketcan_interface_msg::msg::SocketcanIF msg_;
};

class Init_SocketcanIF_candlc
{
public:
  explicit Init_SocketcanIF_candlc(::socketcan_interface_msg::msg::SocketcanIF & msg)
  : msg_(msg)
  {}
  Init_SocketcanIF_candata candlc(::socketcan_interface_msg::msg::SocketcanIF::_candlc_type arg)
  {
    msg_.candlc = std::move(arg);
    return Init_SocketcanIF_candata(msg_);
  }

private:
  ::socketcan_interface_msg::msg::SocketcanIF msg_;
};

class Init_SocketcanIF_canid
{
public:
  Init_SocketcanIF_canid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SocketcanIF_candlc canid(::socketcan_interface_msg::msg::SocketcanIF::_canid_type arg)
  {
    msg_.canid = std::move(arg);
    return Init_SocketcanIF_candlc(msg_);
  }

private:
  ::socketcan_interface_msg::msg::SocketcanIF msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::socketcan_interface_msg::msg::SocketcanIF>()
{
  return socketcan_interface_msg::msg::builder::Init_SocketcanIF_canid();
}

}  // namespace socketcan_interface_msg

#endif  // SOCKETCAN_INTERFACE_MSG__MSG__DETAIL__SOCKETCAN_IF__BUILDER_HPP_
