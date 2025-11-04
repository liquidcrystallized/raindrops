#ifndef RAINDROPS_APPLICATION_HPP
#define RAINDROPS_APPLICATION_HPP

#include "midi/MidiDevice.hpp"
#include "midi/MidiMonitor.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

namespace raindrops
{
    class Application {
    public:
        Application();
        ~Application();

        void run();

    private:
        sf::RenderWindow m_renderWindow;
        std::vector<MidiDevice> m_midiDevices;
        std::shared_ptr<MidiMonitor> m_midiMonitor;

        unsigned int m_midiPort{};
        unsigned int m_midiChannel{};

        void input();
        void update();
        void render();

        void setMidiPort(unsigned int port);
        void setMidiChannel(unsigned int channel);

        void monitorMidi() const;
    };
}


#endif //RAINDROPS_APPLICATION_HPP
