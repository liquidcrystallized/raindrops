#ifndef RAINDROPS_NOTE_HPP
#define RAINDROPS_NOTE_HPP


namespace raindrops
{
    class Note {
    public:
        bool isPartOfChord { false };

        explicit Note(int pitchMidiKey);

        [[nodiscard]] int getPitchMidiKey() const;

    private:
        // Not frequency, just the direct MIDI key number (0-127).
        // Don't want to do conversions in game loop, just have a direct
        // comparison (==) to the midi inputs during gameplay.
        int m_pitchMidiKey {};
    };
}


#endif //RAINDROPS_NOTE_HPP