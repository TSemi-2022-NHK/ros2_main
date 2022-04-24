#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "socketcan_interface::socketcan_interface_node" for configuration ""
set_property(TARGET socketcan_interface::socketcan_interface_node APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(socketcan_interface::socketcan_interface_node PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libsocketcan_interface_node.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS socketcan_interface::socketcan_interface_node )
list(APPEND _IMPORT_CHECK_FILES_FOR_socketcan_interface::socketcan_interface_node "${_IMPORT_PREFIX}/lib/libsocketcan_interface_node.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
