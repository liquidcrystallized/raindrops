#include "Application.hpp"

#include "midi/MidiReceiver.hpp"

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
    }

    Application::~Application()
    {
    }

    void Application::run()
    {
        while (m_renderWindow.isOpen())
        {
            input();
            update();
            render();
        }
     }

    void Application::input()
    {
        //TODO
    }

    void Application::update()
    {
        //TODO
    }

    void Application::render()
    {
        m_renderWindow.clear();
        m_renderWindow.display();
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
