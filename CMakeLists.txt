# ensures that Cmake will adopt the behaviour of the listed version.
cmake_minimum_required(VERSION 4.0)
option(BUILD_TESTING "Enable testing and build tests" TRUE)

# Define project Look for C++ compiler
project(jade CXX) # sets the name for project
set(CMAKE_CXX_STANDARD 20) # sets the compiler standard to CPP 20
set(CMAKE_CXX_STANDARD_REQUIRED ON) # cmake fails if the compiler does not support versioning
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
add_library(jade
        include/Matrix.h)

target_sources(
        jade
        PRIVATE
        src/Vector2.cpp
        src/Vector3.cpp
        src/util.cpp
        src/Matrix2.cpp

        PUBLIC
        FILE_SET HEADERS
        BASE_DIRS include
        FILES
        include/Vector2.h
        include/Vector3.h
        include/Utility.h
        include/Matrix2.h
)

target_compile_features(jade PUBLIC cxx_std_20)

# Example
add_subdirectory(example)

# Tests
if (BUILD_TESTING)
        enable_testing() # command generates necessary metadata in the build tree in order for ctest to find and run tests.
        add_subdirectory(test) #
endif ()




