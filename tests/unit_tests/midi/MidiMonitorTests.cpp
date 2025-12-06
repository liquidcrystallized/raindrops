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

TEST_CASE("MidiMonitor handles device connection status")
{
    std::unique_ptr<raindrops::MidiMonitor> midiMonitor { new raindrops::MidiMonitor };
    unsigned int port { 2 };
    unsigned int channel { 1 };
    midiMonitor->setMidiPort(port);
    midiMonitor->setMidiChannel(channel);
    midiMonitor->startMonitoring(port, channel);

    // Test with no device connected.
    CHECK(midiMonitor->getConnectedDeviceName() == "Midi device not connected.");

    //// Fake device for testing.
    //auto testDevice = std::make_unique<raindrops::MidiDevice>("Test Device", port);
    //std::vector<raindrops::MidiDevice> midiDevices;
    //midiMonitor->probeAndSetMidiDevices(midiDevices);
    //raindrops::MidiMonitor::appendNewDevice(testDevice->getPortName(), testDevice->getPortNumber(), midiDevices);
    //midiMonitor->startMonitoring(testDevice->getPortNumber(), channel);

    //// Verify connection with fake device.
    //CHECK(!midiMonitor->getMidiDevices().empty());
    //CHECK(midiMonitor->getConnectedDeviceName() != "Midi device not connected.");
    //midiMonitor->stopMonitoring();
}

TEST_CASE("MidiMonitor stops correctly")
{
    std::unique_ptr<raindrops::MidiMonitor> midiMonitor { new raindrops::MidiMonitor };
    midiMonitor->startMonitoring(0, 0);
    midiMonitor->stopMonitoring();

    // Verify thread is cleaned up.
    CHECK(midiMonitor->monitorThreadAlive() == false);
}

TEST_CASE("MidiMonitor thread alive between start and stop")
{
    std::unique_ptr<raindrops::MidiMonitor> midiMonitor { new raindrops::MidiMonitor };
    midiMonitor->startMonitoring(0, 0);
    bool aliveBetweenStartAndStop = midiMonitor->monitorThreadAlive();
    midiMonitor->stopMonitoring();

    // Should be alive between calls.
    CHECK(aliveBetweenStartAndStop == true);
}

TEST_SUITE_END();