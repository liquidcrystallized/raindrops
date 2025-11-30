#include "MidiMonitor.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("MidiMonitor");

TEST_CASE("MidiMonitor starts correctly")
{
    std::unique_ptr<raindrops::MidiMonitor> midiMonitor { new raindrops::MidiMonitor };
    bool isRunning { midiMonitor->startMonitoring(0, 0) };
    CHECK(isRunning == true);
}

TEST_CASE("MidiMonitor sets correct port number")
{
    std::unique_ptr<raindrops::MidiMonitor> midiMonitor { new raindrops::MidiMonitor };
    unsigned int expectedPortNumber { 3 };
    midiMonitor->setMidiPort(3);
    CHECK(expectedPortNumber == midiMonitor->getMidiPortNumber());
}

TEST_CASE("MidiMonitor sets correct channel number")
{
    std::unique_ptr<raindrops::MidiMonitor> midiMonitor { new raindrops::MidiMonitor };
    unsigned int expectedChannelNumber { 3 };
    midiMonitor->setMidiChannel(3);
    CHECK(expectedChannelNumber == midiMonitor->getMidiChannelNumber());
}

TEST_SUITE_END();