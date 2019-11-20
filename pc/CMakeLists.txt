cmake_minimum_required(VERSION 3.8.2)

project(fat++ C CXX)

add_executable(fat_test main.cpp)
target_include_directories(fat_test PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>)
