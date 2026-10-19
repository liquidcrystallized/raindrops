#include "PlayingState.hpp"
#include "MainMenuState.hpp"
#include "StateMachine.hpp"

namespace raindrops
{
    PlayingState::PlayingState(StateMachine& stateMachine, IGraphics& renderer, IKeyboardInput& keyboardInput, MidiMonitor& midiMonitor, const bool replace)
    : State { stateMachine, renderer, keyboardInput, midiMonitor, replace, "PlayingState" }
    , m_inputMapper { keyboardInput }
    , m_sheetRenderer { renderer }
    {
        std::unique_ptr selectedSong { stateMachine.getSelectedSong() };
        if (selectedSong)
        {
            loadMusicSheet(std::move(selectedSong));
        }
        else if (!m_musicSheet)
        {
            std::println("Warning: No music sheet provided");
        }

        m_sheetRenderer.recalculateStaffElementSizes();
        resume();
    }

    void PlayingState::pause()
    {
        m_conductor.pause();
    }

    void PlayingState::resume()
    {
        m_conductor.resume();
    }

    void PlayingState::update()
    {
        const Action action = m_inputMapper.getTriggeredAction();
        if (action == Action::Back)
        {
            m_stateMachine.lastState();
        }
        if (action == Action::Pause)
        {
            m_conductor.isPlaying() ? pause() : resume();
        }

        m_timer.tick();

        const float dt = m_timer.getDeltaTime();
        m_conductor.update(dt);
    }

    void PlayingState::draw()
    {
        m_renderer.drawStart();

        if (m_musicSheet)
        {
            m_sheetRenderer.render(*m_musicSheet, m_conductor);
        }

        m_renderer.drawEnd();
    }

    void PlayingState::onWindowResize()
    {
        m_sheetRenderer.recalculateStaffElementSizes();
    }

    void PlayingState::loadMusicSheet(std::unique_ptr<MusicSheet> musicSheet)
    {
        m_musicSheet = std::move(musicSheet);
        m_compositionComposer = m_musicSheet->getComposer();
        m_compositionTitle = m_musicSheet->getTitle();
    }
}
