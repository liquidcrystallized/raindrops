#include "MidiMonitor.hpp"
#include "MidiMessageList.hpp"

namespace raindrops
{
    MidiMonitor::MidiMonitor() : m_running { false }
    {
        try
        {
            m_rtMidiIn = std::make_unique<RtMidiIn>();
        }
        catch (RtMidiError& error)
        {
            error.printMessage();
        }
    }

    MidiMonitor::~MidiMonitor()
    {
        stopMonitoring();
    }

    bool MidiMonitor::startMonitoring(const unsigned int midiPort, const unsigned int midiChannel)
    {
        if (m_running)
        {
            stopMonitoring();
        }

        m_midiPort = midiPort;
        m_midiChannel = midiChannel;

        try
        {
            m_rtMidiIn->openPort(midiPort);
            m_rtMidiIn->ignoreTypes(false, false, false);
            m_running = true;
            startMonitoringThread();
        }
        catch (RtMidiError& error)
        {
            error.printMessage();
            stopMonitoring();
            return false;
        }

        return true;
    }

    void MidiMonitor::stopMonitoring()
    {
        m_running = false;

        if (m_monitorThread && monitorThreadAlive())
        {
            m_monitorThread->join();
        }
    }

    std::vector<MidiDevice> MidiMonitor::getMidiDevices()
    {
        const std::chrono::time_point<std::chrono::steady_clock> currentTime = std::chrono::steady_clock::now();
        std::chrono::duration<long> timeElapsed = std::chrono::duration_cast<std::chrono::seconds>(currentTime - m_lastProbeTime);

        // Re-probe only if cache is stale.
        if (timeElapsed > m_cacheDuration || m_cachedDevices.empty())
        {
            probeAndSetMidiDevices(m_cachedDevices);
            m_lastProbeTime = currentTime;
        }

        return m_cachedDevices;
    }

    void MidiMonitor::probeAndSetMidiDevices(std::vector<MidiDevice>& midiDevices) const
    {
        midiDevices.clear();

        if (m_rtMidiIn)
        {
            const unsigned int numPorts = m_rtMidiIn->getPortCount();
            for (unsigned int i = 0; i < numPorts; i++)
            {
                try
                {
                    std::string portName = m_rtMidiIn->getPortName(i);
                    appendNewDevice(portName, i, midiDevices);
                }
                catch (RtMidiError& error)
                {
                    error.printMessage();
                }
            }
        }
    }

    void MidiMonitor::appendNewDevice(const std::string& portName,  unsigned int portNumber, std::vector<MidiDevice>& midiDevices)
    {
        midiDevices.emplace_back(portName, portNumber);
    }

    void MidiMonitor::setInputListener(std::unique_ptr<IMidiInputListener> inputListener)
    {
        m_inputListener = std::move(inputListener);
    }

    unsigned int MidiMonitor::getMidiChannelNumber() const
    {
        return m_midiChannel;
    }

    void MidiMonitor::setMidiChannel(const unsigned int channelNumber)
    {
        m_midiChannel = channelNumber;
    }

    unsigned int MidiMonitor::getMidiPortNumber() const
    {
        return m_midiPort;
    }

    void MidiMonitor::setMidiPort(const unsigned int portNumber)
    {
        m_midiPort = portNumber;
    }

    std::string MidiMonitor::getConnectedDeviceName()
    {
        const std::vector<MidiDevice> connectedDevices = getMidiDevices();

        for (MidiDevice device : connectedDevices)
        {
            if (device.getPortNumber() == m_midiPort)
            {
                return device.getPortName();
            }
        }
        return "Midi device not connected.";
    }

    bool MidiMonitor::monitorThreadAlive() const
    {
        return m_monitorThread->joinable();
    }

    void MidiMonitor::startMonitoringThread()
    {
        try
        {
            m_monitorThread = std::make_unique<std::thread>(&MidiMonitor::monitor, this);
        }
        catch (std::system_error& error)
        {
            throw std::runtime_error(std::format("Failed to create MIDI monitoring thread: {}", error.what()));
        }
    }

    void MidiMonitor::cleanupThread()
    {
        if (m_monitorThread && m_monitorThread->joinable())
        {
            m_monitorThread->join();
        }

        m_monitorThread.reset();
    }

    void MidiMonitor::monitor() const
    {
        std::vector<unsigned char> midiMessage;

        while (m_running)
        {
            if (m_inputListener)
            {
                m_rtMidiIn->getMessage(&midiMessage);

                if (!midiMessage.empty())
                {
                    const unsigned int byte1 { midiMessage[0] };

                    if (const unsigned int action = byte1 & NOTE_MASK; action == NOTE_ON || action == NOTE_OFF)
                    {
                        const unsigned int noteNumber { midiMessage[1] };
                        const unsigned int velocity { midiMessage[2] };
                        unsigned int midiChannel { (byte1 & CHANNEL_MASK) + 1 };

                        if (m_midiChannel == static_cast<unsigned int>MIDI_CHANNEL_ALL | m_midiChannel == midiChannel)
                        {
                            if (action == NOTE_ON)
                            {
                                m_inputListener->onNoteOn(noteNumber, velocity, midiChannel);
                            }
                            else
                            {
                                m_inputListener->onNoteOff(noteNumber, velocity, midiChannel);
                            }
                        }
                    }
                    else
                    {
                        m_inputListener->onMidiEvent(midiMessage);
                    }
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
        }
        m_rtMidiIn->closePort();
    }
}