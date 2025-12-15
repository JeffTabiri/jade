#include "../include/Vector3.h"

#include <complex>

namespace jade {

    Vector3::Vector3(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
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

    Vector3 Vector3::operator*(const int &scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    Vector3 Vector3::operator/(const int &scalar) const {
        return Vector3(x / scalar, y / scalar, z / scalar);
    }

    std::ostream & Vector3::operator<<(std::ostream &os) const {
        os << "(" << x << " " << y << " " << z << ")";
        return os;
    }

    float Vector3::length() const {
        const float length = std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));
        return length;
    }

}
