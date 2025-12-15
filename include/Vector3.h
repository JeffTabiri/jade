#ifndef JADE_VECTOR3_H
#define JADE_VECTOR3_H
#include <cmath>
#include <iosfwd>

namespace jade {
    class Vector3 {
    public:
        int x = {};
        int y = {};
        int z = {};
        Vector3(int x, int y, int z);
        Vector3 operator-(const Vector3& other) const;
        Vector3 operator+(const Vector3& other) const;
        Vector3 operator*(const int& scalar) const;
        int operator*(const Vector3& other) const;
        Vector3 operator/(const int& scalar) const;
        std::ostream &operator<<(std::ostream &os) const;
        float length() const;
    };
}


#endif //JADE_VECTOR3_H