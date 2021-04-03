cmake_minimum_required(VERSION 3.16)
project(NagyHazi_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(NagyHazi_2 main.cpp vonat.cpp vonat.hpp jegy.cpp jegy.hpp datum.cpp datum.hpp gtest_lite.h memtrace.cpp memtrace.h string.cpp string.hpp menu.cpp menu.h)

add_compile_definitions(MEMTRACE)