// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from socketcan_interface_msg:msg/SocketcanIF.idl
// generated code does not contain a copyright notice
#include "socketcan_interface_msg/msg/detail/socketcan_if__rosidl_typesupport_fastrtps_cpp.hpp"
#include "socketcan_interface_msg/msg/detail/socketcan_if__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: canid
  cdr << ros_message.canid;
  // Member: candlc
  cdr << ros_message.candlc;
  // Member: candata
  {
    cdr << ros_message.candata;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_socketcan_interface_msg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  socketcan_interface_msg::msg::SocketcanIF & ros_message)
{
  // Member: canid
  cdr >> ros_message.canid;

  // Member: candlc
  cdr >> ros_message.candlc;

  // Member: candata
  {
    cdr >> ros_message.candata;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_socketcan_interface_msg
get_serialized_size(
  const socketcan_interface_msg::msg::SocketcanIF & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: canid
  {
    size_t item_size = sizeof(ros_message.canid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: candlc
  {
    size_t item_size = sizeof(ros_message.candlc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: candata
  {
    size_t array_size = 8;
    size_t item_size = sizeof(ros_message.candata[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_socketcan_interface_msg
max_serialized_size_SocketcanIF(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: canid
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: candlc
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: candata
  {
    size_t array_size = 8;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _SocketcanIF__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const socketcan_interface_msg::msg::SocketcanIF *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SocketcanIF__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<socketcan_interface_msg::msg::SocketcanIF *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SocketcanIF__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const socketcan_interface_msg::msg::SocketcanIF *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SocketcanIF__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_SocketcanIF(full_bounded, 0);
}

static message_type_support_callbacks_t _SocketcanIF__callbacks = {
  "socketcan_interface_msg::msg",
  "SocketcanIF",
  _SocketcanIF__cdr_serialize,
  _SocketcanIF__cdr_deserialize,
  _SocketcanIF__get_serialized_size,
  _SocketcanIF__max_serialized_size
};

static rosidl_message_type_support_t _SocketcanIF__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SocketcanIF__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace socketcan_interface_msg

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_socketcan_interface_msg
const rosidl_message_type_support_t *
get_message_type_support_handle<socketcan_interface_msg::msg::SocketcanIF>()
{
  return &socketcan_interface_msg::msg::typesupport_fastrtps_cpp::_SocketcanIF__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, socketcan_interface_msg, msg, SocketcanIF)() {
  return &socketcan_interface_msg::msg::typesupport_fastrtps_cpp::_SocketcanIF__handle;
}

#ifdef __cplusplus
}
#endif
