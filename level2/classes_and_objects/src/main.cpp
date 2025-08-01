#include "rectangle.hpp"
#include "geometry_utils.hpp"
#include <iostream>

using namespace geometry;

int main() {
    const Rectangle rect(0.324, 10);

    std::cout << "Rectangle sides: " << rect.get_right_side() << " x " << rect.get_top_side() << std::endl;
    std::cout << "Rectangle area (direct): " << rect.area() << std::endl;
    std::cout << "Rectangle area (via get_area): " << get_area(rect) << std::endl;

    return 0;
}
