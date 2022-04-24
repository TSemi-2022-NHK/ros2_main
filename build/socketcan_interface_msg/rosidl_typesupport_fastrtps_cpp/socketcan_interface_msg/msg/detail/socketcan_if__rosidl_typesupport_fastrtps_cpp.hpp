// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from socketcan_interface_msg:msg/SocketcanIF.idl
// generated code does not contain a copyright notice

#ifndef SOCKETCAN_INTERFACE_MSG__MSG__DETAIL__SOCKETCAN_IF__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define SOCKETCAN_INTERFACE_MSG__MSG__DETAIL__SOCKETCAN_IF__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "socketcan_interface_msg/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "socketcan_interface_msg/msg/detail/socketcan_if__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace socketcan_interface_msg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_socketcan_interface_msg
cdr_serialize(
  const socketcan_interface_msg::msg::SocketcanIF & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_socketcan_interface_msg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  socketcan_interface_msg::msg::SocketcanIF & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_socketcan_interface_msg
get_serialized_size(
  const socketcan_interface_msg::msg::SocketcanIF & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_socketcan_interface_msg
max_serialized_size_SocketcanIF(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace socketcan_interface_msg

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_socketcan_interface_msg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, socketcan_interface_msg, msg, SocketcanIF)();

#ifdef __cplusplus
}
#endif

#endif  // SOCKETCAN_INTERFACE_MSG__MSG__DETAIL__SOCKETCAN_IF__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
