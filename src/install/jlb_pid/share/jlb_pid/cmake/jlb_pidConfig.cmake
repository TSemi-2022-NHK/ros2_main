# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_jlb_pid_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED jlb_pid_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(jlb_pid_FOUND FALSE)
  elseif(NOT jlb_pid_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(jlb_pid_FOUND FALSE)
  endif()
  return()
endif()
set(_jlb_pid_CONFIG_INCLUDED TRUE)

# output package information
if(NOT jlb_pid_FIND_QUIETLY)
  message(STATUS "Found jlb_pid: 0.1.3 (${jlb_pid_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'jlb_pid' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${jlb_pid_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(jlb_pid_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_dependencies-extras.cmake;ament_cmake_export_include_directories-extras.cmake;ament_cmake_export_libraries-extras.cmake")
foreach(_extra ${_extras})
  include("${jlb_pid_DIR}/${_extra}")
endforeach()
