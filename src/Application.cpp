#include "Application.hpp"

#include "midi/MidiReceiver.hpp"
#include "state/MainMenuState.hpp"

namespace raindrops
{
    Application::Application()
    {
        // Graphics related setup
        m_renderWindow.create(sf::VideoMode({640, 480}), "raindrops [dev]");
        m_renderWindow.setFramerateLimit(60);

        // Midi related setup
        const auto midiReceiver = std::make_shared<MidiReceiver>();

        m_midiMonitor = std::make_shared<MidiMonitor>();
        m_midiMonitor->listDevices(m_midiDevices);
        m_midiMonitor->setInputListener(midiReceiver);

        //TODO: Temporary for testing
        setMidiPort(1);
        setMidiChannel(1);

        monitorMidi();

        // Initialise state machine
        m_stateMachine.run(StateMachine::build<MainMenuState>(m_stateMachine, m_renderWindow, true));
    }

    Application::~Application()
    {
    }

    void Application::run()
    {
        while (m_stateMachine.running())
        {
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

    void Application::monitorMidi() const
    {
        m_midiMonitor->startMonitoring(m_midiPort, m_midiChannel);
    }

}
