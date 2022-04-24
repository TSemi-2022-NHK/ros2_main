// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from socketcan_interface_msg:msg/SocketcanIF.idl
// generated code does not contain a copyright notice

#ifndef SOCKETCAN_INTERFACE_MSG__MSG__DETAIL__SOCKETCAN_IF__STRUCT_H_
#define SOCKETCAN_INTERFACE_MSG__MSG__DETAIL__SOCKETCAN_IF__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/SocketcanIF in the package socketcan_interface_msg.
typedef struct socketcan_interface_msg__msg__SocketcanIF
{
  int16_t canid;
  uint8_t candlc;
  uint8_t candata[8];
} socketcan_interface_msg__msg__SocketcanIF;

// Struct for a sequence of socketcan_interface_msg__msg__SocketcanIF.
typedef struct socketcan_interface_msg__msg__SocketcanIF__Sequence
{
  socketcan_interface_msg__msg__SocketcanIF * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} socketcan_interface_msg__msg__SocketcanIF__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SOCKETCAN_INTERFACE_MSG__MSG__DETAIL__SOCKETCAN_IF__STRUCT_H_
