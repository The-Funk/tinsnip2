cmake_minimum_required(VERSION 3.6)
project(tinsnip)


set(CMAKE_CXX_STANDARD  17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -ltins -lzdb -lviface")

include_directories("/usr/include/zdb")
find_package(zdb)

include_directories("/usr/local/include/tins")
find_package(tins)

include_directories("/usr/local/include/viface")
find_package(viface)

set(SOURCE_FILES main.cpp t_sniffer.cpp t_sniffer.h t_poisoner.cpp t_poisoner.h t_dnsspoof.cpp t_dnsspoof.h t_database.cpp t_database.h t_reports.cpp t_reports.h t_dhcpstarve.cpp t_dhcpstarve.h)
add_executable(tinsnip ${SOURCE_FILES} t_sniffer.cpp t_sniffer.h t_poisoner.cpp t_poisoner.h t_dnsspoof.cpp t_dnsspoof.h t_database.cpp t_database.h t_reports.cpp t_reports.h t_dhcpstarve.cpp t_dhcpstarve.h)