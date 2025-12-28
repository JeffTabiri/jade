#ifndef JADE_MATRIX2_H
#define JADE_MATRIX2_H

namespace jade {
    class Matrix2 {
    public:
        float grid[2][2];
        Matrix2(int a[], int b[]);
        Matrix2();
        Matrix2(int a[2][2]);
        Matrix2 operator-(const Matrix2 &other);
        Matrix2 operator+(const Matrix2 &other);
        Matrix2 operator*() const;
    };
}

#endif //JADE_MATRIX2_H