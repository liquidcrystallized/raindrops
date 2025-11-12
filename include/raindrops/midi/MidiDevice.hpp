#ifndef RAINDROPS_MIDIDEVICE_HPP
#define RAINDROPS_MIDIDEVICE_HPP

#include <RtMidi.h>

namespace raindrops
{
    /**
     * @brief Holds information about a midi device.
     */
    class MidiDevice {
    public:
        MidiDevice(std::string portName, unsigned int portNumber);

        std::string getPortName();

        [[nodiscard]] unsigned int getPortNumber() const;

    private:
        std::string m_portName;
        unsigned int m_portNumber;
    };
}


#endif //RAINDROPS_MIDIDEVICE_HPP