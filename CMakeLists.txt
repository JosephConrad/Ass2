cmake_minimum_required(VERSION 2.8.4)
project(Ass2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c)
add_executable(Ass2 ${SOURCE_FILES})