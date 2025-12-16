#include <iostream>
#include <Vector2.h>
#include <Vector3.h>

int main(int argc, char *argv[]) {
    jade::Vector3 A = jade::Vector3(4,5,6);

    jade::Vector3 B = jade::Vector3(10, 20, 10);

    jade::Vector3 C = A + B;

    jade::Vector3 D = jade::Vector3::zero();

    jade::Vector3 E = jade::Vector3(1, 0, 0);

    std::cout << D.x << " " << D.y << " " << D.z << std::endl;


    return 0;
}
