#include "../include/Vector2D.h"
#include <complex>
#include <cmath>

Vector2D::Vector2D(int in_x, int in_y) {
    x = in_x;
    y = in_y;
}

Vector2D Vector2D::operator-(const Vector2D &other) const {
    return Vector2D(this->x - other.x, this->y - other.y);
}

Vector2D Vector2D::operator*(const int &scalar) const {
}

int Vector2D::operator*(const Vector2D &other) const {
    return this->x * other.x + this->y * other.y;
}

Vector2D Vector2D::operator+(const Vector2D &other) const {
    return Vector2D(this->x + other.x, this->y + other.y);
}

float Vector2D::get_length() const {
    const float length = std::sqrt(std::pow(x, 2) * std::pow(y, 2));
    return length;
}
