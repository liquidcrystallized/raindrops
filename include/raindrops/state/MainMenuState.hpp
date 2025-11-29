#ifndef RAINDROPS_MAINMENUSTATE_HPP
#define RAINDROPS_MAINMENUSTATE_HPP

#include "State.hpp"
#include "VerticalStackPanel.hpp"
#include <raygui-cpp/Button.h>

namespace raindrops
{
    class MainMenuState final : public State {
    public:
        MainMenuState(StateMachine&, raylib::Window&, MidiMonitor&, bool replace = true);

        void pause() override;
        void resume() override;

        void update() override;
        void draw() override;

        void onWindowResize() override;
    private:
        VerticalStackPanel m_verticalStackPanel;
        raylib::Rectangle m_verticalStackPanelSize;
        rgc::Bounds m_verticalStackPanelBounds;

        rgc::Button m_playButton;
        rgc::Button m_settingsMenuButton;
        rgc::Button m_quitButton;
        raylib::Rectangle m_buttonSize;

        const char* m_playButtonText;
        const char* m_settingsMenuButtonText;
        const char* m_quitButtonText;
        int m_buttonScalingFactor;

        void positionUIComponents();
    };
}


#endif //RAINDROPS_MAINMENUSTATE_HPP