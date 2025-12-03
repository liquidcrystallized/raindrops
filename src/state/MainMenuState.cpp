#include "MainMenuState.hpp"
#include "PlayingState.hpp"
#include "SettingsMenuState.hpp"
#include "StateMachine.hpp"
#include <raygui-cpp/Utils.h>
#include <iostream>

namespace raindrops
{
    MainMenuState::MainMenuState(StateMachine& stateMachine, raylib::Window& renderWindow, MidiMonitor& midiMonitor, const bool replace)
    : State { stateMachine, renderWindow, midiMonitor, replace, "MainMenuState" }
    {
        m_playButtonText = "Play";
        m_settingsMenuButtonText = "Settings";
        m_quitButtonText = "Quit";

        m_connectedDeviceLabelText = "";

        positionUIComponents();
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

        m_verticalStackPanel.Update();
    }

    void MainMenuState::draw()
    {
        m_renderWindow.BeginDrawing();
        m_renderWindow.ClearBackground(raylib::Color::RayWhite());

        RAYGUI_CPP_UNUSED(m_verticalStackPanel.Show(true));
        RAYGUI_CPP_UNUSED(m_connectedDeviceLabel.Show(true));
        RAYGUI_CPP_UNUSED(m_wipUIWarningLabel.Show(true));

        m_renderWindow.EndDrawing();
    }

    void MainMenuState::onWindowResize()
    {
        positionUIComponents();
    }

    //TODO: Temp programmers UI, implement actual design later.
    void MainMenuState::positionUIComponents()
    {
        m_buttonScalingFactor = 1;

        // Sets the bounds/workspace/position limit for other controls.
        // They should all be rendered inside the bounds of the stack panel.
        m_verticalStackPanelSize  = raylib::Rectangle {
            0,
            0,
            static_cast<float>(m_renderWindow.GetWidth()) / 2.0f,
            static_cast<float>(m_renderWindow.GetHeight()) / 1.5f
        };

        m_verticalStackPanel = VerticalStackPanel(
            rgc::Bounds(
                {
                    this->m_windowCentrePosition.x - m_verticalStackPanelSize.GetWidth() / 2,
                    this->m_windowCentrePosition.y - m_verticalStackPanelSize.GetHeight() / 2
                },
                {
                    m_verticalStackPanelSize.GetWidth(),
                    m_verticalStackPanelSize.GetHeight()
                }
                ),
            "raindrops [dev]"
        );

        // Size and position the button relative to the stack panel.
        m_buttonSize = raylib::Rectangle {
            0,
            0,
            m_verticalStackPanelSize.GetWidth() / 1.1f,
            m_verticalStackPanelSize.GetHeight() / 8.0f
        };

        // Play button positioning and callback.
        m_playButton = rgc::Button(rgc::Bounds::WithText(
            m_playButtonText,
            m_buttonScalingFactor,
            { m_buttonSize.GetWidth() / 2, m_buttonSize.GetHeight() }),
            m_playButtonText);
        m_playButton.SetStyle(rgc::Style(rgc::Style::Position::TOP_CENTER, { 0, m_buttonSize.GetHeight() / 0.5f }));
        m_playButton.OnClick([this]
        {
            //TODO Move to play/song selection screen.
            std::cout << "Play button clicked" << '\n';
        });
        m_verticalStackPanel.AddChild(rgc::ToComponent(&m_playButton));

        // Settings button positioning and callback.
        m_settingsMenuButton = rgc::Button(rgc::Bounds::WithText(
            m_settingsMenuButtonText,
            m_buttonScalingFactor,
            { m_buttonSize.GetWidth() / 2, m_buttonSize.GetHeight() }),
            m_settingsMenuButtonText);
        m_settingsMenuButton.SetStyle(rgc::Style(rgc::Style::Position::CENTER, { 0, 0 }));
        m_settingsMenuButton.OnClick([this]
        {
            m_next = StateMachine::build<SettingsMenuState>(m_stateMachine, m_renderWindow, m_midiMonitor, false);
        });
        m_verticalStackPanel.AddChild(rgc::ToComponent(&m_settingsMenuButton));

        // Quit button positioning and callback.
        m_quitButton = rgc::Button(rgc::Bounds::WithText(
            m_quitButtonText,
            m_buttonScalingFactor,
            { m_buttonSize.GetWidth() / 2, m_buttonSize.GetHeight() }),
            m_quitButtonText);
        m_quitButton.SetStyle(rgc::Style(rgc::Style::Position::BOTTOM_CENTER, { 0, -m_buttonSize.GetHeight() / 0.5f }));
        m_quitButton.OnClick([this]
        {
            m_stateMachine.quit();
        });
        m_verticalStackPanel.AddChild(rgc::ToComponent(&m_quitButton));

        // Show currently connected device.
        m_connectedDeviceLabelText = "Connected device: " + m_midiMonitor.getConnectedDeviceName();
        m_connectedDeviceLabel = rgc::Label{ rgc::Bounds
            { 10, static_cast<float>(m_renderWindow.GetHeight()) - 20.0f, static_cast<float>(m_renderWindow.GetWidth()), 10 },
            m_connectedDeviceLabelText.c_str() };
        m_connectedDeviceLabel.SetStyle(rgc::Style(rgc::Style::Position::CENTER, { 0, 0 }));

        // Mostly temporary.
        m_wipUIWarningLabel = rgc::Label{ rgc::Bounds
            { 10, 10, 1000, 10 },
            "The menu UI is temporary for testing and will be completely revamped closer to 1.0"
        };
    }
}
