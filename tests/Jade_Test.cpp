#include "Vector2.h"
#include  <gtest/gtest.h>
#include "Utility.h"

TEST(Vector2Test, AssertVectorAddition) {
    const auto v1 = jade::Vector2(-3,2);
    const auto v2 = jade::Vector2(2,2);
    const auto v3 = v1 + v2;

    EXPECT_EQ(v3.x, -1);
    EXPECT_EQ(v3.y, 4);
}

TEST(UtilTest, ArithmeticSum) {
    // 1 + 2 + 3 + ... + 10 = 55
    const int result = jade::Arithmetic_Sum(10, 1, 1);
    EXPECT_EQ(result, 55);
}

TEST(UtilTest, ArithmeticSum_SingleTerm) {
    // 5 = 5
    const int result = jade::Arithmetic_Sum(1, 0, 5);
    EXPECT_EQ(result, 5);
}

TEST(UtilTest, GeometricSum) {
    // 1 + 5 + 25 + 125 = 156
    const float result = jade::Geometric_Sum(4, 5, 1);
    EXPECT_EQ(result, 156);
}

TEST(UtilTest, GeometricSum_SingleTerm) {
    // 1
    const float result = jade::Geometric_Sum(1, 0, 1);
    EXPECT_EQ(result, 1);
}