//
// Created by Solarium on 29/12/2025.
//

#ifndef JADE_MATRIX_H
#define JADE_MATRIX_H
#include <stdexcept>

template<typename T, int Rows, int Cols>
class Matrix {
    T data[Rows][Cols] = {};
    int rows = Rows;
    int cols = Cols;

public:
    Matrix() = default;
    Matrix(std::initializer_list<std::initializer_list<T>> init) {
        int r = 0;
        for (const auto& row : init) {
            int c = 0;
            for (const auto& value : row) {
                data[r][c] = value;
                ++c;
            }
            ++r;
        }
    }

    Matrix<T, Rows, Cols> operator+(const Matrix<T, Rows, Cols>& other) const {
        Matrix<T, Rows, Cols> result;
        for (int i = 0; i < Rows; ++i) {
            for (int j = 0; j < Cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    };

    Matrix<T, Rows, Cols> operator-(const Matrix<T, Rows, Cols>& other) const {
        Matrix<T, Rows, Cols> result;
        for (int i = 0; i < Rows; ++i) {
            for (int j = 0; j < Cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    };

    Matrix<T, Rows, Cols> operator*(T scalar) const {
        Matrix<T, Rows, Cols> result;
        for (int i = 0; i < Rows; ++i) {
            for (int j = 0; j < Cols; ++j) {
                result.data[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }

    Matrix<T, Rows, Cols> operator/(T scalar) const {
        Matrix<T, Rows, Cols> result;
        for (int i = 0; i < Rows; ++i) {
            for (int j = 0; j < Cols; ++j) {
                result.data[i][j] = data[i][j] / scalar;
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::runtime_error("Matrix dimensions are not fit for matrix multiplication");
        }

        Matrix<T, other.rows, this->cols> result;

        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result[i][j] = 0;
                for (int k = 0; k < other.rows; k++) {
                    result[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }

    friend std::ostream& operator<< (std::ostream& out, const Matrix& mat) {
        for (int i = 0; i < mat.rows; i++) {
            for (int j = 0; j < mat.cols; j++) {
                if (j == mat.cols - 1) { // if the number is last in its entry
                    out << mat.data[i][j];
                } else {
                    out << mat.data[i][j] << ", ";
                }
            }
            out << "\n";
        }

        return out;
    }

};


#endif //JADE_MATRIX_H