#include  <gtest/gtest.h>
#include "Matrix.h"

TEST(Matrix, ArgumentConstructor) {
    Matrix<float, 2, 2> A{{3, 2}, {4, 5}};
    EXPECT_EQ(A[0][0], 3);
    EXPECT_EQ(A[0][1], 2);
    EXPECT_EQ(A[1][0], 4);
    EXPECT_EQ(A[1][1], 5);
}

TEST(Matrix, DefaultConstructor) {
    Matrix<float, 2, 2> A{};
    EXPECT_EQ(A[0][0], 0);
    EXPECT_EQ(A[0][1], 0);
    EXPECT_EQ(A[1][0], 0);
    EXPECT_EQ(A[1][1], 0);
}

TEST(Matrix, AssertEqual) {
    Matrix<float, 2, 2> A{};
    Matrix<float, 2, 2> B{};
    EXPECT_EQ(A, B);
}

TEST(Matrix, AssertNotEqual) {
    Matrix<float, 2, 2> A{};
    Matrix<float, 2, 2> B{
        {1, 2},
        {3, 4}
    };
    EXPECT_NE(A, B);
}


TEST(Matrix, Addition) {
    Matrix<float, 3, 3> A{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Matrix<float, 3, 3> B{
        {1, 7, 3},
        {9, 10, 1},
        {7, 11, 3}
    };

    auto C = A + B;

    auto expected = Matrix<float, 3, 3>{
        {2, 9, 6},
        {13, 15, 7},
        {14, 19, 12}
    };

    EXPECT_EQ(C, expected);
}

TEST(Matrix, Subtraction) {
    Matrix<float, 3, 3> A{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Matrix<float, 3, 3> B{
        {1, 7, 3},
        {9, 10, 1},
        {7, 11, 3}
    };

    auto C = A - B;

    auto expected = Matrix<float, 3, 3>{
        {0, -5, 0},
        {-5, -5, 5},
        {0, -3, 6}
    };

    EXPECT_EQ(C, expected);
}


TEST(Matrix, Negatation) {
    Matrix<float, 3, 3> A{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Matrix<float, 3, 3> B{
        {-1, -2, -3},
        {-4, -5, -6},
        {-7, -8, -9}
    };


    EXPECT_EQ(-A, B);
}


TEST(Matrix, ScalarMultiplication) {
    Matrix<float, 3, 3> A{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B{5};

    auto C = B * A;

    auto expected = Matrix<float, 3, 3>{
        {5, 10, 15},
        {20, 25, 30},
        {35, 40, 45}
    };

    EXPECT_EQ(C, expected);
}

TEST(Matrix, ScalarDivision) {
    Matrix<float, 3, 3> A{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    float B{2};

    auto C = B / A;

    auto expected = Matrix<float, 3, 3>{
        {0.5, 1, 1.5},
        {2, 2.5, 3},
        {3.5, 4, 4.5}
    };

    EXPECT_EQ(C, expected);
}

TEST(Matrix, MatrixMultiplication) {
    Matrix<float, 3, 3> A{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Matrix<float, 3, 3> B{
           {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    auto C = A * B;

    auto expected = Matrix<float, 3, 3>{
        {30, 36, 42},
        {66, 81, 96},
        {102, 126, 150}
    };

    EXPECT_EQ(C, expected);
}
