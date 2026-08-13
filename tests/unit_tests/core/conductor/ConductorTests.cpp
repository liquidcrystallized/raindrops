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

TEST_SUITE_END;