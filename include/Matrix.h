#ifndef JADE_MATRIX_H
#define JADE_MATRIX_H

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
    }

    Matrix<T, Rows, Cols> operator-(const Matrix<T, Rows, Cols>& other) const {
        Matrix<T, Rows, Cols> result;
        for (int i = 0; i < Rows; ++i) {
            for (int j = 0; j < Cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    };

    friend bool operator==(const Matrix& mat1, const Matrix& mat2) {
        bool equal = true;
        for (int i = 0; i < Rows; ++i) {
            for (int j = 0; j < Cols; ++j) {
                equal = equal && mat1.data[i][j] == mat2.data[i][j];
            }
        }
        return equal;
    }

    friend bool operator!=(const Matrix& mat1, const Matrix& mat2)
    {
        return !(mat1 == mat2);
    }


    Matrix<T, Rows, Cols> operator-() const {
        Matrix<T, Rows, Cols> result;
        for (int i = 0; i < Rows; ++i) {
            for (int j = 0; j < Cols; ++j) {
                result.data[i][j] = -data[i][j];
            }
        }
        return result;
    }

    friend Matrix operator*(T scalar, const Matrix& mat1) {
        Matrix<T, Rows, Cols> result;
        for (int i = 0; i < Rows; ++i) {
            for (int j = 0; j < Cols; ++j) {
                result.data[i][j] = mat1.data[i][j] * scalar;
            }
        }
        return result;
    }

    friend Matrix operator*(const Matrix& mat1, T scalar) {
        return scalar * mat1;
    }

    friend Matrix operator/(T scalar, const Matrix& mat1) {
        Matrix<T, Rows, Cols> result;
        for (int i = 0; i < Rows; ++i) {
            for (int j = 0; j < Cols; ++j) {
                result.data[i][j] = mat1.data[i][j] / scalar;
            }
        }
        return result;
    }

    friend Matrix operator/(const Matrix& mat1, T scalar) {
        return scalar * mat1;
    }

    template<int OtherCols>
    Matrix<T, Rows, OtherCols> operator*(const Matrix<T, Cols, OtherCols>& other) const {
        Matrix<T, Rows, OtherCols> result{};

        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < OtherCols; j++) {
                for (int k = 0; k < Cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }

    friend std::ostream& operator<<(std::ostream& out, const Matrix& mat) {
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

    friend std::ostream& operator>> (std::ostream& in, const Matrix& mat) {
        for (int i = 0; i < mat.rows; i++) {
            for (int j = 0; j < mat.cols; j++) {
                in >> mat.data[i][j];
            }
        }
        return in;
    }

    T* operator[](int idx) {
        return data[idx];
    }
};


#endif //JADE_MATRIX_H