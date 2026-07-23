#include "Measure.hpp"
#include "Note.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("Measure");

TEST_CASE("Measure number default 0")
{
    raindrops::Measure measure;
    CHECK( measure.getMeasureNumber() == 0 );
}

TEST_CASE("Measure number get/set")
{
    raindrops::Measure measure;

    int expectedMeasureNumber { 4 };
    measure.setMeasureNumber(expectedMeasureNumber);
    int actualMeasureNumber = measure.getMeasureNumber();

    CHECK( expectedMeasureNumber == actualMeasureNumber );
}

TEST_CASE("Measure number set invalid value")
{
    raindrops::Measure measure;
    measure.setMeasureNumber(-100);

    CHECK( measure.getMeasureNumber() == -1 );
}

TEST_CASE("Measure add a note")
{
    const raindrops::Note note(60);
    raindrops::Measure measure;
    measure.addNote(note);

    CHECK( measure.getNotes().front().getPitchMidiKey() == 60 );
}

TEST_SUITE_END();