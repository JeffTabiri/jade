#include "Matrix2.h"

namespace jade {

    Matrix2::Matrix2() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                grid[i][j] = 0.0f;
            }
        }
    }

    Matrix2::Matrix2(int a[2][2]) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                grid[i][j] = a[i][j];
            }
        }
    }

    Matrix2::Matrix2(int a[], int b[]) {
        for (int i = 0;  i < 2; ++i) {
            grid[0][i] = a[i];
            grid[1][i] = b[i];
        }
    }

    Matrix2 Matrix2::operator-(const Matrix2 &other) {
        int calculated_grid[2][2] = {};

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                calculated_grid[i][j] = grid[i][j] - other.grid[i][j];
            }
        }

        return Matrix2(calculated_grid);
    }

    Matrix2 Matrix2::operator+(const Matrix2 &other) {
        int calculated_grid[2][2] = {};

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                calculated_grid[i][j] = grid[i][j] + other.grid[i][j];
            }
        }

        return Matrix2(calculated_grid);
    }

    Matrix2 Matrix2::operator*() const {
    }

}
