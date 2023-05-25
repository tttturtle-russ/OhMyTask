# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/OhMyTask_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/OhMyTask_autogen.dir/ParseCache.txt"
  "OhMyTask_autogen"
  )
endif()
