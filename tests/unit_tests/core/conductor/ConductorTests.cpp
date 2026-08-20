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

    conductor.resume();

    conductor.setScrollSpeed(200.0f);

    CHECK( conductor.getScrollOffset() == doctest::Approx(-1000.0f) );
    CHECK( conductor.getScrollSpeed() == doctest::Approx(200.0f) );

    conductor.update(1.0f);
    CHECK( conductor.getScrollOffset() == doctest::Approx(-800.0f) );

    conductor.update(2.0f);
    CHECK( conductor.getScrollOffset() == doctest::Approx(-400.0f) );
}

TEST_CASE("No updates when paused")
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

    conductor.resume();

    conductor.setScrollSpeed(200.0f);

    CHECK( conductor.getScrollOffset() == doctest::Approx(-1000.0f) );
    CHECK( conductor.getScrollSpeed() == doctest::Approx(200.0f) );

    conductor.update(1.0f);
    CHECK( conductor.getScrollOffset() == doctest::Approx(-800.0f) );

    conductor.pause();

    conductor.update(2.0f);
    CHECK( conductor.getScrollOffset() == doctest::Approx(-800.0f) );
}

TEST_CASE("Scroll offset clamping")
{
    raindrops::Conductor conductor {};

    SUBCASE("Upper limit clamp")
    {
        conductor.setScrollOffset(std::numeric_limits<float>::max() + 10000.0f);
        CHECK( conductor.getScrollOffset() == doctest::Approx(std::numeric_limits<float>::max()) );
    }
    SUBCASE("Lower limit clamp")
    {
        conductor.setScrollOffset(-20000.0f);
        CHECK( conductor.getScrollOffset() == doctest::Approx(-1000.0f) );
    }
}

TEST_CASE("Scroll speed clamping")
{
    raindrops::Conductor conductor {};

    SUBCASE("Upper limit clamp")
    {
        conductor.setScrollSpeed(std::numeric_limits<float>::max() + 10000.0f);
        CHECK( conductor.getScrollSpeed() == doctest::Approx(std::numeric_limits<float>::max()) );
    }
    SUBCASE("Lower limit clamp")
    {
        conductor.setScrollSpeed(-100.0f);
        CHECK( conductor.getScrollSpeed() == doctest::Approx(0.0f) );
    }
}

TEST_CASE("Song start scroll buffer clamping")
{
    raindrops::Conductor conductor {};

    SUBCASE("Upper limit clamp")
    {
        conductor.setSongStartScrollBuffer(1000.0f);
        CHECK( conductor.getSongStartScrollBuffer() == doctest::Approx(0.0f) );
    }
    SUBCASE("Lower limit clamp")
    {
        conductor.setSongStartScrollBuffer(std::numeric_limits<float>::lowest() - 250000.0f);
        CHECK( conductor.getSongStartScrollBuffer() == doctest::Approx(std::numeric_limits<float>::lowest()) );
    }
}

TEST_CASE("Stops updating/scrolling if float limits are somehow hit")
{
    raindrops::Conductor conductor {};

    conductor.setScrollOffset(std::numeric_limits<float>::max() - 1000.0f);
    conductor.setScrollSpeed(100.0f);
    conductor.resume();

    for (int i = 0; i < 20; i++)
    {
        conductor.update(1.0f);
    }

    CHECK( conductor.getScrollOffset() == doctest::Approx(std::numeric_limits<float>::max()) );
}

TEST_SUITE_END;