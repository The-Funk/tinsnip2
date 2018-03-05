cmake_minimum_required(VERSION 3.6)
project(tinsnip)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories("/usr/include/zdb")
find_package(zdb)

set(SOURCE_FILES main.cpp t_sniffer.cpp t_sniffer.h t_poisoner.cpp t_poisoner.h t_dnsspoof.cpp t_dnsspoof.h t_database.cpp t_database.h t_reports.cpp t_reports.h)
add_executable(tinsnip ${SOURCE_FILES} t_sniffer.cpp t_sniffer.h t_poisoner.cpp t_poisoner.h t_dnsspoof.cpp t_dnsspoof.h t_database.cpp t_database.h t_reports.cpp t_reports.h)