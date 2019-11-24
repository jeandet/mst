cmake_minimum_required(VERSION 3.6)
project(ucpp-tests CXX)

set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
endif()

enable_testing()

add_subdirectory(registers_and_fields)
