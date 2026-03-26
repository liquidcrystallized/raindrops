#include "Mode.hpp"
#include <doctest.h>
#include <vector>

TEST_SUITE_BEGIN("Mode");

TEST_CASE("Default initialisation")
{
    raindrops::Mode mode {};

    CHECK( mode == "none" );
}

TEST_CASE("to_string returns correct names for all enums")
{
    CHECK( raindrops::to_string(raindrops::Mode::major) == "major" );
    CHECK( raindrops::to_string(raindrops::Mode::minor) == "minor" );
    CHECK( raindrops::to_string(raindrops::Mode::dorian) == "dorian" );
    CHECK( raindrops::to_string(raindrops::Mode::phrygian) == "phrygian" );
    CHECK( raindrops::to_string(raindrops::Mode::lydian) == "lydian" );
    CHECK( raindrops::to_string(raindrops::Mode::mixolydian) == "mixolydian" );
    CHECK( raindrops::to_string(raindrops::Mode::aeolian) == "aeolian" );
    CHECK( raindrops::to_string(raindrops::Mode::ionian) == "ionian" );
    CHECK( raindrops::to_string(raindrops::Mode::locrian) == "locrian" );

    // Default case (Mode::none is usually the last enum, but let's be explicit).
    CHECK( raindrops::to_string(raindrops::Mode::none) == "none" );
}

TEST_CASE("to_string handles unexpected values gracefully")
{
    // There aren't invalid enum values directly,
    // casting a random int to Mode tests the default case if the value isn't in the switch.
    auto badMode = static_cast<raindrops::Mode>(999);
    CHECK( raindrops::to_string(badMode) == "none" );
}

TEST_CASE("String equality (std::string == Mode)")
{
    CHECK( "major" == raindrops::Mode::major );
    CHECK( "mixolydian" == raindrops::Mode::mixolydian );

    // Case sensitivity check (should be false).
    CHECK_FALSE( "Major" == raindrops::Mode::major );
    CHECK_FALSE( "MAJOR" == raindrops::Mode::major );

    CHECK("none" == raindrops::Mode::none);
}

TEST_CASE("(Direct) Mode equality (Mode == std::string)")
{
    CHECK( raindrops::Mode::minor == "minor" );
    CHECK( raindrops::Mode::locrian == "locrian" );

    // Case sensitivity check (should be false).
    CHECK_FALSE( raindrops::Mode::major == "Major" );

    CHECK( raindrops::Mode::none == "none" );
}

TEST_CASE("All modes are unique")
{
    // Check that no two different enum values produce the same string or are equal
    std::vector<raindrops::Mode> allModes = {
        raindrops::Mode::none,
        raindrops::Mode::major,
        raindrops::Mode::minor,
        raindrops::Mode::dorian,
        raindrops::Mode::phrygian,
        raindrops::Mode::lydian,
        raindrops::Mode::mixolydian,
        raindrops::Mode::aeolian,
        raindrops::Mode::ionian,
        raindrops::Mode::locrian
    };

    for (int i = 0; i < allModes.size(); i++)
    {
        for (int j = i + 1; j < allModes.size(); j++)
        {
            CHECK( allModes[i] != allModes[j] );
            // Also verify their string representations differ
            CHECK( to_string(allModes[i]) != to_string(allModes[j]) );
        }
    }
}

TEST_SUITE_END();