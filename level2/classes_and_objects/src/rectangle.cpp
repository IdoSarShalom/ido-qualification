#include "rectangle.hpp"

namespace geometry {
    float Rectangle::area() const {
        return right_side.value * top_side.value;
    }

    Rectangle::Rectangle(const float length, const float width)
        : Quad(width, width, length, length) {
    }
}
