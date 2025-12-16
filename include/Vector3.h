#ifndef JADE_VECTOR3_H
#define JADE_VECTOR3_H
#include <iosfwd>

namespace jade {
    class Vector3 {
    public:
        int x = {};
        int y = {};
        int z = {};
        Vector3(int x, int y, int z);
        Vector3();
        Vector3 operator-(const Vector3& other) const;
        Vector3 operator+(const Vector3& other) const;
        Vector3 operator*(const int& scalar) const;
        int operator*(const Vector3& other) const;
        Vector3 operator/(const int& scalar) const;
        std::ostream &operator<<(std::ostream &os) const;

        float magnitude() const;

        Vector3 dot();

        static Vector3 unit_X();
        static Vector3 unit_Y();
        static Vector3 unit_Z();
        static Vector3 zero();
        static Vector3 normalize(const Vector3& other);

    };
}


#endif //JADE_VECTOR3_H