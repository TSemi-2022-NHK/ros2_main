// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from socketcan_interface_msg:msg/SocketcanIF.idl
// generated code does not contain a copyright notice
#include "socketcan_interface_msg/msg/detail/socketcan_if__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "socketcan_interface_msg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "socketcan_interface_msg/msg/detail/socketcan_if__struct.h"
#include "socketcan_interface_msg/msg/detail/socketcan_if__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _SocketcanIF__ros_msg_type = socketcan_interface_msg__msg__SocketcanIF;

static bool _SocketcanIF__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SocketcanIF__ros_msg_type * ros_message = static_cast<const _SocketcanIF__ros_msg_type *>(untyped_ros_message);
  // Field name: canid
  {
    cdr << ros_message->canid;
  }

  // Field name: candlc
  {
    cdr << ros_message->candlc;
  }

  // Field name: candata
  {
    size_t size = 8;
    auto array_ptr = ros_message->candata;
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _SocketcanIF__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SocketcanIF__ros_msg_type * ros_message = static_cast<_SocketcanIF__ros_msg_type *>(untyped_ros_message);
  // Field name: canid
  {
    cdr >> ros_message->canid;
  }

  // Field name: candlc
  {
    cdr >> ros_message->candlc;
  }

  // Field name: candata
  {
    size_t size = 8;
    auto array_ptr = ros_message->candata;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_socketcan_interface_msg
size_t get_serialized_size_socketcan_interface_msg__msg__SocketcanIF(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SocketcanIF__ros_msg_type * ros_message = static_cast<const _SocketcanIF__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name canid
  {
    size_t item_size = sizeof(ros_message->canid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name candlc
  {
    size_t item_size = sizeof(ros_message->candlc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name candata
  {
    size_t array_size = 8;
    auto array_ptr = ros_message->candata;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SocketcanIF__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_socketcan_interface_msg__msg__SocketcanIF(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_socketcan_interface_msg
size_t max_serialized_size_socketcan_interface_msg__msg__SocketcanIF(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: canid
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: candlc
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: candata
  {
    size_t array_size = 8;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _SocketcanIF__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_socketcan_interface_msg__msg__SocketcanIF(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_SocketcanIF = {
  "socketcan_interface_msg::msg",
  "SocketcanIF",
  _SocketcanIF__cdr_serialize,
  _SocketcanIF__cdr_deserialize,
  _SocketcanIF__get_serialized_size,
  _SocketcanIF__max_serialized_size
};

static rosidl_message_type_support_t _SocketcanIF__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SocketcanIF,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, socketcan_interface_msg, msg, SocketcanIF)() {
  return &_SocketcanIF__type_support;
}

#if defined(__cplusplus)
}
#endif
