#include <Vector3.h>
#include <vector>
#include <format>
#include <iostream>

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

    jade::Vector3 A = jade::Vector3(4.0,5,6);

    jade::Vector3 B = jade::Vector3(10, 20, 10);

    auto F = linearize(A, B);
    std::cout << std::format("LOL");
    jade::Vector3 C = A + B;

    jade::Vector3 D = jade::Vector3::zero();

    jade::Vector3 E = jade::Vector3(1, 0, 0);

    //std::cout << D.x << " " << D.y << " " << D.z << std::endl;

    /*
    for (auto& item : F) {
        item.print();
    }
    */

    return 0;
}
