#include <Vector3.h>
#include <vector>
#include <format>
#include <iostream>

#include "Matrix.h"
#include "Matrix4.h"

template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

std::vector<double> lin_space(double start, double end, int n = 40) {
    std::vector out(n + 1, 0.0);

    const double span = end - start;
    const double increment = span / n;

    for (int i = 0; i <= n; ++i) {
        out[i] = start + i * increment;
    }

    return out;
}

std::vector<double> multiply(std::vector<double>&in, double factor) {
    for (double& item : in) {
        item *= factor;
    }
    return in;
}

std::vector<jade::Vector3> linearize(const jade::Vector3& p1, const jade::Vector3& p2) {
    const std::vector<double> span = lin_space(0, 1, 60);


    std::vector out = {60, jade::Vector3()};

    for (int i = 0; i < span.size(); ++i) {
        jade::Vector3 result = p1 + p2 * span[i];
        result.print();
    }

    return out;
}

int main(int argc, char *argv[]) {
    Matrix<float, 3, 3> A = {
        {1,2,4},
        {1,2,3},
        {1,2,3},
    };

    Matrix<float, 3, 3> B = {
        {1,2,4},
        {1,2,3},
        {1,2,3},
    };

    auto C = A + B;

    std::cout << C << std::endl;

    return 0;
}
