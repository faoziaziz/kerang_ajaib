cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(KerangOS)

set(CMAKE_CXX_STANDARD CXX)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

find_package(Threads)
find_package(json-c CONFIG)

add_executable(KerangOS kerangos.cc commands.cc)
TARGET_LINK_LIBRARIES(KerangOS pthread json-c::json-c)
install (TARGETS KerangOS DESTINATION bin)
