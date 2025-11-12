#ifndef RAINDROPS_APPLICATION_HPP
#define RAINDROPS_APPLICATION_HPP

#include "MidiDevice.hpp"
#include "MidiMonitor.hpp"
#include "StateMachine.hpp"
#include <raylib-cpp.hpp>

namespace raindrops
{
    class Application {
    public:
        Application();
        ~Application();

        void run();

    private:
        StateMachine m_stateMachine;
        raylib::Window m_renderWindow;
        std::vector<MidiDevice> m_midiDevices;
        std::shared_ptr<MidiMonitor> m_midiMonitor;

        unsigned int m_midiPort{};
        unsigned int m_midiChannel{};

        void setMidiPort(unsigned int port);
        void setMidiChannel(unsigned int channel);

        void monitorMidi() const;
    };
}


#endif //RAINDROPS_APPLICATION_HPP
