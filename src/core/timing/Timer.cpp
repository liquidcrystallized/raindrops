#include "Timer.hpp"

namespace raindrops
{
    Timer::Timer() : m_previous { std::chrono::steady_clock::now() } {}

    float Timer::getDeltaTime()
    {
        const std::chrono::time_point<std::chrono::steady_clock> now = std::chrono::steady_clock::now();
        const float delta = std::chrono::duration<float>(now - m_previous).count();
        m_previous = now;
        return delta;
    }
}
