#include "raindrops/midi/MidiDevice.hpp"

#include <utility>

namespace raindrops
{
    MidiDevice::MidiDevice(std::string portName, const unsigned int portNumber)
    : m_portName { std::move(portName) }
    , m_portNumber { portNumber }
    {
    }

    std::string MidiDevice::getPortName()
    {
        return m_portName;
    }

    unsigned int MidiDevice::getPortNumber() const
    {
        return m_portNumber;
    }
}