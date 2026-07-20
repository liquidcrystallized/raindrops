#include "Note.hpp"

namespace raindrops
{
    Note::Note(const int pitchMidiKey)
    {
        if (pitchMidiKey < 0 || pitchMidiKey > 127)
        {
            m_pitchMidiKey = -1;
        }
        else
        {
            m_pitchMidiKey = pitchMidiKey;
        }
    }

    int Note::getPitchMidiKey() const
    {
        return m_pitchMidiKey;
    }
}
