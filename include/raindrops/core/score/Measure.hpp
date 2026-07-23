#ifndef RAINDROPS_MEASURE_HPP
#define RAINDROPS_MEASURE_HPP

#include "Note.hpp"
#include <vector>

namespace raindrops
{
    /**
     * @brief Represents the data of a unique measure. Each measure
     * should correspond to one XML measure or per paper sheet measure.
     */
    class Measure {
    public:
        Measure();

        [[nodiscard]] int getMeasureNumber() const;
        void setMeasureNumber(int number);

        [[nodiscard]] const std::vector<Note>& getNotes() const;
        void addNote(const Note& note);

    private:
        int m_measureNumber {};
        std::vector<Note> m_notes {};
    };
}


#endif //RAINDROPS_MEASURE_HPP