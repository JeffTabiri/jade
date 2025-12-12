cmake_minimum_required(VERSION 4.0)

# Look for C++ compiler
project(jade

         CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(jade src/main.cpp
        src/Vector2D.cpp
        include/Vector2D.h)
