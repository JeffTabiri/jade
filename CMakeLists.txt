# ensures that Cmake will adopt the behaviour of the listed version.
cmake_minimum_required(VERSION 3.20)

# Define project Look for C++ compiler
project(jade CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


### Dependencies ###

# Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

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

target_compile_features(jade PUBLIC cxx_std_20)

# Tests
enable_testing()
add_subdirectory(tests)

# Example
add_subdirectory(example)

