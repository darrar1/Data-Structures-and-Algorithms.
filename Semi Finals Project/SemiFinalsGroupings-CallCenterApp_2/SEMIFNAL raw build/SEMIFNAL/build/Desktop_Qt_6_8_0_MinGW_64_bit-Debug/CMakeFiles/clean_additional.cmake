# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\SEMIFNAL_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SEMIFNAL_autogen.dir\\ParseCache.txt"
  "SEMIFNAL_autogen"
  )
endif()
