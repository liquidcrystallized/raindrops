#include "raindrops/midi/MidiDevice.hpp"
#include <doctest/doctest.h>

TEST_SUITE_BEGIN("MidiDevice");

TEST_CASE("getPortName - should return expected name")
{
    raindrops::MidiDevice midiDevice { "foo", 1 };
    std::string expectedPortName { "foo" };
    CHECK(expectedPortName == midiDevice.getPortName());
}

TEST_CASE("getPortNumber - should return expected number")
{
    raindrops::MidiDevice midiDevice { "foo", 1 };
    int expectedPortNumber { 1 };
    CHECK(expectedPortNumber == midiDevice.getPortNumber());
}

TEST_SUITE_END();