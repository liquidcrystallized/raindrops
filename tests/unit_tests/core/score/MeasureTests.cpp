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

TEST_SUITE_END();