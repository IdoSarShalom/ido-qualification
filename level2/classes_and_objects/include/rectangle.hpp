#pragma once

#include "quad.hpp"

namespace geometry {
    class Rectangle final : public Quad {
    public:
        [[nodiscard]] float area() const override;

        explicit Rectangle(float length = DEFAULT_SIDE_VALUE, float width = DEFAULT_SIDE_VALUE);
    };
}
