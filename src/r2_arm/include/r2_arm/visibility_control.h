#ifndef R2_ARM__VISIBILITY_CONTROL_H_
#define R2_ARM__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define R2_ARM_EXPORT __attribute__ ((dllexport))
    #define R2_ARM_IMPORT __attribute__ ((dllimport))
  #else
    #define R2_ARM_EXPORT __declspec(dllexport)
    #define R2_ARM_IMPORT __declspec(dllimport)
  #endif
  #ifdef R2_ARM_BUILDING_LIBRARY
    #define R2_ARM_PUBLIC R2_ARM_EXPORT
  #else
    #define R2_ARM_PUBLIC R2_ARM_IMPORT
  #endif
  #define R2_ARM_PUBLIC_TYPE R2_ARM_PUBLIC
  #define R2_ARM_LOCAL
#else
  #define R2_ARM_EXPORT __attribute__ ((visibility("default")))
  #define R2_ARM_IMPORT
  #if __GNUC__ >= 4
    #define R2_ARM_PUBLIC __attribute__ ((visibility("default")))
    #define R2_ARM_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define R2_ARM_PUBLIC
    #define R2_ARM_LOCAL
  #endif
  #define R2_ARM_PUBLIC_TYPE
#endif

#endif  // R2_ARM__VISIBILITY_CONTROL_H_
