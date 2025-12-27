#include "core/math/Vector2.hpp"

namespace raindrops
{
    template<Number T>
    Vector2<T>::Vector2(T const x, T const y) : m_x { x }, m_y { y } {}

    template<Number T>
    T Vector2<T>::getX() const
    {
        return m_x;
    }

    template<Number T>
    void Vector2<T>::setX(T const x)
    {
        m_x = x;
    }

    template<Number T>
    T Vector2<T>::getY() const
    {
        return m_y;
    }

    template<Number T>
    void Vector2<T>::setY(T const y)
    {
        m_y = y;
    }
}
