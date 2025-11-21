#ifndef RAINDROPS_MIDISETUPMENUSTATE_HPP
#define RAINDROPS_MIDISETUPMENUSTATE_HPP

#include "State.hpp"
#include "VerticalStackPanel.hpp"
#include <raygui-cpp/Button.h>

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
        raylib::Rectangle m_verticalStackPanelSize;
        rgc::Bounds m_verticalStackPanelBounds;

        rgc::Button m_backButton;
        raylib::Rectangle m_buttonSize;

        const char* m_backButtonText;
        int m_buttonScalingFactor;

        void positionUIComponents();
    };
}

#endif //RAINDROPS_MIDISETUPMENUSTATE_HPP