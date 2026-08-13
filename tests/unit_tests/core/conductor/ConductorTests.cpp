#include "Conductor.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("Conductor");

TEST_CASE("Starts in stopped state with correct defaults")
{
    raindrops::Conductor conductor {};

    CHECK( conductor.isPlaying() == false );
    CHECK( conductor.getScrollOffset() == doctest::Approx(-1000.0f));
    CHECK( conductor.getScrollSpeed() == doctest::Approx(100.0f));
}

TEST_CASE("Updates scroll position based on delta time")
{
    raindrops::Conductor conductor {};
    auto sheet = std::make_unique<raindrops::MusicSheet>();

    std::vector<raindrops::Measure> measures {};
    for (int i = 1; i <= 10; i++)
    {
        raindrops::Measure measure {};
        measure.setMeasureNumber(i);
        measures.push_back(measure);
    }
    sheet->setMeasures(measures);

    conductor.setMusicSheet(std::move(sheet));
    conductor.resume();

    // TODO: explicitly set these when setters are implemented instead of relying on defaults.
    CHECK( conductor.getScrollOffset() == doctest::Approx(-1000.0f) );
    CHECK( conductor.getScrollSpeed() == doctest::Approx(100.0f) );

    conductor.update(1.0f);
    CHECK( conductor.getScrollOffset() == doctest::Approx(-900.0f) );

    conductor.update(2.0f);
    CHECK( conductor.getScrollOffset() == doctest::Approx(-700.0f) );
}

TEST_SUITE_END;