#ifndef RAINDROPS_SONGSELECTIONSTATE_HPP
#define RAINDROPS_SONGSELECTIONSTATE_HPP

#include "State.hpp"
#include "MusicSheet.hpp"
#include "MusicXmlReader.hpp"
#include "MxReader.hpp"
#include "VerticalStackPanel.hpp"
#include <raygui-cpp/Button.h>
#include <raygui-cpp/Label.h>
#include <raygui-cpp/ListView.h>
#include <filesystem>

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

        std::filesystem::path m_songDirectory;
        std::string m_songList;
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

        rgc::Label m_connectedDeviceLabel;
        std::string m_connectedDeviceLabelText;

        std::unique_ptr<MusicSheet> m_selectedSong;
        MxReader mx {};
        MusicXmlReader m_musicXmlReader { mx }; //TODO: Init elsewhere.

        void positionUIComponents();
        void refreshSongList();
        bool loadSelectedSong(const std::string& filePathForSelectedSong);
    };
}


#endif //RAINDROPS_SONGSELECTIONSTATE_HPP