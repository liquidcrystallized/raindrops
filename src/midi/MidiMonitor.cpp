#include "MidiMonitor.hpp"
#include "MidiMessageList.hpp"

namespace raindrops
{
    MidiMonitor::MidiMonitor() : m_running(false)
    {
        try
        {
            m_rtMidiIn = std::make_shared<RtMidiIn>();
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
            m_monitorThread = std::make_shared<std::thread>(&MidiMonitor::monitor, this);
        }
        catch (RtMidiError& error)
        {
            error.printMessage();
            return false;
        }

        return true;
    }

    void MidiMonitor::stopMonitoring()
    {
        m_running = false;

        if (m_monitorThread)
        {
            m_monitorThread->join();
        }
    }

    void MidiMonitor::listDevices(std::vector<MidiDevice>& midiDevices) const
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
                    midiDevices.emplace_back(portName, i);
                }
                catch (RtMidiError& error)
                {
                    error.printMessage();
                }
            }
        }
    }

    void MidiMonitor::setInputListener(const std::shared_ptr<IMidiInputListener>& inputListener)
    {
        m_inputListener = inputListener;
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
                    const int byte1 = midiMessage[0];

                    if (const int action = byte1 & NOTE_MASK; action == NOTE_ON || action == NOTE_OFF)
                    {
                        const int noteNumber = midiMessage[1];
                        const int velocity = midiMessage[2];
                        unsigned int midiChannel = (byte1 & CHANNEL_MASK) + 1;

                        if (m_midiChannel == MIDI_CHANNEL_ALL | midiChannel == m_midiChannel)
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
                usleep(10000);
            }
        }
        m_rtMidiIn->closePort();
    }

}