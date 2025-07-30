#include "rectangle.hpp"

namespace geometry {
    float Rectangle::area() const override {
        return side1 * side2;
    }
}
