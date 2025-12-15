cmake_minimum_required(VERSION 4.0)

add_executable(jade_example)

target_sources(jade_example PRIVATE example.cpp)

target_link_libraries(jade_example PRIVATE jade)