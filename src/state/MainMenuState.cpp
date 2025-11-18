#include "MainMenuState.hpp"
#include "PlayingState.hpp"
#include "SettingsMenuState.hpp"
#include "StateMachine.hpp"
#include <raygui-cpp/Utils.h>
#include <iostream>

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

        RAYGUI_CPP_UNUSED(m_verticalStackPanel.Show(true));

        m_renderWindow.EndDrawing();
    }

    void MainMenuState::onWindowResize()
    {
        std::cout << "Window resizing" << '\n';
    }

    //TODO: Temp programmers UI, implement actual design later
    void MainMenuState::setupUI()
    {
        // Size and position stack panel based on render window size.
        const raylib::Vector2 verticalStackPanelSize {
            static_cast<float>(m_renderWindow.GetWidth()) / 3.0f,
            static_cast<float>(m_renderWindow.GetHeight()) / 1.2f
        };

        const raylib::Vector2 verticalStackPanelMidpointSnap {
            (static_cast<float>(m_renderWindow.GetWidth()) / 2.0f) - (verticalStackPanelSize.x / 2),
            (static_cast<float>(m_renderWindow.GetHeight()) / 2.0f) - (verticalStackPanelSize.y / 2)
        };

        m_verticalStackPanel = VerticalStackPanel(
            rgc::Bounds({verticalStackPanelMidpointSnap.x,verticalStackPanelMidpointSnap.y},
            {verticalStackPanelSize.x, verticalStackPanelSize.y}),
            "raindrops [dev]");

        // Button sizing and positioning
        const raylib::Vector2 buttonSize {
            (verticalStackPanelSize.x / 1.5f),
            verticalStackPanelSize.y / 6.0f
        };
        constexpr int fontSize { 22 };

        // Settings button initialisation and callback setup.
        m_settingsMenuButtonText = "Settings";
        m_settingsMenuButton = rgc::Button(rgc::Bounds::WithText(m_settingsMenuButtonText, fontSize, { buttonSize.x, buttonSize.y }), m_settingsMenuButtonText);
        m_settingsMenuButton.SetStyle(rgc::Style(rgc::Style::Position::CENTER, { 0, 0 }));
        m_settingsMenuButton.OnClick([this]
        {
            m_next = StateMachine::build<SettingsMenuState>(m_stateMachine, m_renderWindow, false);
        });
        m_verticalStackPanel.AddChild(rgc::ToComponent(&m_settingsMenuButton));

        // Quit button initialisation and callback setup.
        m_quitButtonText = "Quit";
        m_quitButton = rgc::Button(rgc::Bounds::WithText(m_quitButtonText, fontSize, { buttonSize.x, buttonSize.y }), m_quitButtonText);
        m_quitButton.SetStyle(rgc::Style(rgc::Style::Position::CENTER, { 0, buttonSize.y }));
        m_quitButton.OnClick([this]
        {
            m_stateMachine.quit();
        });
        m_verticalStackPanel.AddChild(rgc::ToComponent(&m_quitButton));
    }
}
