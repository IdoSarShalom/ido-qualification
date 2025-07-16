#include <iostream>

int get_integer() {
    int user_input;
    std::cout << "Please enter an integer: ";
    std::cin >> user_input;
    return user_input;
}

int* allocate_dynamic_integer(const int integer_value) {
    const auto dynamic_integer = new int;
    *dynamic_integer = integer_value;
    return dynamic_integer;
}

void print_integer(const int* dynamic_integer, const int original_value) {
    std::cout << "\n--- Value Output ---" << std::endl;
    std::cout << "Value accessed via pointer: " << *dynamic_integer << std::endl;
    std::cout << "Original input value: " << original_value << std::endl;
}

void deallocate_dynamic_integer(const int* dynamic_integer) {
    delete dynamic_integer;
    dynamic_integer = nullptr;
}

int main() {
    const int integer_input = get_integer();
    const int* dynamic_integer = allocate_dynamic_integer(integer_input);
    print_integer(dynamic_integer, integer_input);
    deallocate_dynamic_integer(dynamic_integer);
    return 0;
}
