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
        m_measureNumber = number;
    }

    bool Measure::hasEndLine() const
    {
        return m_hasEndLine;
    }

    void Measure::setHasEndLine(const bool hasEndLine)
    {
        m_hasEndLine = hasEndLine;
    }

    int Measure::getTempoInBPM() const
    {
        return m_tempoInBPM;
    }

    void Measure::setTempoInBPM(const int number)
    {
        m_tempoInBPM = number;
    }
}
