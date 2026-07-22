#include "Note.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("Note");

TEST_CASE("Note - default initialisation")
{
    raindrops::Note note { 0 };

    CHECK( note.isPartOfChord == false );
}

TEST_CASE("Note - valid MIDI key (0)")
{
    raindrops::Note note { 0 };
    CHECK( note.getPitchMidiKey() == 0 );
}

TEST_CASE("Note - valid MIDI key (60 - Middle C)")
{
    raindrops::Note note { 60 };
    CHECK( note.getPitchMidiKey() == 60 );
}

TEST_CASE("Note - valid MIDI key (127)")
{
    raindrops::Note note { 127 };
    CHECK( note.getPitchMidiKey() == 127 );
}

TEST_CASE("Note - invalid MIDI key (negative)")
{
    raindrops::Note note { -128 };
    CHECK( note.getPitchMidiKey() == -1 );
}

TEST_CASE("Note - invalid MIDI key (greater than 127)")
{
    raindrops::Note note { 128 };
    CHECK( note.getPitchMidiKey() == -1 );
}

TEST_SUITE_END;