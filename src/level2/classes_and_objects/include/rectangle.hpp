#pragma once

#include "quad.hpp"

namespace geometry {
    class Rectangle final : public Quad {
    public:
        [[nodiscard]] float area() const override;
    };
}
