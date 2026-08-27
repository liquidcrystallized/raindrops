#ifndef RAINDROPS_TIMER_HPP
#define RAINDROPS_TIMER_HPP

#include <chrono>

namespace raindrops
{
    class Timer {
    public:
        Timer();

        float getDeltaTime();

    private:
        std::chrono::time_point<std::chrono::steady_clock> m_previous {};
    };
}


#endif //RAINDROPS_TIMER_HPP