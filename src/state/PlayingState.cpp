#include "PlayingState.hpp"
#include "MainMenuState.hpp"
#include "StateMachine.hpp"
#include <iostream>

namespace raindrops
{
    PlayingState::PlayingState(StateMachine& stateMachine, Renderer& renderer, MidiMonitor& midiMonitor, const bool replace)
    : State { stateMachine, renderer, midiMonitor, replace, "PlayingState" }
    {
        std::cout << "PlayingState Init\n";
    }

    void PlayingState::pause()
    {
        std::cout << "PlayingState Pause\n";
    }

    void PlayingState::resume()
    {
        std::cout << "PlayingState Resume\n";
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
