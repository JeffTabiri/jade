#include <iostream>

#include "../include/Vector2D.h"


void print_number(int x) {
    std::cout << x << "\n";
}

int main() {
    Vector2D A {5,6};
    Vector2D B {2,3};


    std::cout << B * A << "\n";

    int c = 5;
    *(&c) = 6;

    int z = 5;
    int g = 10;

    int* ptr = {nullptr}; //pointer to the variable a null ptr

    if (ptr == nullptr) {
        std::cout << "Wow nullpointers" << "\n";
    }

}
