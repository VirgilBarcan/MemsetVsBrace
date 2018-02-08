cmake_minimum_required(VERSION 3.9)
project(MemsetVsBrace)

set(CMAKE_CXX_STANDARD 11)

add_executable(MemsetVsBrace main.cpp)
target_link_libraries(MemsetVsBrace benchmark pthread)
