set(CMAKE_TOOLCHAIN_FILE ../cmake/Arduino-Toolchain.cmake)
cmake_minimum_required(VERSION 3.8.2)

project(fat++ C CXX ASM)

arduino_cmake_project(fat++ BOARD_NAME mega BOARD_CPU atmega2560)

add_arduino_executable(fat_test main.cpp)
set_target_upload_port(fat_test /dev/ttyACM0)

link_platform_library(fat_test SPI)

target_include_directories(fat_test PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>)
