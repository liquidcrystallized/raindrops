#ifndef RAINDROPS_CONDUCTOR_HPP
#define RAINDROPS_CONDUCTOR_HPP

#include "MusicSheet.hpp"
#include <memory>

namespace raindrops
{
    /**
     * @brief Mostly handles playback and scrolling.
     */
    class Conductor {
    public:
        Conductor();

        void setMusicSheet(std::unique_ptr<MusicSheet> musicSheet);

    private:
        std::unique_ptr<MusicSheet> m_musicSheet {};

        float m_scrollOffset { 0.0f };
        float m_scrollSpeed { 100.0f };
        bool m_playing { false };
    };
}


#endif //RAINDROPS_CONDUCTOR_HPP