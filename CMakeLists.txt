cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(suffix)
add_executable(${PROJECT_NAME} "main.cpp" "sa-is.h")
