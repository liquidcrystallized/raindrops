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

    private:
        int m_measureNumber {};
    };
}


#endif //RAINDROPS_MEASURE_HPP