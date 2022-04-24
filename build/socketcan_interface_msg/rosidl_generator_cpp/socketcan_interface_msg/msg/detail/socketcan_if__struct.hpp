// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from socketcan_interface_msg:msg/SocketcanIF.idl
// generated code does not contain a copyright notice

#ifndef SOCKETCAN_INTERFACE_MSG__MSG__DETAIL__SOCKETCAN_IF__STRUCT_HPP_
#define SOCKETCAN_INTERFACE_MSG__MSG__DETAIL__SOCKETCAN_IF__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__socketcan_interface_msg__msg__SocketcanIF __attribute__((deprecated))
#else
# define DEPRECATED__socketcan_interface_msg__msg__SocketcanIF __declspec(deprecated)
#endif

namespace socketcan_interface_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SocketcanIF_
{
  using Type = SocketcanIF_<ContainerAllocator>;

  explicit SocketcanIF_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->canid = 0;
      this->candlc = 0;
      std::fill<typename std::array<uint8_t, 8>::iterator, uint8_t>(this->candata.begin(), this->candata.end(), 0);
    }
  }

  explicit SocketcanIF_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : candata(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->canid = 0;
      this->candlc = 0;
      std::fill<typename std::array<uint8_t, 8>::iterator, uint8_t>(this->candata.begin(), this->candata.end(), 0);
    }
  }

  // field types and members
  using _canid_type =
    int16_t;
  _canid_type canid;
  using _candlc_type =
    uint8_t;
  _candlc_type candlc;
  using _candata_type =
    std::array<uint8_t, 8>;
  _candata_type candata;

  // setters for named parameter idiom
  Type & set__canid(
    const int16_t & _arg)
  {
    this->canid = _arg;
    return *this;
  }
  Type & set__candlc(
    const uint8_t & _arg)
  {
    this->candlc = _arg;
    return *this;
  }
  Type & set__candata(
    const std::array<uint8_t, 8> & _arg)
  {
    this->candata = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    socketcan_interface_msg::msg::SocketcanIF_<ContainerAllocator> *;
  using ConstRawPtr =
    const socketcan_interface_msg::msg::SocketcanIF_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<socketcan_interface_msg::msg::SocketcanIF_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<socketcan_interface_msg::msg::SocketcanIF_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      socketcan_interface_msg::msg::SocketcanIF_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<socketcan_interface_msg::msg::SocketcanIF_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      socketcan_interface_msg::msg::SocketcanIF_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<socketcan_interface_msg::msg::SocketcanIF_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<socketcan_interface_msg::msg::SocketcanIF_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<socketcan_interface_msg::msg::SocketcanIF_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__socketcan_interface_msg__msg__SocketcanIF
    std::shared_ptr<socketcan_interface_msg::msg::SocketcanIF_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__socketcan_interface_msg__msg__SocketcanIF
    std::shared_ptr<socketcan_interface_msg::msg::SocketcanIF_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SocketcanIF_ & other) const
  {
    if (this->canid != other.canid) {
      return false;
    }
    if (this->candlc != other.candlc) {
      return false;
    }
    if (this->candata != other.candata) {
      return false;
    }
    return true;
  }
  bool operator!=(const SocketcanIF_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SocketcanIF_

// alias to use template instance with default allocator
using SocketcanIF =
  socketcan_interface_msg::msg::SocketcanIF_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace socketcan_interface_msg

#endif  // SOCKETCAN_INTERFACE_MSG__MSG__DETAIL__SOCKETCAN_IF__STRUCT_HPP_
