#ifndef RAINDROPS_APPLICATION_HPP
#define RAINDROPS_APPLICATION_HPP

#include "MidiDevice.hpp"
#include "MidiMonitor.hpp"
#include "Renderer.hpp"
#include "StateMachine.hpp"
#include <raylib-cpp.hpp>

namespace raindrops
{
    class Application {
    public:
        explicit Application(Renderer&);
        ~Application();

    private:
        Renderer& m_renderer;
        StateMachine m_stateMachine;
        std::vector<MidiDevice> m_midiDevices;
        MidiMonitor m_midiMonitor;

        unsigned int m_midiPort{};
        unsigned int m_midiChannel{};

        void startApplication();

        void onWindowResize();
    };
}


#endif //RAINDROPS_APPLICATION_HPP
