cmake_minimum_required(VERSION 2.8)
project(2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(2 ${SOURCE_FILES} table_printer.cpp table_printer.h table_printer.tpp.h)