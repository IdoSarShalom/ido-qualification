#include "rectangle.hpp"
#include "geometry_utils.hpp"
#include <iostream>

using namespace geometry;

int main() {
    Rectangle rect;
    rect.set_side1(5.0f);
    rect.set_side2(3.0f);

    std::cout << "Rectangle sides: " << rect.get_side1() << " x " << rect.get_side2() << std::endl;
    std::cout << "Rectangle area (direct): " << rect.area() << std::endl;
    std::cout << "Rectangle area (via get_area): " << get_area(rect) << std::endl;

    return 0;
}