#include "Measure.hpp"

namespace raindrops
{
    Measure::Measure() = default;

    int Measure::getMeasureNumber() const
    {
        return m_measureNumber;
    }

    void Measure::setMeasureNumber(const int number)
    {
        if (number < 0)
        {
            m_measureNumber = -1;
        }
        else
        {
            m_measureNumber = number;
        }
    }

    const std::vector<Note>& Measure::getNotes() const
    {
        return m_notes;
    }

    void Measure::addNote(const Note& note)
    {
        m_notes.push_back(note);
    }
}
