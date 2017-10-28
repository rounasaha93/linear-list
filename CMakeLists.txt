cmake_minimum_required(VERSION 3.8)
project(linear_list)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES LinearList.h LinearList.cpp)
add_executable(linear_list ${SOURCE_FILES})