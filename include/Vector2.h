#ifndef MATLIB_VECTOR_H
#define MATLIB_VECTOR_H
#include <iosfwd>

namespace jade {
    class Vector2 {

    public:
        int x = {};
        int y = {};
        Vector2(int x, int y);
        Vector2 operator-(const Vector2& other) const;
        Vector2 operator+(const Vector2& other) const;
        Vector2 operator*(const int& scalar) const;
        std::ostream &operator<<(std::ostream &os);
        int operator*(const Vector2& other) const;
        float get_length() const;
    };

}


#endif //MATLIB_VECTOR_H