#ifndef RAINDROPS_MIDIMONITOR_HPP
#define RAINDROPS_MIDIMONITOR_HPP

#include "MidiDevice.hpp"
#include "IMidiInputListener.hpp"
#include <memory>
#include <thread>

namespace raindrops
{
    /**
     * @brief rtmidi wrapper. For device monitoring. Allows event based midi event catching.
     */
    class MidiMonitor final {
    public:
        MidiMonitor();
        ~MidiMonitor();

        bool startMonitoring(unsigned int midiPort, unsigned int midiChannel);
        void stopMonitoring();

        [[nodiscard]] std::vector<MidiDevice> getMidiDevices() const;
        void probeAndSetMidiDevices(std::vector<MidiDevice>& midiDevices) const;

        void setInputListener(std::unique_ptr<IMidiInputListener> inputListener);

        [[nodiscard]] unsigned int getMidiChannelNumber() const;
        void setMidiChannel(unsigned int channelNumber);

        [[nodiscard]] unsigned int getMidiPortNumber() const;
        void setMidiPort(unsigned int portNumber);

    private:
        bool m_running;
        unsigned int m_midiPort;
        unsigned int m_midiChannel;

        std::unique_ptr<std::thread> m_monitorThread;
        std::unique_ptr<RtMidiIn> m_rtMidiIn;
        std::unique_ptr<IMidiInputListener> m_inputListener;

        /**
         * @brief Thread function that periodically checks for new midi events.
         */
        void monitor() const;
    };
}


#endif //RAINDROPS_MIDIMONITOR_HPP