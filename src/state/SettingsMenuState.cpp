#include "SettingsMenuState.hpp"
#include <iostream>

#include "StateMachine.hpp"

namespace raindrops
{
    SettingsMenuState::SettingsMenuState(StateMachine& stateMachine, raylib::Window& renderWindow, const bool replace)
    : State { stateMachine, renderWindow, replace }
    {
        m_testRectangle.SetSize(100, 100);
        std::cout << "SettingsMenuState Init\n";
    }

    void SettingsMenuState::pause()
    {
        std::cout << "SettingsMenuState Pause\n";
    }

    void SettingsMenuState::resume()
    {
        std::cout << "SettingsMenuState Resume\n";
    }

    void SettingsMenuState::update()
    {
        if (IsKeyPressed(KEY_ESCAPE))
        {
            m_stateMachine.quit();
        }
        else if (IsKeyPressed(KEY_N))
        {
            m_stateMachine.lastState();
        }
    }

    void SettingsMenuState::draw()
    {
        m_renderWindow.BeginDrawing();
        m_renderWindow.ClearBackground();
        m_testRectangle.Draw(raylib::Color::Blue());
        m_renderWindow.EndDrawing();
    }
}
