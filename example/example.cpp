#include <iostream>
#include <Vector2.h>
#include <Vector3.h>

int main(int argc, char *argv[]) {
    jade::Vector3 A = jade::Vector3(4,5,6);

    jade::Vector3 B = jade::Vector3(10, 20, 10);

    jade::Vector3 C = A + B;

    std::cout << C.x << " " << C.y << " " << C.z << std::endl;

    return 0;
}
