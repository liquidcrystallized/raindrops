#include "StaffLine.hpp"

namespace raindrops
{
    StaffLine::StaffLine(const int positionY) : m_position { 0, positionY } {}

    int StaffLine::getPositionY() const
    {
        return m_position.getY();
    }

    void StaffLine::setPositionY(const int value)
    {
        m_position.setY(value);
    }
}
