cmake_minimum_required(VERSION 3.9)
project(MemsetVsBrace)

set(CMAKE_CXX_STANDARD 11)

# build the benchmark executable
add_executable(MemsetVsBraceBenchmark memset_vs_brace_benchmark.cpp)
target_link_libraries(MemsetVsBraceBenchmark benchmark pthread)

# build the small test executable (will be used to disassemble the code)
add_executable(MemsetVsBrace memset_vs_brace.cpp)