#include "core/math/Vector2.hpp"

namespace raindrops
{
    Vector2::Vector2(const float x, const float y) : m_x { x }, m_y { y } {}

    float Vector2::getX() const
    {
        return m_x;
    }

    void Vector2::setX(const float x)
    {
        m_x = x;
    }

    float Vector2::getY() const
    {
        return m_y;
    }

    void Vector2::setY(const float y)
    {
        m_y = y;
    }
}
