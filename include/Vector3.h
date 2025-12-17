#ifndef JADE_VECTOR3_H
#define JADE_VECTOR3_H
#include <iosfwd>

namespace jade {
    class Vector3 {
    public:
        double x = {};
        double y = {};
        double z = {};
        Vector3(double x, double y, double z);
        Vector3();
        Vector3 operator-(const Vector3& other) const;
        Vector3 operator+(const Vector3& other) const;
        Vector3 operator*(const double& scalar) const;
        Vector3 operator*(const int& scalar) const;
        int operator*(const Vector3& other) const;
        Vector3 operator/(const int& scalar) const;
        std::ostream &operator<<(std::ostream &os) const;

        float magnitude() const;

        Vector3 dot();
        void print();

        static Vector3 unit_X();
        static Vector3 unit_Y();
        static Vector3 unit_Z();
        static Vector3 zero();
        static Vector3 normalize(const Vector3& other);

    };
}


#endif //JADE_VECTOR3_H