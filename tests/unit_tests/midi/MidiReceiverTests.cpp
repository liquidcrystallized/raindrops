#include "MidiReceiver.hpp"
#include <doctest.h>
#include <memory>

TEST_SUITE_BEGIN("MidiReceiver");

TEST_CASE("On key press - should all return true")
{
    std::unique_ptr<raindrops::MidiReceiver> midiReceiver { new raindrops::MidiReceiver };
    unsigned int keyNumber { 60 };
    unsigned int velocity { 60 };
    unsigned int midiChannel { 1 };

    CHECK(midiReceiver->onNoteOn(keyNumber, velocity, midiChannel));
    CHECK(midiReceiver->onNoteOff(keyNumber, velocity, midiChannel));
}

TEST_SUITE_END();