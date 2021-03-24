cmake_minimum_required(VERSION 3.0.0)
project(LanTP VERSION 0.1.0)

include(CTest)
enable_testing()

set(SOURCES src/main.cpp src/Network/TCP/TCP.cpp src/Network/TCP/TCP.hpp)
add_executable(LanTP ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
