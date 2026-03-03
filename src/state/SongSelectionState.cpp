#include "SongSelectionState.hpp"
#include "StateMachine.hpp"

namespace raindrops
{
    SongSelectionState::SongSelectionState(StateMachine& stateMachine, Renderer& renderer, MidiMonitor& midiMonitor, const bool replace)
    : State { stateMachine, renderer, midiMonitor, replace, "SongSelectionState" }
    {
        positionUIComponents();
    }

    void SongSelectionState::pause()
    {
        //TODO
    }

    void SongSelectionState::resume()
    {
        //TODO
    }

    void SongSelectionState::update()
    {
        if (raylib::Keyboard::IsKeyPressed(KEY_ESCAPE))
        {
            m_stateMachine.lastState();
        }

        m_connectedDeviceLabelText = "Connected device: " + m_midiMonitor.getConnectedDeviceName();
        m_connectedDeviceLabel.SetText(m_connectedDeviceLabelText.c_str());
    }

    void SongSelectionState::draw()
    {
        m_renderer.drawStart();
        RAYGUI_CPP_UNUSED(m_connectedDeviceLabel.Show(true));
        m_renderer.drawEnd();
    }

    void SongSelectionState::onWindowResize()
    {
        positionUIComponents();
    }

    //TODO: Temp programmers UI, implement actual design later, throw it into the renderer
    void SongSelectionState::positionUIComponents()
    {
        // Show currently connected device.
        m_connectedDeviceLabel = rgc::Label{ rgc::Bounds
            { 10, static_cast<float>(m_renderer.getWindowHeight()) - 20.0f, static_cast<float>(m_renderer.getWindowWidth()), 10 },
            m_connectedDeviceLabelText.c_str() };
        m_connectedDeviceLabel.SetStyle(rgc::Style(rgc::Style::Position::CENTER, { 0, 0 }));
    }
}
