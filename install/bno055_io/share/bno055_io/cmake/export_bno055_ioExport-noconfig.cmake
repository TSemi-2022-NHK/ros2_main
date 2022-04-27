#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "bno055_io::bno055_io_node" for configuration ""
set_property(TARGET bno055_io::bno055_io_node APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(bno055_io::bno055_io_node PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libbno055_io_node.so"
  IMPORTED_SONAME_NOCONFIG "libbno055_io_node.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS bno055_io::bno055_io_node )
list(APPEND _IMPORT_CHECK_FILES_FOR_bno055_io::bno055_io_node "${_IMPORT_PREFIX}/lib/libbno055_io_node.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
