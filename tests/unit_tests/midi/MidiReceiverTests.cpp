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

TEST_CASE("MidiReceiver handles multiple simultaneous notes")
{
    std::unique_ptr<raindrops::MidiReceiver> midiReceiver { new raindrops::MidiReceiver };
    unsigned int key1 { 60 }, key2 { 61 }, key3 { 62 };
    unsigned int velocity { 60 };
    unsigned int midiChannel { 1 };

    // Press multiple keys
    CHECK(midiReceiver->onNoteOn(key1, velocity, midiChannel));
    CHECK(midiReceiver->onNoteOn(key2, velocity, midiChannel));
    CHECK(midiReceiver->onNoteOn(key3, velocity, midiChannel));

    // Release all keys
    CHECK(midiReceiver->onNoteOff(key1, velocity, midiChannel));
    CHECK(midiReceiver->onNoteOff(key2, velocity, midiChannel));
    CHECK(midiReceiver->onNoteOff(key3, velocity, midiChannel));
}


TEST_SUITE_END();