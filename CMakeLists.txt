cmake_minimum_required(VERSION 3.23)
project(todo_app)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)

add_executable(todo_app
        src/main.cpp)
