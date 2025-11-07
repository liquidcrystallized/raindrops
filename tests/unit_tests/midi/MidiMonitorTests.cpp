#include "../../../src/midi/MidiMonitor.hpp"
#include "doctest/doctest.h"

TEST_SUITE_BEGIN("MidiMonitor");

TEST_CASE("MidiMonitor starts correctly")
{
    std::unique_ptr<raindrops::MidiMonitor> midiMonitor { new raindrops::MidiMonitor };
    bool isRunning { midiMonitor->startMonitoring(0, 0) };
    CHECK(isRunning == true);
}

TEST_SUITE_END();