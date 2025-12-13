#ifndef RAINDROPS_VECTOR2_HPP
#define RAINDROPS_VECTOR2_HPP


namespace raindrops
{
    /**
     * Represents two arbitrary points, or values, that
     * have some sort of relation with each other.
     */
    class Vector2 {
    public:
        Vector2(float x, float y);

        [[nodiscard]] float getX() const;
        void setX(float);

        [[nodiscard]] float getY() const;
        void setY(float);

    private:
        float m_x;
        float m_y;
    };
}


#endif //RAINDROPS_VECTOR2_HPP