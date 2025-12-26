#include <complex>
//
// Created by Solarium on 26/12/2025.
//
namespace jade {

    int Arithmetic_Sum(int n, int distance, int init_term) {
        int result = 0;

        result = n * init_term + (n * (n - 1) / 2) * distance;

        return result;
    }

    float Geometric_Sum(int n, float multiple, float init_term) {
        float result = 0;
        result = init_term * ((std::pow(multiple, n) - 1) / (multiple - 1));
        return result;
    }

}