#ifndef RAINDROPS_PLAYINGSTATE_HPP
#define RAINDROPS_PLAYINGSTATE_HPP

#include "Conductor.hpp"
#include "InputMapper.hpp"
#include "MusicSheet.hpp"
#include "MusicSheetRenderer.hpp"
#include "State.hpp"
#include "Timer.hpp"

namespace raindrops
{
    class PlayingState final : public State {
    public:
        PlayingState(StateMachine&, IGraphics&, IKeyboardInput&, MidiMonitor&, bool replace = true);

        void pause() override;
        void resume() override;

        void update() override;
        void draw() override;

        void onWindowResize() override;

        void loadMusicSheet(std::unique_ptr<MusicSheet> musicSheet);
    private:
        std::unique_ptr<MusicSheet> m_musicSheet;
        std::string m_compositionComposer {};
        std::string m_compositionTitle {};

        Conductor m_conductor {};
        Timer m_timer {};

        InputMapper m_inputMapper;
        MusicSheetRenderer m_sheetRenderer;
    };
}


#endif //RAINDROPS_PLAYINGSTATE_HPP