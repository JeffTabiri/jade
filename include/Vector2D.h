#ifndef MATLIB_VECTOR_H
#define MATLIB_VECTOR_H

class Vector2D {

public:
    int x = {};
    int y = {};
    Vector2D(int x, int y);
    Vector2D operator-(const Vector2D& other) const;
    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator*(const int& scalar) const;
    int operator*(const Vector2D& other) const;
    float get_length() const;
};


#endif //MATLIB_VECTOR_H