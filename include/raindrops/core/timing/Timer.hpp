#ifndef RAINDROPS_TIMER_HPP
#define RAINDROPS_TIMER_HPP

#include <chrono>

namespace raindrops
{
    class Timer {
    public:
        Timer();

        [[nodiscard]] float getDeltaTime() const;

        void tick();

    private:
        std::chrono::time_point<std::chrono::steady_clock> m_previous {};
        float m_deltaTime {};
    };
}


#endif //RAINDROPS_TIMER_HPP