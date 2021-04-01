cmake_minimum_required(VERSION 3.16)
project(NagyHazi_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(NagyHazi_2 main.cpp vonat.cpp vonat.h jegy.cpp jegy.h datum.cpp datum.h gtest_lite.h memtrace.cpp memtrace.h string.cpp string.h)

add_compile_definitions(MEMTRACE)