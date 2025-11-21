#include "MidiSetupMenuState.hpp"
#include "StateMachine.hpp"
#include <raygui-cpp/Utils.h>
#include <iostream>

namespace raindrops
{
    MidiSetupMenuState::MidiSetupMenuState(StateMachine& stateMachine, raylib::Window& renderWindow, const bool replace)
    : State { stateMachine, renderWindow, replace, "MidiSetupMenuState" }
    {
        m_backButtonText = "Back";

        positionUIComponents();
        std::cout << "MidiSetupMenuState Init\n";
    }

    void MidiSetupMenuState::pause()
    {
        std::cout << "MidiSetupMenuState Pause\n";
    }

    void MidiSetupMenuState::resume()
    {
        std::cout << "MidiSetupMenuState Resume\n";
    }

    void MidiSetupMenuState::update()
    {
        if (IsKeyPressed(KEY_ESCAPE))
        {
            m_stateMachine.lastState();
        }

        m_verticalStackPanel.Update();
    }

    void MidiSetupMenuState::draw()
    {
        m_renderWindow.BeginDrawing();
        m_renderWindow.ClearBackground(raylib::Color::RayWhite());

        RAYGUI_CPP_UNUSED(m_verticalStackPanel.Show(true));

        m_renderWindow.EndDrawing();
    }

    void MidiSetupMenuState::onWindowResize()
    {
        positionUIComponents();
    }

    void MidiSetupMenuState::positionUIComponents()
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
            "midi setup"
        );

        // Size and position the button relative to the stack panel.
        m_buttonSize = raylib::Rectangle {
            0,
            0,
            m_verticalStackPanelSize.GetWidth() / 1.1f,
            m_verticalStackPanelSize.GetHeight() / 8.0f
        };

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
    }
}
