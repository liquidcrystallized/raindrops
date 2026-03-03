#ifndef RAINDROPS_SONGSELECTIONSTATE_HPP
#define RAINDROPS_SONGSELECTIONSTATE_HPP

#include "State.hpp"
#include <raygui-cpp/Label.h>

namespace raindrops
{
    class SongSelectionState final : public State {
    public:
        SongSelectionState(StateMachine&, Renderer&, MidiMonitor&, bool replace = true);

        void pause() override;
        void resume() override;

        void update() override;
        void draw() override;

        void onWindowResize() override;
    private:
        std::vector<MidiDevice> m_midiDevices;
        rgc::Label m_connectedDeviceLabel;
        std::string m_deviceList;
        std::string m_connectedDeviceLabelText;

        void positionUIComponents();
    };
}


#endif //RAINDROPS_SONGSELECTIONSTATE_HPP