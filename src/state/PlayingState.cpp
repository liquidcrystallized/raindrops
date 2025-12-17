#include "PlayingState.hpp"
#include "MainMenuState.hpp"
#include "StateMachine.hpp"

namespace raindrops
{
    PlayingState::PlayingState(StateMachine& stateMachine, Renderer& renderer, MidiMonitor& midiMonitor, const bool replace)
    : State { stateMachine, renderer, midiMonitor, replace, "PlayingState" }
    {}

    void PlayingState::pause()
    {
        //TODO
    }

    void PlayingState::resume()
    {
        //TODO
    }

    void PlayingState::update()
    {
        if (raylib::Keyboard::IsKeyPressed(KEY_ESCAPE))
        {
            m_stateMachine.lastState();
        }
    }

    void PlayingState::draw()
    {
        m_renderer.drawStart();
        m_renderer.drawEnd();
    }

    void PlayingState::onWindowResize()
    {
        //TODO
    }
}
