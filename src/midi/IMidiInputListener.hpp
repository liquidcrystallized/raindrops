#ifndef RAINDROPS_IMIDIINPUTLISTENER_HPP
#define RAINDROPS_IMIDIINPUTLISTENER_HPP

#include <vector>

namespace raindrops
{
    /**
     * @brief Midi listener that can be derived from any class that wants to
     * have midi event callbacks.
     */
    class IMidiInputListener {
    public:
        virtual ~IMidiInputListener() = default;

        /**
         * @brief Called on new midi Note On (9x) event.
         * @param keyNumber Number of pressed note. There are 128 possible note numbers.
         * @param velocity How hard/fast a key was pressed. Value between 0 and 127.
         * @param midiChannel Channel of sent event. There are 16 possible channels.
         */
        virtual void onNoteOn(int keyNumber, int velocity, int midiChannel) = 0;

        /**
         * @brief Called on a Note Off (8x) event.
         * @param keyNumber Number of released note. There are 128 possible note numbers.
         * @param velocity "Release" velocity of note. Value between 0 and 127.
         * @param midiChannel Channel of sent event. There are 16 possible channels.
         */
        virtual void onNoteOff(int keyNumber, int velocity, int midiChannel) = 0;

        /**
         * @brief Called when a midi event cannot be identified as a Note On or Off.
         * @param bytes The message of the midi event.
         * @see https://en.wikipedia.org/wiki/MIDI for more details.
         */
        virtual void onMidiEvent(std::vector<unsigned char> bytes) = 0;
    };
}

#endif //RAINDROPS_IMIDIINPUTLISTENER_HPP