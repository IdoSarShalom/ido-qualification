#include <iostream>
#include <utility>

constexpr double PI = 3.14159;

namespace circles {
    double calculate_area(const double radius) {
        return PI * radius * radius;
    }

    double calculate_perimeter(const double radius) {
        return 2 * PI * radius;
    }

    std::pair<double, double> get_circle_info(const double radius) {
        double area = calculate_area(radius);
        double perimeter = calculate_perimeter(radius);
        return std::make_pair(area, perimeter);
    }

    void print_circle_info(const double radius) {
        const double area = calculate_area(radius);
        const double perimeter = calculate_perimeter(radius);
        std::cout << "Area: " << area << std::endl;
        std::cout << "Perimeter: " << perimeter << std::endl;
    }
}

int main() {
    double radius;
    std::cout << "Enter the radius: ";
    std::cin >> radius;
    circles::print_circle_info(radius);
    return 0;
}
