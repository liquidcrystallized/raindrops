#include "Conductor.hpp"

namespace raindrops
{
    Conductor::Conductor()
    {
        //
    }

    void Conductor::setMusicSheet(std::unique_ptr<MusicSheet> musicSheet)
    {
        m_musicSheet = std::move(musicSheet);
    }
}
