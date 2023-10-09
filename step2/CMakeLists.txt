cmake_minimum_required(VERSION 3.19)
project(cmake_tutorial)
set(CMAKE_CXX_STANDARD 20)
include_directories(./include) # gcc/g++ -I ...
add_executable(a.out src/tensor.cpp main.cpp) # g++ main.cpp src/tensor.cpp -o test
