#include "PlayingState.hpp"
#include "MainMenuState.hpp"
#include "StateMachine.hpp"
#include <iostream>

namespace raindrops
{
    PlayingState::PlayingState(StateMachine& stateMachine, raylib::Window& renderWindow, const bool replace)
    : State { stateMachine, renderWindow, replace, "PlayingState" }
    {
        m_testRectangle.SetSize(100, 100);
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
        if (IsKeyPressed(KEY_ESCAPE))
        {
            m_stateMachine.quit();
        }
        else if (IsKeyPressed(KEY_M))
        {
            m_stateMachine.lastState();
        }
    }

    void PlayingState::draw()
    {
        m_renderWindow.BeginDrawing();
        m_renderWindow.ClearBackground();
        m_testRectangle.Draw(raylib::Color::Green());
        m_renderWindow.EndDrawing();
    }
}
