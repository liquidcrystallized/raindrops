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

    bool Conductor::isPlaying() const
    {
        return m_playing;
    }

    float Conductor::getScrollOffset() const
    {
        return m_scrollOffset;
    }

    float Conductor::getScrollSpeed() const
    {
        return m_scrollSpeed;
    }

    void Conductor::reset()
    {
        m_scrollOffset = -1000.0f;
        m_playing = false;
    }
}
