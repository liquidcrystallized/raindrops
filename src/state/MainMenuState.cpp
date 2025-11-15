#include "MainMenuState.hpp"
#include "PlayingState.hpp"
#include "SettingsMenuState.hpp"
#include "StateMachine.hpp"
#include <iostream>

#include "raygui-cpp/Utils.h"

namespace raindrops
{
    MainMenuState::MainMenuState(StateMachine& stateMachine, raylib::Window& renderWindow, const bool replace)
    : State { stateMachine, renderWindow, replace, "MainMenuState" }
    {
        setupUI();
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
            m_stateMachine.quit();
        }

        m_settingsMenuButton.Update();
        m_quitButton.Update();
    }

    void MainMenuState::draw()
    {
        m_renderWindow.BeginDrawing();
        m_renderWindow.ClearBackground(raylib::Color::RayWhite());

        RAYGUI_CPP_UNUSED(m_settingsMenuButton.Show(m_settingsMenuButtonCanClick));
        RAYGUI_CPP_UNUSED(m_quitButton.Show(m_quitButtonCanClick));

        m_renderWindow.EndDrawing();
    }

    //TODO: Temp programmers UI, implement actual design later
    void MainMenuState::setupUI()
    {
        // Size buttons based on screen resolution
        const float buttonWidth { static_cast<float>(m_renderWindow.GetWidth()) / 4.0f };
        const float buttonHeight { static_cast<float>(m_renderWindow.GetHeight()) / 8.0f };
        constexpr int fontSize { 22 };
        const rgc::Margin textMargin { buttonWidth, buttonHeight };

        // Settings button initialisation and callback setup.
        m_settingsMenuButtonText = "Settings";
        m_settingsMenuButton = rgc::Button(rgc::Bounds::WithText(m_settingsMenuButtonText, fontSize, textMargin), m_settingsMenuButtonText);
        m_settingsMenuButton.SetStyle(rgc::Style(rgc::Style::Position::CENTER, { 0, 0 }));
        m_settingsMenuButton.OnClick([this]
        {
            m_next = StateMachine::build<SettingsMenuState>(m_stateMachine, m_renderWindow, false);
        });
        m_settingsMenuButtonCanClick = true;

        // Quit button initialisation and callback setup.
        m_quitButtonText = "Quit";
        m_quitButton = rgc::Button(rgc::Bounds::WithText(m_quitButtonText, fontSize, textMargin), m_quitButtonText);
        m_quitButton.SetStyle(rgc::Style(rgc::Style::Position::CENTER, { 0, buttonHeight * 2 }));
        m_quitButton.OnClick([this]
        {
            m_stateMachine.quit();
        });
        m_quitButtonCanClick = true;
    }
}
