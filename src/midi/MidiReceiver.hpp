#ifndef RAINDROPS_MIDIRECEIVER_HPP
#define RAINDROPS_MIDIRECEIVER_HPP

#include "IMidiInputListener.hpp"


namespace raindrops
{
    class MidiReceiver final : public IMidiInputListener {
    public:
        MidiReceiver();

        void onNoteOn(unsigned int keyNumber, unsigned int velocity, unsigned int midiChannel) override;
        void onNoteOff(unsigned int keyNumber, unsigned int velocity, unsigned int midiChannel) override;
        void onMidiEvent(std::vector<unsigned char> bytes) override;
    };
}


#endif //RAINDROPS_MIDIRECEIVER_HPP