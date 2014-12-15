cmake_minimum_required(VERSION 2.8.4)
project(soldat_class)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(soldat_class ${SOURCE_FILES})