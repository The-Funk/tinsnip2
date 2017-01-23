cmake_minimum_required(VERSION 3.6)
project(tinsnip)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp .idea/optionparser.h optionparser.h)
add_executable(tinsnip ${SOURCE_FILES} optionparser.h)