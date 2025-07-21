#include <iostream>

void swap_integers(int* ptr1, int* ptr2) {
    if (ptr1 != ptr2) {
        *ptr1 = *ptr1 ^ *ptr2;
        *ptr2 = *ptr1 ^ *ptr2;
        *ptr1 = *ptr1 ^ *ptr2;
    }
}

int main() {
    int a = 10;
    int b = 20;

    std::cout << "Before swap:" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    swap_integers(&a, &b);

    std::cout << "After swap:" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    return 0;
}
