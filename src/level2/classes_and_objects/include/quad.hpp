#pragma once

namespace geometry {
    class Quad {
    protected:
        float side1 = 0, side2 = 0, side3 = 0, side4 = 0;

    public:
        virtual ~Quad() = default;

        [[nodiscard]] virtual float area() const = 0;

        void set_side1(const float side1) { this->side1 = side1; }
        void set_side2(const float side2) { this->side2 = side2; }
        void set_side3(const float side3) { this->side3 = side3; }
        void set_side4(const float side4) { this->side4 = side4; }

        [[nodiscard]] float get_side1() const { return side1; }
        [[nodiscard]] float get_side2() const { return side2; }
        [[nodiscard]] float get_side3() const { return side3; }
        [[nodiscard]] float get_side4() const { return side4; }
    };
}