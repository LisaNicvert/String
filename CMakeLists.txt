cmake_minimum_required(VERSION 3.1.3)
project(TP7 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14) # Use C++14
set(CMAKE_BUILD_TYPE Debug) # To make the gdb run in debug mode

add_executable(tp7 tp7.cpp String.cpp )
