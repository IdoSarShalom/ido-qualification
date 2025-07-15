#include <iostream>
#include <utility>

#define PI 3.14159

namespace circles {
    double calculateArea(const double radius) {
        return PI * radius * radius;
    }

    double calculatePerimeter(const double radius) {
        return 2 * PI * radius;
    }

    std::pair<double, double> getCircleInfo(const double radius) {
        double area = calculateArea(radius);
        double perimeter = calculatePerimeter(radius);
        return std::make_pair(area, perimeter);
    }

    void printCircleInfo(const double radius) {
        const double area = calculateArea(radius);
        const double perimeter = calculatePerimeter(radius);
        std::cout << "Area: " << area << std::endl;
        std::cout << "Perimeter: " << perimeter << std::endl;
    }
}

int main() {
    double r;
    std::cout << "Enter the radius: ";
    std::cin >> r;
    circles::printCircleInfo(r);

    return 0;
}
