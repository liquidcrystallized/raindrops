#ifndef RAINDROPS_MIDISETUPMENUSTATE_HPP
#define RAINDROPS_MIDISETUPMENUSTATE_HPP

#include "State.hpp"
#include "VerticalStackPanel.hpp"
#include <raygui-cpp/Button.h>
#include <raygui-cpp/ListView.h>

namespace raindrops
{
    class MidiSetupMenuState final : public State {
    public:
        MidiSetupMenuState(StateMachine& stateMachine, raylib::Window& renderWindow, bool replace = true);

        void pause() override;
        void resume() override;

        void update() override;
        void draw() override;

        void onWindowResize() override;
    private:
        VerticalStackPanel m_verticalStackPanel;
        VerticalStackPanel m_innerVerticalStackPanel;
        raylib::Rectangle m_verticalStackPanelSize;
        raylib::Rectangle m_innerVerticalStackPanelSize;
        rgc::Bounds m_verticalStackPanelBounds;
        rgc::Bounds m_innerVerticalStackPanelBounds;

        rgc::ListView m_midiDeviceListView;
        rgc::Bounds m_midiDeviceListViewBounds;
        int m_midiDeviceListViewScrollIndex;
        int m_midiDeviceListViewActiveSelection;
        const char* m_midiDeviceListViewText;

        rgc::Button m_applyButton;
        rgc::Button m_backButton;
        raylib::Rectangle m_buttonSize;

        const char* m_applyButtonText;
        const char* m_backButtonText;
        int m_buttonScalingFactor;

        void positionUIComponents();
    };
}

#endif //RAINDROPS_MIDISETUPMENUSTATE_HPP