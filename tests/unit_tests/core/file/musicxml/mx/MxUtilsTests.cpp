#include "MxUtils.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("MxUtils");

TEST_CASE("convertMxPitchDataToMidiKey - Conversion Results")
{
    mx::api::Step step {};
    int octave {};
    int alter {};

    SUBCASE("Middle C (C4)")
    {
        step = mx::api::Step::c;
        octave = 4 ;
        alter = 0 ;

        int result = raindrops::MxUtils::convertMxPitchDataToMidiKey(step, octave, alter);
        CHECK( result == 60 );
    }
    SUBCASE("C#4")
    {
        step = mx::api::Step::c;
        octave = 4;
        alter = 1;

        int result = raindrops::MxUtils::convertMxPitchDataToMidiKey(step, octave, alter);
        CHECK( result == 61 );
    }
    SUBCASE("B3")
    {
        step = mx::api::Step::b;
        octave = 3;
        alter = 0;

        int result = raindrops::MxUtils::convertMxPitchDataToMidiKey(step, octave, alter);
        CHECK( result == 59 );
    }
}

TEST_CASE("convertMxPitchDataToMidiKey - Clamping")
{
    mx::api::Step step {};
    int octave {};
    int alter {};

    SUBCASE("Lower Bound")
    {
        step = mx::api::Step::c;
        octave = -1;
        alter = 0;

        int result = raindrops::MxUtils::convertMxPitchDataToMidiKey(step, octave, alter);
        CHECK( result == 0 );
    }
    SUBCASE("Upper Bound")
    {
        step = mx::api::Step::c;
        octave = 20;
        alter = 0;

        int result = raindrops::MxUtils::convertMxPitchDataToMidiKey(step, octave, alter);
        CHECK( result == 127 );
    }
}

TEST_CASE("createNoteFromMxNote - Basic Note")
{
    mx::api::NoteData mxNote;
    mxNote.pitchData.step = mx::api::Step::c;
    mxNote.pitchData.octave = 4;
    mxNote.pitchData.alter = 0;
    mxNote.isChord = false;

    raindrops::Note note = raindrops::MxUtils::createNoteFromMxNote(mxNote);

    CHECK( note.getPitchMidiKey() == 60 );
    CHECK( note.isPartOfChord == false );
}

TEST_CASE("createNoteFromMxNote - Chord Note")
{
    mx::api::NoteData mxNote;
    mxNote.pitchData.step = mx::api::Step::c;
    mxNote.pitchData.octave = 4;
    mxNote.pitchData.alter = 0;
    mxNote.isChord = true;

    raindrops::Note note = raindrops::MxUtils::createNoteFromMxNote(mxNote);

    CHECK( note.getPitchMidiKey() == 60 );
    CHECK( note.isPartOfChord == true );
}

TEST_CASE("extractNotesFromMxStaff - Empty Staff")
{
    mx::api::StaffData staff;
    staff.voices.clear();

    std::vector<raindrops::Note> notes = raindrops::MxUtils::extractNotesFromMxStaff(staff);
    CHECK( notes.empty() );
}

TEST_CASE("extractNoteFromMxStaff - Single Voice, Single Note")
{
    mx::api::StaffData staff;

    mx::api::VoiceData voice;
    mx::api::NoteData noteData;
    noteData.pitchData.step = mx::api::Step::c;
    noteData.pitchData.octave = 4;
    noteData.pitchData.alter = 0;
    noteData.isChord = false;

    voice.notes.push_back(noteData);
    staff.voices[0] = voice;

    std::vector<raindrops::Note> notes = raindrops::MxUtils::extractNotesFromMxStaff(staff);

    CHECK( notes.size() == 1 );
    CHECK( notes[0].getPitchMidiKey() == 60 );
}

TEST_CASE("extractNotesFromMxStaff - Multiple Voices")
{
    mx::api::StaffData staff;

    mx::api::VoiceData voice1;
    mx::api::NoteData note1;
    note1.pitchData.step = mx::api::Step::c;
    note1.pitchData.octave = 4;
    note1.isChord = false;
    voice1.notes.push_back(note1);

    mx::api::VoiceData voice2;
    mx::api::NoteData note2;
    note2.pitchData.step = mx::api::Step::e;
    note2.pitchData.octave = 4;
    note2.isChord = false;
    voice2.notes.push_back(note2);

    staff.voices[0] = voice1;
    staff.voices[1] = voice2;

    std::vector<raindrops::Note> notes = raindrops::MxUtils::extractNotesFromMxStaff(staff);

    CHECK( notes.size() == 2 );
    CHECK( notes[0].getPitchMidiKey() == 60 );
    CHECK( notes[1].getPitchMidiKey() == 64 );
}

TEST_CASE("convertFromMxMeasure - Basic Conversion")
{
    mx::api::MeasureData mxMeasure;
    int index = 0;

    raindrops::Measure measure = raindrops::MxUtils::convertFromMxMeasure(mxMeasure, index);

    CHECK(measure.getMeasureNumber() == 1);
}


TEST_CASE("convertFromMxMeasure - Measure Numbering")
{
    mx::api::MeasureData mxMeasure;
    int index = 5;

    raindrops::Measure measure = raindrops::MxUtils::convertFromMxMeasure(mxMeasure, index);

    CHECK(measure.getMeasureNumber() == 6);
}

TEST_SUITE_END;