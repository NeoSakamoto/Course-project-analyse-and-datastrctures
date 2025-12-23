# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Course-project-analyse-and-datastrctures_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Course-project-analyse-and-datastrctures_autogen.dir\\ParseCache.txt"
  "Course-project-analyse-and-datastrctures_autogen"
  )
endif()
