#include "MidiReceiver.hpp"
#include <iostream>

namespace raindrops
{
    MidiReceiver::MidiReceiver() = default;

    void MidiReceiver::onNoteOn(const int keyNumber, const int velocity, const int midiChannel)
    {
        std::cout   << "MidiReceiver::onNoteOn: keyNumber " << keyNumber
                    << " velocity: " << velocity
                    << " channel: " << midiChannel
                    << '\n';
    }

    void MidiReceiver::onNoteOff(const int keyNumber, const int velocity, const int midiChannel)
    {
        std::cout   << "MidiReceiver::onNoteOff: keyNumber " << keyNumber
                    << " velocity: " << velocity
                    << " midiChannel: " << midiChannel
                    << '\n';
    }

    void MidiReceiver::onMidiEvent(std::vector<unsigned char> bytes)
    {
        //TODO
    }
}
