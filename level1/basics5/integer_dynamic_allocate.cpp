#include <iostream>
#include <memory>

int get_integer() {
    int user_input;
    std::cout << "Please enter an integer: ";
    std::cin >> user_input;
    return user_input;
}

std::unique_ptr<int> allocate_dynamic_integer(const int integer_value) {
    auto dynamic_integer = std::make_unique<int>(integer_value);

    return dynamic_integer;
}

void print_integer(const std::unique_ptr<int>& dynamic_integer, const int original_value) {
    std::cout << "\n--- Value Output ---" << std::endl;
    std::cout << "Value accessed via pointer: " << *dynamic_integer << std::endl;
    std::cout << "Original input value: " << original_value << std::endl;
}

int main() {
    const int integer_input = get_integer();
    const auto dynamic_integer = allocate_dynamic_integer(integer_input);
    print_integer(dynamic_integer, integer_input);

    return 0;
}
