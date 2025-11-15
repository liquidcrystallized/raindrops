#include "SettingsMenuState.hpp"
#include <iostream>

#include "StateMachine.hpp"

namespace raindrops
{
    SettingsMenuState::SettingsMenuState(StateMachine& stateMachine, raylib::Window& renderWindow, const bool replace)
    : State { stateMachine, renderWindow, replace, "SettingsMenuState" }
    {
        setupUI();
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
            m_stateMachine.lastState();
        }

        m_backButton.Update();
    }

    void SettingsMenuState::draw()
    {
        m_renderWindow.BeginDrawing();
        m_renderWindow.ClearBackground(raylib::Color::RayWhite());

        RAYGUI_CPP_UNUSED(m_backButton.Show(m_backButtonCanClick));

        m_renderWindow.EndDrawing();
    }

    //TODO: Temp programmers UI, implement actual design later
    void SettingsMenuState::setupUI()
    {
        const float buttonWidth { static_cast<float>(m_renderWindow.GetWidth()) / 4.0f };
        const float buttonHeight { static_cast<float>(m_renderWindow.GetHeight()) / 8.0f };
        constexpr int fontSize { 22 };
        const rgc::Margin textMargin { buttonWidth, buttonHeight };

        // Settings button initialisation and callback setup.
        m_backButtonText = "Back";
        m_backButton = rgc::Button(rgc::Bounds::WithText(m_backButtonText, fontSize, textMargin), m_backButtonText);
        m_backButton.SetStyle(rgc::Style(rgc::Style::Position::CENTER, { 0, 0 }));
        m_backButton.OnClick([this]
        {
            m_stateMachine.lastState();
        });
        m_backButtonCanClick = true;
    }
}
