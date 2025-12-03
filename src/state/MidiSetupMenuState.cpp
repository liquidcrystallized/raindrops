#include "MidiSetupMenuState.hpp"
#include "StateMachine.hpp"
#include <raygui-cpp/Utils.h>
#include <cstring>
#include <iostream>

namespace raindrops
{
    MidiSetupMenuState::MidiSetupMenuState(StateMachine& stateMachine, raylib::Window& renderWindow, MidiMonitor& midiMonitor, const bool replace)
    : State { stateMachine, renderWindow, midiMonitor, replace, "MidiSetupMenuState" }
    {
        m_midiDeviceListViewText = "Lorem;Ipsum;Dolor;Sit;Amet;Consectetuer";
        m_midiDeviceListViewScrollIndex = 1;
        m_midiDeviceListViewActiveSelection = 0;

        m_applyButtonText = "Apply";
        m_backButtonText = "Back";
        m_refreshButtonText = "Refresh";

        refreshMidiDevices();
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
        if (raylib::Keyboard::IsKeyPressed(KEY_ESCAPE))
        {
            m_stateMachine.lastState();
        }

        m_verticalStackPanel.Update();
        m_midiDeviceListView.Update();
    }

    void MidiSetupMenuState::draw()
    {
        m_renderWindow.BeginDrawing();
        m_renderWindow.ClearBackground(raylib::Color::RayWhite());

        RAYGUI_CPP_UNUSED(m_verticalStackPanel.Show(true));
        RAYGUI_CPP_UNUSED(m_midiDeviceListView.Show(true));
        RAYGUI_CPP_UNUSED(m_connectedDeviceLabel.Show(true));

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

        // Set another vertical stack panel inside.
        m_innerVerticalStackPanelSize = raylib::Rectangle {
            0,
            0,
            m_verticalStackPanelSize.GetWidth() / 1.2f,
           m_verticalStackPanelSize.GetHeight() / 1.5f
        };

        m_innerVerticalStackPanel = VerticalStackPanel(
            rgc::Bounds(
                {
                    0,
                    0
                },
                {
                    m_innerVerticalStackPanelSize.GetWidth(),
                   m_innerVerticalStackPanelSize.GetHeight()
                }
            ),
            "select midi device"
        );

        m_innerVerticalStackPanel.SetStyle(rgc::Style(rgc::Style::Position::TOP_CENTER, { 0, m_innerVerticalStackPanelSize.GetHeight() / 12.0f }));
        m_verticalStackPanel.AddChild(rgc::ToComponent(&m_innerVerticalStackPanel));

        // List view for all connected midi devices.
        m_midiDeviceListViewBounds = rgc::Bounds {
            {
                0,
                0
            },
            {
                m_innerVerticalStackPanelSize.GetWidth() / 1.1f,
                m_innerVerticalStackPanelSize.GetHeight() / 1.2f
            }
        };
        m_midiDeviceListView = rgc::ListView(m_midiDeviceListViewBounds, m_midiDeviceListViewText, &m_midiDeviceListViewScrollIndex, m_midiDeviceListViewActiveSelection);
        m_midiDeviceListView.SetStyle(rgc::Style(rgc::Style::Position::CENTER, { 0, -m_innerVerticalStackPanelSize.GetHeight() / 5.0f }));

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
            { m_buttonSize.GetWidth() / 4, m_buttonSize.GetHeight() }),
            m_backButtonText);
        m_backButton.SetStyle(rgc::Style(rgc::Style::Position::BOTTOM_CENTER, { -m_buttonSize.GetWidth() / 5.0f, -m_verticalStackPanelSize.GetHeight() / 12.0f }));
        m_backButton.OnClick([this]
        {
            m_stateMachine.lastState();
        });
        m_verticalStackPanel.AddChild(rgc::ToComponent(&m_backButton));

        // Refresh button positioning and callback.
        m_refreshButton = rgc::Button(rgc::Bounds::WithText(
            m_refreshButtonText,
            m_buttonScalingFactor,
            { m_buttonSize.GetWidth() / 4, m_buttonSize.GetHeight() / 2 }),
            m_refreshButtonText);
        m_refreshButton.SetStyle(rgc::Style(rgc::Style::Position::BOTTOM_CENTER, { -m_buttonSize.GetWidth() / 1000.0f, -m_verticalStackPanelSize.GetHeight() / 3.5f }));
        m_refreshButton.OnClick([this]
        {
            refreshMidiDevices();
        });
        m_verticalStackPanel.AddChild(rgc::ToComponent(&m_refreshButton));

        // Apply button positioning and callback.
        m_applyButton = rgc::Button(rgc::Bounds::WithText(
            m_applyButtonText,
            m_buttonScalingFactor,
            { m_buttonSize.GetWidth() / 4, m_buttonSize.GetHeight() }),
            m_applyButtonText);
        m_applyButton.SetStyle(rgc::Style(rgc::Style::Position::BOTTOM_CENTER, { m_buttonSize.GetWidth() / 5.0f, -m_verticalStackPanelSize.GetHeight() / 12.0f }));
        m_applyButton.OnClick([this]
        {
            //TODO Apply settings
        });
        m_verticalStackPanel.AddChild(rgc::ToComponent(&m_applyButton));

        // Show currently connected device.
        m_connectedDeviceLabelText = "Connected device: " + m_midiMonitor.getConnectedDeviceName();
        m_connectedDeviceLabel = rgc::Label{ rgc::Bounds
            { 10, static_cast<float>(m_renderWindow.GetHeight()) - 20.0f, static_cast<float>(m_renderWindow.GetWidth()), 10 },
            m_connectedDeviceLabelText.c_str() };
        m_connectedDeviceLabel.SetStyle(rgc::Style(rgc::Style::Position::CENTER, { 0, 0 }));
    }

    void MidiSetupMenuState::refreshMidiDevices()
    {
        m_midiDevices = m_stateMachine
            .getCurrentState()
            ->getMidiMonitor()
            .getMidiDevices();

        m_deviceList.clear();

        for (MidiDevice& device : m_midiDevices)
        {
            // Needed first because raylib adds a new selection in the list view after the ;
            // so if there's an ; at the end of the string, there will be a blank option selectable.
            if (!m_deviceList.empty())
            {
                m_deviceList += ";";
            }
            m_deviceList += device.getPortName();
        }
        m_midiDeviceListViewText = m_deviceList.c_str();
    }
}
