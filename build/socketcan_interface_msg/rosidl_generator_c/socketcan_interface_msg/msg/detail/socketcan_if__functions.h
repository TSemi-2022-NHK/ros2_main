// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from socketcan_interface_msg:msg/SocketcanIF.idl
// generated code does not contain a copyright notice

#ifndef SOCKETCAN_INTERFACE_MSG__MSG__DETAIL__SOCKETCAN_IF__FUNCTIONS_H_
#define SOCKETCAN_INTERFACE_MSG__MSG__DETAIL__SOCKETCAN_IF__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "socketcan_interface_msg/msg/rosidl_generator_c__visibility_control.h"

#include "socketcan_interface_msg/msg/detail/socketcan_if__struct.h"

/// Initialize msg/SocketcanIF message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * socketcan_interface_msg__msg__SocketcanIF
 * )) before or use
 * socketcan_interface_msg__msg__SocketcanIF__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_socketcan_interface_msg
bool
socketcan_interface_msg__msg__SocketcanIF__init(socketcan_interface_msg__msg__SocketcanIF * msg);

/// Finalize msg/SocketcanIF message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_socketcan_interface_msg
void
socketcan_interface_msg__msg__SocketcanIF__fini(socketcan_interface_msg__msg__SocketcanIF * msg);

/// Create msg/SocketcanIF message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * socketcan_interface_msg__msg__SocketcanIF__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_socketcan_interface_msg
socketcan_interface_msg__msg__SocketcanIF *
socketcan_interface_msg__msg__SocketcanIF__create();

/// Destroy msg/SocketcanIF message.
/**
 * It calls
 * socketcan_interface_msg__msg__SocketcanIF__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_socketcan_interface_msg
void
socketcan_interface_msg__msg__SocketcanIF__destroy(socketcan_interface_msg__msg__SocketcanIF * msg);


/// Initialize array of msg/SocketcanIF messages.
/**
 * It allocates the memory for the number of elements and calls
 * socketcan_interface_msg__msg__SocketcanIF__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_socketcan_interface_msg
bool
socketcan_interface_msg__msg__SocketcanIF__Sequence__init(socketcan_interface_msg__msg__SocketcanIF__Sequence * array, size_t size);

/// Finalize array of msg/SocketcanIF messages.
/**
 * It calls
 * socketcan_interface_msg__msg__SocketcanIF__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_socketcan_interface_msg
void
socketcan_interface_msg__msg__SocketcanIF__Sequence__fini(socketcan_interface_msg__msg__SocketcanIF__Sequence * array);

/// Create array of msg/SocketcanIF messages.
/**
 * It allocates the memory for the array and calls
 * socketcan_interface_msg__msg__SocketcanIF__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_socketcan_interface_msg
socketcan_interface_msg__msg__SocketcanIF__Sequence *
socketcan_interface_msg__msg__SocketcanIF__Sequence__create(size_t size);

/// Destroy array of msg/SocketcanIF messages.
/**
 * It calls
 * socketcan_interface_msg__msg__SocketcanIF__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_socketcan_interface_msg
void
socketcan_interface_msg__msg__SocketcanIF__Sequence__destroy(socketcan_interface_msg__msg__SocketcanIF__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // SOCKETCAN_INTERFACE_MSG__MSG__DETAIL__SOCKETCAN_IF__FUNCTIONS_H_
