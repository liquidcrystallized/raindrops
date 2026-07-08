#include "Application.hpp"
#include "ConfigManager.hpp"
#include "MidiReceiver.hpp"
#include "MainMenuState.hpp"

namespace raindrops
{
    Application::Application(IGraphics& renderer)
    : m_renderer { renderer }
    {
        m_config = ConfigManager::getInstance().getConfig();

        setupMidi();

        m_stateMachine.run(StateMachine::build<MainMenuState>(m_stateMachine, m_renderer, m_midiMonitor, true));

        startApplication();
    }

    Application::~Application()
    {
        m_midiMonitor.stopMonitoring();
    }

    void Application::startApplication()
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

    void Application::setupMidi()
    {
        auto midiReceiver = std::make_unique<MidiReceiver>();

        m_midiMonitor.probeAndSetMidiDevices(m_midiDevices);
        m_midiMonitor.setInputListener(std::move(midiReceiver));

        if (m_config.midiConfig.autoDetect && !m_midiDevices.empty())
        {
            m_midiMonitor.setMidiPort(m_midiDevices[0].getPortNumber());
            std::cout << "Auto-detected MIDI device: " << m_midiDevices[0].getPortName() << '\n';
        }
        else
        {
            m_midiMonitor.setMidiPort(m_config.midiConfig.port);
        }

        m_midiMonitor.setMidiChannel(m_config.midiConfig.channel);

        std::cout << "MIDI device configured: Port=" << m_midiMonitor.getMidiPortNumber()
                  << ", Channel=" << m_midiMonitor.getMidiChannelNumber() << std::endl;

        m_midiMonitor.startMonitoring(m_midiMonitor.getMidiPortNumber(), m_midiMonitor.getMidiChannelNumber());
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
