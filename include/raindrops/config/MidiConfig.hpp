#ifndef RAINDROPS_MIDICONFIG_HPP
#define RAINDROPS_MIDICONFIG_HPP

namespace raindrops
{
    /**
     * @brief Configuration for things related to the MIDI subsystem.
     * Mostly dealing with connected devices.
     */
    struct MidiConfig {
        unsigned int port { 0 };
        unsigned int channel { 0 };
        bool autoDetect { true }; //TODO: Future feature.

        [[nodiscard]] bool isValid() const
        {
            return port >= 0 && port <= 128 &&
                channel >= 0 && channel <= 16;
        }
    };
}

#endif //RAINDROPS_MIDICONFIG_HPP