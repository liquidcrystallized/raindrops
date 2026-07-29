#include "MidiReceiver.hpp"
#include <print>

namespace raindrops
{
    MidiReceiver::MidiReceiver() = default;

    bool MidiReceiver::onNoteOn(const unsigned int keyNumber, const unsigned int velocity, const unsigned int midiChannel)
    {
        std::println("MidiReceiver::onNoteOn: keyNumber {} velocity: {} channel: {}",
                     keyNumber, velocity, midiChannel);

        return true;
    }

    bool MidiReceiver::onNoteOff(const unsigned int keyNumber, const unsigned int velocity, const unsigned int midiChannel)
    {
        std::println("MidiReceiver::onNoteOff: keyNumber {} velocity: {} channel: {}",
             keyNumber, velocity, midiChannel);

        return true;
    }

    bool MidiReceiver::onMidiEvent(std::vector<unsigned char> bytes)
    {
        //TODO
        return true;
    }
}
