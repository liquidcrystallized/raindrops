#include "Conductor.hpp"

namespace raindrops
{
    Conductor::Conductor()
    {
        reset();
    }

    void Conductor::update(const float deltaTime)
    {
        if (!m_playing)
        {
            return;
        }

        m_scrollOffset += m_scrollSpeed * deltaTime;

        if (m_scrollOffset >= std::numeric_limits<float>::max())
        {
            m_scrollSpeed = 0.0f;
            m_scrollOffset = std::numeric_limits<float>::max();
        }
    }

    void Conductor::pause()
    {
        m_playing = false;
    }

    void Conductor::resume()
    {
        m_playing = true;
    }

    void Conductor::stop()
    {
        m_playing = false;
        m_scrollOffset = m_songStartScrollBuffer;
    }

    bool Conductor::isPlaying() const
    {
        return m_playing;
    }

    float Conductor::getScrollOffset() const
    {
        return m_scrollOffset;
    }

    void Conductor::setScrollOffset(const float offset)
    {
        m_scrollOffset = std::clamp(offset, m_songStartScrollBuffer, std::numeric_limits<float>::max());
    }

    float Conductor::getScrollSpeed() const
    {
        return m_scrollSpeed;
    }

    void Conductor::setScrollSpeed(const float speed)
    {
        m_scrollSpeed = std::clamp(speed, 0.0f, std::numeric_limits<float>::max());
    }

    float Conductor::getSongStartScrollBuffer() const
    {
        return m_songStartScrollBuffer;
    }

    void Conductor::setSongStartScrollBuffer(const float buffer)
    {
        m_songStartScrollBuffer = std::clamp(buffer, std::numeric_limits<float>::lowest(), 0.0f);
    }

    void Conductor::reset()
    {
        m_playing = false;
        m_scrollOffset = m_songStartScrollBuffer;
    }
}
