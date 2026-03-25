#include "Measure.hpp"
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

TEST_CASE("Has end line default false")
{
    raindrops::Measure measure;
    CHECK( measure.hasEndLine() == false );
}

TEST_CASE("Has end line get/set")
{
    raindrops::Measure measure;

    measure.setHasEndLine(true);
    bool shouldHaveEndLine = measure.hasEndLine();

    CHECK( shouldHaveEndLine == true );
}

TEST_CASE("Tempo in BPM default")
{
    raindrops::Measure measure;
    CHECK( measure.getTempoInBPM() == 0 );
}

TEST_CASE("Tempo in BPM get/set")
{
    raindrops::Measure measure;

    int expectedTempo { 150 };
    measure.setTempoInBPM(expectedTempo);
    int actualTempo = measure.getTempoInBPM();

    CHECK( expectedTempo == actualTempo );
}

TEST_SUITE_END();