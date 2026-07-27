#include "MxUtils.hpp"

namespace raindrops::MxUtils
{
    int convertMxPitchDataToMidiKey(const mx::api::Step step, const int octave, const int alter)
    {
        int semitoneOffset;

        // This'll make more sense if you look at your piano/keyboard.
        // Going 1 semitone up from C will just land you on C#, not D.
        switch (step)
        {
            case mx::api::Step::c: semitoneOffset = 0; break;
            case mx::api::Step::d: semitoneOffset = 2; break;
            case mx::api::Step::e: semitoneOffset = 4; break;
            case mx::api::Step::f: semitoneOffset = 5; break;
            case mx::api::Step::g: semitoneOffset = 7; break;
            case mx::api::Step::a: semitoneOffset = 9; break;
            case mx::api::Step::b: semitoneOffset = 11; break;
            default:
                throw std::invalid_argument("Unknown musicxml::Step value");
        }

        // A little magic but lets say we want middle C (60).
        // Step = c, so offset is 0.
        // Octave = 4, C4 is middle C for MOST standards.
        // Alter = 0, no accidentals.
        // (4 + 1) * 12 + 0 + 0 = 60.
        const int midiValue = (octave + 1) * 12 + semitoneOffset + alter;

        //TODO: Note sure how to handle malformed note data with weird values. Just assume it's valid for now.
        if (midiValue < 0) return 0;
        if (midiValue > 127) return 127;

        return midiValue;
    }

    Note createNoteFromMxNote(const mx::api::NoteData& mxNote)
    {
        Note note(convertMxPitchDataToMidiKey(mxNote.pitchData.step, mxNote.pitchData.octave, mxNote.pitchData.alter));
        note.isPartOfChord = mxNote.isChord;
        return note;
    }

    std::vector<Note> extractNotesFromMxStaff(const mx::api::StaffData& staff)
    {
        std::vector<Note> notes;

        for (const auto& voice : staff.voices)
        {
            for (const auto& mxNote : voice.second.notes)
            {
                notes.push_back(createNoteFromMxNote(mxNote));
            }
        }

        return notes;
    }

    Measure convertFromMxMeasure(const mx::api::MeasureData& mxMeasure, const int index)
    {
        Measure measure;
        measure.setMeasureNumber(index + 1);

        for (const auto& staff : mxMeasure.staves)
        {
            std::vector<Note> staffNotes = extractNotesFromMxStaff(staff);

            for (Note note : staffNotes)
            {
                measure.addNote(note);
            }
        }

        return measure;
    }
}
