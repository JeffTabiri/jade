cmake_minimum_required(VERSION 4.0)

add_executable(jade_test
        Vector2_test.cpp
)

target_link_libraries(jade_test GTest::gtest_main jade)

# Enable CMakes test runner to discover the tests included in the target
include(GoogleTest)
gtest_discover_tests(jade_test)