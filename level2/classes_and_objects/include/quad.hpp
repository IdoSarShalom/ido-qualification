#pragma once
#include <string>

namespace geometry {
    constexpr float DEFAULT_SIDE_VALUE = 0.0f;

    enum class QuadSide {
        TOP,
        BOTTOM,
        LEFT,
        RIGHT
    };

    struct Side {
        float value;
        QuadSide quad_side;

        Side(const float value, const QuadSide quad_side) : value(value), quad_side(quad_side) {
        }
    };

    class Quad {
    protected:
        Side top_side;
        Side bottom_side;
        Side right_side;
        Side left_side;

    public:
        virtual ~Quad() = default;

        explicit Quad(float top_side = DEFAULT_SIDE_VALUE,
                      float bottom_side = DEFAULT_SIDE_VALUE,
                      float right_side = DEFAULT_SIDE_VALUE,
                      float left_side = DEFAULT_SIDE_VALUE);

        [[nodiscard]] virtual float area() const = 0;

        void set_top_side(float top_side);

        void set_bottom_side(float bottom_side);

        void set_right_side(float right_side);

        void set_left_side(float left_side);

        [[nodiscard]] float get_top_side() const { return top_side.value; }
        [[nodiscard]] float get_bottom_side() const { return bottom_side.value; }
        [[nodiscard]] float get_right_side() const { return right_side.value; }
        [[nodiscard]] float get_left_side() const { return left_side.value; }

    private:
        static bool validate(float value, const QuadSide &quad_side);

        static void set_side(Side &side, float value);
    };
}
