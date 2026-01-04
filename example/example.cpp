#include <vector>
#include <iostream>
#include "Matrix.h"

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
    auto D = A - B;
    auto E = A * B;
    auto F = 4 * A;

    std::cout << C << std::endl;
    std::cout << D << std::endl;
    std::cout << E << std::endl;
    std::cout << F << std::endl;

    /*
    OUTPUT

    2, 4, 8
    2, 4, 6
    2, 4, 6

    0, 0, 0
    0, 0, 0
    0, 0, 0

    7, 14, 22
    6, 12, 19
    6, 12, 19

    4, 8, 16
    4, 8, 12
    4, 8, 12
    */

    return 0;
}
