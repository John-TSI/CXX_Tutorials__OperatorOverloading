cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(task VERSION 1.0.0)

add_executable(${PROJECT_NAME} src/main.cpp src/named_type.hpp src/class.hpp)