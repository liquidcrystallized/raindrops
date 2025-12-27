#ifndef RAINDROPS_VECTOR2_HPP
#define RAINDROPS_VECTOR2_HPP

#include <concepts>

namespace raindrops
{
    template<typename T>
    concept Scalar = std::integral<T> || std::floating_point<T>;

    /**
     * Represents two arbitrary points, or values, that
     * have some sort of relation with each other.
     */
    template<Scalar T>
    class Vector2 {
    public:
        Vector2(T x, T y);

        [[nodiscard]] T getX() const;
        void setX(T);

        [[nodiscard]] T getY() const;
        void setY(T);

    private:
        T m_x;
        T m_y;
    };
}


#endif //RAINDROPS_VECTOR2_HPP