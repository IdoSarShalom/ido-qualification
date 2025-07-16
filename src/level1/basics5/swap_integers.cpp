#include <iostream>

void swapIntegers(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int a = 10;
    int b = 20;

    std::cout << "Before swap:" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    swapIntegers(&a, &b);

    std::cout << "After swap:" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    return 0;
}