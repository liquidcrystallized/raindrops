#ifndef RAINDROPS_MIDIMESSAGELIST_HPP
#define RAINDROPS_MIDIMESSAGELIST_HPP

/**
 * @brief Contains several defines used when parsing midi input messages.
 * https://midi.org/expanded-midi-1-0-messages-list
 */

#define NOTE_ON             144U
#define NOTE_OFF            128U
#define NOTE_MASK           240U
#define CHANNEL_MASK        15U
#define MIDI_CHANNEL_1      1
#define MIDI_CHANNEL_2      2
#define MIDI_CHANNEL_3      3
#define MIDI_CHANNEL_4      4
#define MIDI_CHANNEL_5      5
#define MIDI_CHANNEL_6      6
#define MIDI_CHANNEL_7      7
#define MIDI_CHANNEL_8      8
#define MIDI_CHANNEL_9      9
#define MIDI_CHANNEL_10     10
#define MIDI_CHANNEL_11     11
#define MIDI_CHANNEL_12     12
#define MIDI_CHANNEL_13     13
#define MIDI_CHANNEL_14     14
#define MIDI_CHANNEL_15     15
#define MIDI_CHANNEL_16     16
#define MIDI_CHANNEL_ALL    (-1)

#endif //RAINDROPS_MIDIMESSAGELIST_HPP