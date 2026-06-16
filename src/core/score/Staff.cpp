#include "Staff.hpp"

namespace raindrops
{
    Staff::Staff(const int firstLinePositionY, const int lineSpacing)
    {
        m_staffLines.reserve(16);
        int currentLinePosition = firstLinePositionY;

        // There are technically lines between the treble and bass clef on an actual music sheet.
        // But they are generally not visible unless there happens to be a note there, and even then,
        // only a tiny part of the line beneath the note is visible.
        // So they'll still need to be tracked but not rendered.
        for (int i = 0; i < 16; i++)
        {
            // Treble clef: 0-4, Bass clef: 11-15
            bool isClefLine = i < 5 || i >= 11;
            m_staffLines.emplace_back(currentLinePosition, isClefLine);
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
