#ifndef R1_VERTICAL_DRIVER__VISIBILITY_CONTROL_H_
#define R1_VERTICAL_DRIVER__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define R1_VERTICAL_DRIVER_EXPORT __attribute__ ((dllexport))
    #define R1_VERTICAL_DRIVER_IMPORT __attribute__ ((dllimport))
  #else
    #define R1_VERTICAL_DRIVER_EXPORT __declspec(dllexport)
    #define R1_VERTICAL_DRIVER_IMPORT __declspec(dllimport)
  #endif
  #ifdef R1_VERTICAL_DRIVER_BUILDING_LIBRARY
    #define R1_VERTICAL_DRIVER_PUBLIC R1_VERTICAL_DRIVER_EXPORT
  #else
    #define R1_VERTICAL_DRIVER_PUBLIC R1_VERTICAL_DRIVER_IMPORT
  #endif
  #define R1_VERTICAL_DRIVER_PUBLIC_TYPE R1_VERTICAL_DRIVER_PUBLIC
  #define R1_VERTICAL_DRIVER_LOCAL
#else
  #define R1_VERTICAL_DRIVER_EXPORT __attribute__ ((visibility("default")))
  #define R1_VERTICAL_DRIVER_IMPORT
  #if __GNUC__ >= 4
    #define R1_VERTICAL_DRIVER_PUBLIC __attribute__ ((visibility("default")))
    #define R1_VERTICAL_DRIVER_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define R1_VERTICAL_DRIVER_PUBLIC
    #define R1_VERTICAL_DRIVER_LOCAL
  #endif
  #define R1_VERTICAL_DRIVER_PUBLIC_TYPE
#endif

#endif  // R1_VERTICAL_DRIVER__VISIBILITY_CONTROL_H_
