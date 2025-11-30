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

    private:
        StateMachine m_stateMachine;
        raylib::Window m_renderWindow;
        std::vector<MidiDevice> m_midiDevices;
        MidiMonitor m_midiMonitor;

        unsigned int m_midiPort{};
        unsigned int m_midiChannel{};

        void run();

        void onWindowResize();
    };
}


#endif //RAINDROPS_APPLICATION_HPP
