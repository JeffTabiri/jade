#include "../include/Vector2.h"
#include <cmath>

namespace jade {
    Vector2::Vector2(int in_x, int in_y) {
        x = in_x;
        y = in_y;
    }

    Vector2 Vector2::operator-(const Vector2 &other) const {
        return Vector2(this->x - other.x, this->y - other.y);
    }

    Vector2 Vector2::operator*(const int &scalar) const {
        return Vector2(this->x * scalar, this->y * scalar);
    }

    int Vector2::operator*(const Vector2 &other) const {
        return this->x * other.x + this->y * other.y;
    }

    Vector2 Vector2::operator+(const Vector2 &other) const {
        return Vector2(this->x + other.x, this->y + other.y);
    }

    float Vector2::get_length() const {
        const float length = std::sqrt(std::pow(x, 2) * std::pow(y, 2));
        return length;
    }

}
