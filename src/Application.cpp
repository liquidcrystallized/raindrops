#include "Application.hpp"
#include "MidiReceiver.hpp"
#include "MainMenuState.hpp"

namespace raindrops
{
    Application::Application(Renderer& renderer)
    : m_renderer { renderer }
    {
        // Midi related setup
        auto midiReceiver = std::make_unique<MidiReceiver>();

        m_midiMonitor.probeAndSetMidiDevices(m_midiDevices);
        m_midiMonitor.setInputListener(std::move(midiReceiver));

        //TODO: Temporary for testing
        m_midiMonitor.setMidiPort(1);
        m_midiMonitor.setMidiChannel(1);
        m_midiMonitor.startMonitoring(m_midiMonitor.getMidiPortNumber(), m_midiMonitor.getMidiChannelNumber());

        // Initialise state machine
        m_stateMachine.run(StateMachine::build<MainMenuState>(m_stateMachine, m_renderer, m_midiMonitor, true));

        run();
    }

    Application::~Application()
    {
        m_midiMonitor.stopMonitoring();
    }

    void Application::run()
    {
        while (m_stateMachine.running())
        {
            if (m_renderer.windowResized())
            {
                onWindowResize();
            }

            m_stateMachine.nextState();
            m_stateMachine.update();
            m_stateMachine.draw();
        }
    }

    void Application::onWindowResize()
    {
        m_stateMachine.getCurrentState()->setWindowCentrePosition
        (
            static_cast<float>(m_renderer.getWindowWidth()) / 2.0f,
            static_cast<float>(m_renderer.getWindowHeight()) / 2.0f
        );

        m_stateMachine.getCurrentState()->onWindowResize();
    }
}
