cmake_minimum_required(VERSION 3.6)
project(tinsnip)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories("/usr/include/zdb")
find_package(zdb)

set(SOURCE_FILES main.cpp)
add_executable(tinsnip ${SOURCE_FILES})