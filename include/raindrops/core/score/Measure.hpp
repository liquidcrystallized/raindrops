#ifndef RAINDROPS_MEASURE_HPP
#define RAINDROPS_MEASURE_HPP


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

        [[nodiscard]] bool hasEndLine() const;
        void setHasEndLine(bool hasEndLine);

        [[nodiscard]] int getTempoInBPM() const;
        void setTempoInBPM(int number);
    private:
        int m_measureNumber {};
        bool m_hasAttributes {};
        bool m_hasEndLine {};
        int m_tempoInBPM {};
    };
}


#endif //RAINDROPS_MEASURE_HPP