cmake_minimum_required(VERSION 3.29)
project(project1)

set(CMAKE_CXX_STANDARD 20)

add_executable(project1 main.cpp
        command_function.h
        command_function.cpp)
