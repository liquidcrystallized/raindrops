#ifndef RAINDROPS_SONGSELECTIONSTATE_HPP
#define RAINDROPS_SONGSELECTIONSTATE_HPP

#include "State.hpp"
#include "VerticalStackPanel.hpp"
#include <raygui-cpp/Button.h>
#include <raygui-cpp/Label.h>
#include <raygui-cpp/ListView.h>

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
        VerticalStackPanel m_verticalStackPanel;
        raylib::Rectangle m_verticalStackPanelSize;
        rgc::Bounds m_verticalStackPanelBounds;

        rgc::ListView m_songListView;
        rgc::Bounds m_songListViewBounds;
        int m_songListViewScrollIndex;
        int m_songListViewActiveSelection;
        const char* m_songListViewText;

        rgc::Button m_playButton;
        rgc::Button m_backButton;
        rgc::Button m_refreshButton;
        raylib::Rectangle m_buttonSize;

        const char* m_playButtonText;
        const char* m_backButtonText;
        const char* m_refreshButtonText;
        int m_buttonScalingFactor;

        std::vector<MidiDevice> m_midiDevices;
        rgc::Label m_connectedDeviceLabel;
        std::string m_deviceList;
        std::string m_connectedDeviceLabelText;

        void positionUIComponents();
        void refreshSongList();
    };
}


#endif //RAINDROPS_SONGSELECTIONSTATE_HPP