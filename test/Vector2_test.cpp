//
// Created by Solarium on 24/12/2025.
//

#include "Vector2.h"
#include  <gtest/gtest.h>

TEST(Vector2Test, AssertVectorAddition) {
    const auto v1 = jade::Vector2(-3,2);
    const auto v2 = jade::Vector2(2,2);
    const auto v3 = v1 + v2;

    EXPECT_EQ(v3.x, -1);
    EXPECT_EQ(v3.y, 4);
}