﻿# CMakeList.txt : CMake project for ccp_prac3, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (ccp_prac3 "ccp_prac3.cpp" "ccp_prac3.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ccp_prac3 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
