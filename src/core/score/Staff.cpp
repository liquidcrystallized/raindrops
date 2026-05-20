#include "Staff.hpp"

namespace raindrops
{
    Staff::Staff(const int firstLinePosition, const int lineSpacing, const int numberOfLines)
    {
        int currentLinePosition = firstLinePosition;
        for (int i = 0; i < numberOfLines; i++)
        {
            StaffLine staffLine { currentLinePosition };
            m_staffLines.push_back(staffLine);
            currentLinePosition += lineSpacing;
        }
    }

    const std::vector<StaffLine>& Staff::getLines() const
    {
        return m_staffLines;
    }

    int Staff::getNumberOfLines() const
    {
        return m_staffLines.size();
    }
}
