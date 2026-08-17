#include "Conductor.hpp"

namespace raindrops
{
    Conductor::Conductor()
    {
        reset();
    }

    void Conductor::setMusicSheet(std::unique_ptr<MusicSheet> musicSheet)
    {
        m_musicSheet = std::move(musicSheet);
        reset();
    }

    void Conductor::update(float deltaTime)
    {
        if (!m_playing || !m_musicSheet)
        {
            return;
        }

        m_scrollOffset += m_scrollSpeed * deltaTime;
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
        m_scrollOffset = -1000.0f;
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
        m_scrollOffset = std::max(-1000.0f, offset);
    }

    float Conductor::getScrollSpeed() const
    {
        return m_scrollSpeed;
    }

    void Conductor::setScrollSpeed(const float speed)
    {
        m_scrollSpeed = std::max(0.0f, speed);
    }

    void Conductor::reset()
    {
        m_scrollOffset = -1000.0f;
        m_playing = false;
    }
}
