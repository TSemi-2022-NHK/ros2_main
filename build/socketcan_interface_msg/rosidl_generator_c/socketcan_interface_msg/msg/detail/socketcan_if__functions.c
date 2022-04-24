// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from socketcan_interface_msg:msg/SocketcanIF.idl
// generated code does not contain a copyright notice
#include "socketcan_interface_msg/msg/detail/socketcan_if__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
socketcan_interface_msg__msg__SocketcanIF__init(socketcan_interface_msg__msg__SocketcanIF * msg)
{
  if (!msg) {
    return false;
  }
  // canid
  // candlc
  // candata
  return true;
}

void
socketcan_interface_msg__msg__SocketcanIF__fini(socketcan_interface_msg__msg__SocketcanIF * msg)
{
  if (!msg) {
    return;
  }
  // canid
  // candlc
  // candata
}

socketcan_interface_msg__msg__SocketcanIF *
socketcan_interface_msg__msg__SocketcanIF__create()
{
  socketcan_interface_msg__msg__SocketcanIF * msg = (socketcan_interface_msg__msg__SocketcanIF *)malloc(sizeof(socketcan_interface_msg__msg__SocketcanIF));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(socketcan_interface_msg__msg__SocketcanIF));
  bool success = socketcan_interface_msg__msg__SocketcanIF__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
socketcan_interface_msg__msg__SocketcanIF__destroy(socketcan_interface_msg__msg__SocketcanIF * msg)
{
  if (msg) {
    socketcan_interface_msg__msg__SocketcanIF__fini(msg);
  }
  free(msg);
}


bool
socketcan_interface_msg__msg__SocketcanIF__Sequence__init(socketcan_interface_msg__msg__SocketcanIF__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  socketcan_interface_msg__msg__SocketcanIF * data = NULL;
  if (size) {
    data = (socketcan_interface_msg__msg__SocketcanIF *)calloc(size, sizeof(socketcan_interface_msg__msg__SocketcanIF));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = socketcan_interface_msg__msg__SocketcanIF__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        socketcan_interface_msg__msg__SocketcanIF__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
socketcan_interface_msg__msg__SocketcanIF__Sequence__fini(socketcan_interface_msg__msg__SocketcanIF__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      socketcan_interface_msg__msg__SocketcanIF__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

socketcan_interface_msg__msg__SocketcanIF__Sequence *
socketcan_interface_msg__msg__SocketcanIF__Sequence__create(size_t size)
{
  socketcan_interface_msg__msg__SocketcanIF__Sequence * array = (socketcan_interface_msg__msg__SocketcanIF__Sequence *)malloc(sizeof(socketcan_interface_msg__msg__SocketcanIF__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = socketcan_interface_msg__msg__SocketcanIF__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
socketcan_interface_msg__msg__SocketcanIF__Sequence__destroy(socketcan_interface_msg__msg__SocketcanIF__Sequence * array)
{
  if (array) {
    socketcan_interface_msg__msg__SocketcanIF__Sequence__fini(array);
  }
  free(array);
}
