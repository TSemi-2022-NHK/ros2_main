// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from socketcan_interface_msg:msg/SocketcanIF.idl
// generated code does not contain a copyright notice

#ifndef SOCKETCAN_INTERFACE_MSG__MSG__DETAIL__SOCKETCAN_IF__TRAITS_HPP_
#define SOCKETCAN_INTERFACE_MSG__MSG__DETAIL__SOCKETCAN_IF__TRAITS_HPP_

#include "socketcan_interface_msg/msg/detail/socketcan_if__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const socketcan_interface_msg::msg::SocketcanIF & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: canid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "canid: ";
    value_to_yaml(msg.canid, out);
    out << "\n";
  }

  // member: candlc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "candlc: ";
    value_to_yaml(msg.candlc, out);
    out << "\n";
  }

  // member: candata
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.candata.size() == 0) {
      out << "candata: []\n";
    } else {
      out << "candata:\n";
      for (auto item : msg.candata) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const socketcan_interface_msg::msg::SocketcanIF & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<socketcan_interface_msg::msg::SocketcanIF>()
{
  return "socketcan_interface_msg::msg::SocketcanIF";
}

template<>
inline const char * name<socketcan_interface_msg::msg::SocketcanIF>()
{
  return "socketcan_interface_msg/msg/SocketcanIF";
}

template<>
struct has_fixed_size<socketcan_interface_msg::msg::SocketcanIF>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<socketcan_interface_msg::msg::SocketcanIF>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<socketcan_interface_msg::msg::SocketcanIF>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SOCKETCAN_INTERFACE_MSG__MSG__DETAIL__SOCKETCAN_IF__TRAITS_HPP_
