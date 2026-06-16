#include "StaffLine.hpp"

namespace raindrops
{
    StaffLine::StaffLine(const int positionY, const bool isVisible)
    : m_position { 0, positionY }, m_isVisible { isVisible } {}

    int StaffLine::getPositionY() const
    {
        return m_position.getY();
    }

    void StaffLine::setPositionY(const int value)
    {
        m_position.setY(value);
    }

    bool StaffLine::isVisible() const
    {
        return m_isVisible;
    }

    void StaffLine::setVisible(const bool visible)
    {
        m_isVisible = visible;
    }
}
