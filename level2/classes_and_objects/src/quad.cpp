#include "quad.hpp"
#include <iostream>

namespace geometry {
    std::string quadSideToString(const QuadSide &side) {
        switch (side) {
            case QuadSide::TOP: return "TOP";
            case QuadSide::BOTTOM: return "BOTTOM";
            case QuadSide::LEFT: return "LEFT";
            case QuadSide::RIGHT: return "RIGHT";
            default: return "UNKNOWN";
        }
    }

    bool Quad::validate(const float value, const QuadSide& quad_side) {
        if (value < 0.0f) {
            std::cerr << "Warning: " << quadSideToString(quad_side)
                    << " side must be non-negative (got " << value << "), defaulting to "
                    << DEFAULT_SIDE_VALUE << '\n';
            return false;
        }
        return true;
    }

    Quad::Quad(const float top_side, const float bottom_side, const float right_side, const float left_side)
        : top_side{validate(top_side, QuadSide::TOP) ? top_side : DEFAULT_SIDE_VALUE, QuadSide::TOP},
          bottom_side{validate(bottom_side, QuadSide::BOTTOM) ? bottom_side : DEFAULT_SIDE_VALUE, QuadSide::BOTTOM},
          right_side{validate(right_side, QuadSide::RIGHT) ? right_side : DEFAULT_SIDE_VALUE, QuadSide::RIGHT},
          left_side{validate(left_side, QuadSide::LEFT) ? left_side : DEFAULT_SIDE_VALUE, QuadSide::LEFT} {
    }

    void Quad::set_side(Side &side, const float value) {
        if (validate(value, side.quad_side)) {
            side.value = value;
        } else {
            side.value = DEFAULT_SIDE_VALUE;
        }
    }

    void Quad::set_top_side(const float top_side) {
        set_side(this->top_side, top_side);
    }

    void Quad::set_bottom_side(const float bottom_side) {
        set_side(this->bottom_side, bottom_side);
    }

    void Quad::set_right_side(const float right_side) {
        set_side(this->right_side, right_side);
    }

    void Quad::set_left_side(const float left_side) {
        set_side(this->left_side, left_side);
    }
}
