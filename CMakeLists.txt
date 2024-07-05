cmake_minimum_required(VERSION 3.28)
add_definitions(-std=c++20)

project(Test_core)

set (SOURCE main.cpp resources.cpp commands.cpp)

include_directories(headers)
add_executable(test ${SOURCE})


