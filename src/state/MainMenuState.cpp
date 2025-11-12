#include "MainMenuState.hpp"
#include "PlayingState.hpp"
#include "StateMachine.hpp"
#include <iostream>

namespace raindrops
{
    MainMenuState::MainMenuState(StateMachine& stateMachine, raylib::Window& renderWindow, const bool replace)
    : State { stateMachine, renderWindow, replace, "MainMenuState" }
    {
        m_testRectangle.SetSize(100, 100);
        std::cout << "MainMenuState Init\n";
    }

    void MainMenuState::pause()
    {
        std::cout << "MainMenuState Pause\n";
    }

    void MainMenuState::resume()
    {
        std::cout << "MainMenuState Resume\n";
    }

    void MainMenuState::update()
    {
        if (IsKeyPressed(KEY_ESCAPE))
        {
            m_stateMachine.lastState();
        }
        else if (IsKeyPressed(KEY_M))
        {
            m_next = StateMachine::build<PlayingState>(m_stateMachine, m_renderWindow, false);
        }
    }

    void MainMenuState::draw()
    {
        m_renderWindow.BeginDrawing();
        m_renderWindow.ClearBackground();
        m_testRectangle.Draw(raylib::Color::Red());
        m_renderWindow.EndDrawing();
    }
}
