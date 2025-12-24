#include "../include/Vector3.h"
#include <format>
#include <complex>
#include <iostream>

namespace jade {

    double geometric_sum(double k, double n, double first) {
        double result = first * ((std::pow(k, n) - 1) / (k - 1));
        return result;
    }

    Vector3::Vector3(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector3::Vector3() {
    }

    int Vector3::operator*(const Vector3 &other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    Vector3 Vector3::operator-(const Vector3 &other) const {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    Vector3 Vector3::operator+(const Vector3 &other) const {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    Vector3 Vector3::operator*(const double &scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    Vector3 Vector3::operator/(const int &scalar) const {
        return Vector3(x / scalar, y / scalar, z / scalar);
    }

    Vector3 Vector3::zero() {
        return {};
    }

    std::ostream & Vector3::operator<<(std::ostream &os) const {
        os << "(" << x << " " << y << " " << z << ")";
        return os;
    }

    float Vector3::magnitude() const {
        const float length = std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));
        return length;
    }

     Vector3 Vector3::normalize(const Vector3 &other) {
        float magnitude = other.magnitude();
        return Vector3(other.x / magnitude, other.y / magnitude, other.x / magnitude);
    }

     void Vector3::print() {
        std::cout << std::format("({}, {}, {})\n", this->x, this->y, this->z);
     }

     Vector3 Vector3::unit_X() {
        return {1, 0, 0};
     }

     Vector3 Vector3::unit_Y() {
        return {0, 1, 0};
     }

     Vector3 Vector3::unit_Z() {
        return {0, 0, 1};
     }
}
