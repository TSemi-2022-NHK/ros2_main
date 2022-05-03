#ifndef TCP_JOYSTICK_HANDLER__VISIBILITY_CONTROL_H_
#define TCP_JOYSTICK_HANDLER__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define TCP_JOYSTICK_HANDLER_EXPORT __attribute__ ((dllexport))
    #define TCP_JOYSTICK_HANDLER_IMPORT __attribute__ ((dllimport))
  #else
    #define TCP_JOYSTICK_HANDLER_EXPORT __declspec(dllexport)
    #define TCP_JOYSTICK_HANDLER_IMPORT __declspec(dllimport)
  #endif
  #ifdef TCP_JOYSTICK_HANDLER_BUILDING_LIBRARY
    #define TCP_JOYSTICK_HANDLER_PUBLIC TCP_JOYSTICK_HANDLER_EXPORT
  #else
    #define TCP_JOYSTICK_HANDLER_PUBLIC TCP_JOYSTICK_HANDLER_IMPORT
  #endif
  #define TCP_JOYSTICK_HANDLER_PUBLIC_TYPE TCP_JOYSTICK_HANDLER_PUBLIC
  #define TCP_JOYSTICK_HANDLER_LOCAL
#else
  #define TCP_JOYSTICK_HANDLER_EXPORT __attribute__ ((visibility("default")))
  #define TCP_JOYSTICK_HANDLER_IMPORT
  #if __GNUC__ >= 4
    #define TCP_JOYSTICK_HANDLER_PUBLIC __attribute__ ((visibility("default")))
    #define TCP_JOYSTICK_HANDLER_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define TCP_JOYSTICK_HANDLER_PUBLIC
    #define TCP_JOYSTICK_HANDLER_LOCAL
  #endif
  #define TCP_JOYSTICK_HANDLER_PUBLIC_TYPE
#endif

#endif  // TCP_JOYSTICK_HANDLER__VISIBILITY_CONTROL_H_
