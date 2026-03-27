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
}
