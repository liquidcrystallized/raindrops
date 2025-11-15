#ifndef RAINDROPS_SETTINGSMENUSTATE_HPP
#define RAINDROPS_SETTINGSMENUSTATE_HPP

#include "State.hpp"
#include <raygui-cpp/Button.h>

namespace raindrops
{
    /**
     * @brief The settings screen. Where users change things like screen res.
     */
    class SettingsMenuState final : public State {
    public:
        SettingsMenuState(StateMachine& stateMachine, raylib::Window& renderWindow, bool replace = true);

        void pause() override;
        void resume() override;

        void update() override;
        void draw() override;
    private:
        rgc::Button m_backButton;

        const char* m_backButtonText;
        bool m_backButtonCanClick;

        void setupUI();
    };
}


#endif //RAINDROPS_SETTINGSMENUSTATE_HPP