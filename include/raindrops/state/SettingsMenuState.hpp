#ifndef RAINDROPS_SETTINGSMENUSTATE_HPP
#define RAINDROPS_SETTINGSMENUSTATE_HPP

#include "State.hpp"
#include "VerticalStackPanel.hpp"
#include <raygui-cpp/Button.h>

namespace raindrops
{
    /**
     * @brief The settings screen. Where users can select their midi device and etc.
     */
    class SettingsMenuState final : public State {
    public:
        SettingsMenuState(StateMachine& stateMachine, raylib::Window& renderWindow, bool replace = true);

        void pause() override;
        void resume() override;

        void update() override;
        void draw() override;

        void onWindowResize() override;
    private:
        VerticalStackPanel m_verticalStackPanel;
        raylib::Rectangle m_verticalStackPanelSize;
        rgc::Bounds m_verticalStackPanelBounds;

        rgc::Button m_midiSetupMenuButton;
        rgc::Button m_backButton;
        raylib::Rectangle m_buttonSize;

        const char* m_midiSetupMenuButtonText;
        const char* m_backButtonText;
        int m_buttonScalingFactor;

        void positionUIComponents();
    };
}


#endif //RAINDROPS_SETTINGSMENUSTATE_HPP