#include "SettingsMenuState.hpp"
#include "MidiSetupMenuState.hpp"
#include "StateMachine.hpp"
#include <raygui-cpp/Utils.h>
#include <iostream>

namespace raindrops
{
    SettingsMenuState::SettingsMenuState(StateMachine& stateMachine, Renderer& renderer, MidiMonitor& midiMonitor, const bool replace)
    : State { stateMachine, renderer, midiMonitor, replace, "SettingsMenuState" }
    {
        m_midiSetupMenuButtonText = "Midi Setup";
        m_backButtonText = "Back";

        positionUIComponents();
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
        if (raylib::Keyboard::IsKeyPressed(KEY_ESCAPE))
        {
            m_stateMachine.lastState();
        }

        m_connectedDeviceLabelText = "Connected device: " + m_midiMonitor.getConnectedDeviceName();
        m_connectedDeviceLabel.SetText(m_connectedDeviceLabelText.c_str());

        m_verticalStackPanel.Update();
    }

    void SettingsMenuState::draw()
    {
        m_renderer.drawStart();

        RAYGUI_CPP_UNUSED(m_verticalStackPanel.Show(true));
        RAYGUI_CPP_UNUSED(m_connectedDeviceLabel.Show(true));

        m_renderer.drawEnd();
    }

    void SettingsMenuState::onWindowResize()
    {
        positionUIComponents();
    }

    //TODO: Temp programmers UI, implement actual design later, throw it into the renderer
    void SettingsMenuState::positionUIComponents()
    {
        m_buttonScalingFactor = 1;

        // Sets the bounds/workspace/position limit for other controls.
        // They should all be rendered inside the bounds of the stack panel.
        m_verticalStackPanelSize  = raylib::Rectangle {
            0,
            0,
            static_cast<float>(m_renderer.getWindowWidth()) / 2.0f,
            static_cast<float>(m_renderer.getWindowHeight()) / 1.5f
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
            "settings"
        );

        // Size and position the button relative to the stack panel.
        m_buttonSize = raylib::Rectangle {
            0,
            0,
            m_verticalStackPanelSize.GetWidth() / 1.1f,
            m_verticalStackPanelSize.GetHeight() / 8.0f
        };

        // Midi setup menu button positioning and callback.
        m_midiSetupMenuButton = rgc::Button(rgc::Bounds::WithText(
            m_midiSetupMenuButtonText,
            m_buttonScalingFactor,
            { m_buttonSize.GetWidth() / 2, m_buttonSize.GetHeight() }),
            m_midiSetupMenuButtonText);
        m_midiSetupMenuButton.SetStyle(rgc::Style(rgc::Style::Position::CENTER, { 0, 0 }));
        m_midiSetupMenuButton.OnClick([this]
        {
            m_next = StateMachine::build<MidiSetupMenuState>(m_stateMachine, m_renderer, m_midiMonitor, false);
        });
        m_verticalStackPanel.AddChild(rgc::ToComponent(&m_midiSetupMenuButton));

        // Back button positioning and callback.
        m_backButton = rgc::Button(rgc::Bounds::WithText(
            m_backButtonText,
            m_buttonScalingFactor,
            { m_buttonSize.GetWidth() / 2, m_buttonSize.GetHeight() }),
            m_backButtonText);
        m_backButton.SetStyle(rgc::Style(rgc::Style::Position::BOTTOM_CENTER, { 0, -m_buttonSize.GetHeight() / 0.5f }));
        m_backButton.OnClick([this]
        {
            m_stateMachine.lastState();
        });
        m_verticalStackPanel.AddChild(rgc::ToComponent(&m_backButton));

        // Show currently connected device.
        m_connectedDeviceLabel = rgc::Label{ rgc::Bounds
            { 10, static_cast<float>(m_renderer.getWindowHeight()) - 20.0f, static_cast<float>(m_renderer.getWindowWidth()), 10 },
            m_connectedDeviceLabelText.c_str() };
        m_connectedDeviceLabel.SetStyle(rgc::Style(rgc::Style::Position::CENTER, { 0, 0 }));
    }
}
