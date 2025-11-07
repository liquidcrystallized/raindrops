#ifndef RAINDROPS_MIDIRECEIVER_HPP
#define RAINDROPS_MIDIRECEIVER_HPP

#include "IMidiInputListener.hpp"


namespace raindrops
{
    class MidiReceiver final : public IMidiInputListener {
    public:
        MidiReceiver();

        bool onNoteOn(unsigned int keyNumber, unsigned int velocity, unsigned int midiChannel) override;
        bool onNoteOff(unsigned int keyNumber, unsigned int velocity, unsigned int midiChannel) override;
        bool onMidiEvent(std::vector<unsigned char> bytes) override;
    };
}


#endif //RAINDROPS_MIDIRECEIVER_HPP