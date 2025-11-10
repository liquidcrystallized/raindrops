#include "raindrops/midi/MidiReceiver.hpp"
#include <iostream>

namespace raindrops
{
    MidiReceiver::MidiReceiver() = default;

    bool MidiReceiver::onNoteOn(const unsigned int keyNumber, const unsigned int velocity, const unsigned int midiChannel)
    {
        std::cout   << "MidiReceiver::onNoteOn: keyNumber " << keyNumber
                    << " velocity: " << velocity
                    << " channel: " << midiChannel
                    << '\n';

        return true;
    }

    bool MidiReceiver::onNoteOff(const unsigned int keyNumber, const unsigned int velocity, const unsigned int midiChannel)
    {
        std::cout   << "MidiReceiver::onNoteOff: keyNumber " << keyNumber
                    << " velocity: " << velocity
                    << " midiChannel: " << midiChannel
                    << '\n';
        return true;
    }

    bool MidiReceiver::onMidiEvent(std::vector<unsigned char> bytes)
    {
        //TODO
        return true;
    }
}
