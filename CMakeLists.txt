# ensures that Cmake will adopt the behaviour of the listed version.
cmake_minimum_required(VERSION 4.0)

# Define project Look for C++ compiler
project(jade CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(example)

# Create the library
add_library(jade)

target_sources(
        jade
        PRIVATE
        src/Vector2.cpp
        src/Vector3.cpp

        PUBLIC
        FILE_SET HEADERS
        BASE_DIRS include
        FILES
        include/Vector2.h
        include/Vector3.h
)

