#include "Application.hpp"
#include "MidiReceiver.hpp"
#include "MainMenuState.hpp"
#include "raygui-defguard.hpp"

namespace raindrops
{
    Application::Application()
    {
        // Graphics related setup
        m_renderWindow.SetConfigFlags(FLAG_WINDOW_RESIZABLE);
        m_renderWindow.Init(1280, 720, "raindrops [dev]");
        m_renderWindow.SetTargetFPS(60);

        // Note: Default raylib font looks bad if not in multiples of 10.
        rgc::Globals::Style::GuiSetStyle(DEFAULT, TEXT_SIZE, 20);

        // Midi related setup
        auto midiReceiver = std::make_unique<MidiReceiver>();

        m_midiMonitor.probeAndSetMidiDevices(m_midiDevices);
        m_midiMonitor.setInputListener(std::move(midiReceiver));

        //TODO: Temporary for testing
        setMidiPort(1);
        setMidiChannel(1);

        monitorMidi();

        // Initialise state machine
        m_stateMachine.run(StateMachine::build<MainMenuState>(m_stateMachine, m_renderWindow, m_midiMonitor, true));
    }

    Application::~Application()
    {
        m_midiMonitor.stopMonitoring();
    }

    void Application::run()
    {
        while (m_stateMachine.running())
        {
            if (m_renderWindow.IsResized())
            {
                onWindowResize();
            }

            m_stateMachine.nextState();
            m_stateMachine.update();
            m_stateMachine.draw();
        }
    }

    void Application::setMidiPort(unsigned int port)
    {
        m_midiPort = port;
    }

    void Application::setMidiChannel(unsigned int channel)
    {
        m_midiChannel = channel;
    }

    void Application::monitorMidi()
    {
        m_midiMonitor.startMonitoring(m_midiPort, m_midiChannel);
    }

    void Application::onWindowResize()
    {
        m_stateMachine.getCurrentState()->setWindowCentrePosition
        (
            static_cast<float>(m_renderWindow.GetWidth()) / 2.0f,
            static_cast<float>(m_renderWindow.GetHeight()) / 2.0f
        );

        m_stateMachine.getCurrentState()->onWindowResize();
    }
}
