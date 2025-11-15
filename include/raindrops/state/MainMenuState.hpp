#ifndef RAINDROPS_MAINMENUSTATE_HPP
#define RAINDROPS_MAINMENUSTATE_HPP

#include "State.hpp"
#include <raygui-cpp/Button.h>
#include <raygui-cpp/ListView.h>
#include <raygui-cpp/Panel.h>

namespace raindrops
{
    class MainMenuState final : public State {
    public:
        MainMenuState(StateMachine& stateMachine, raylib::Window& renderWindow, bool replace = true);

        void pause() override;
        void resume() override;

        void update() override;
        void draw() override;
    private:
        rgc::Button m_settingsMenuButton;
        rgc::Button m_quitButton;

        const char* m_settingsMenuButtonText;
        const char* m_quitButtonText;
        bool m_settingsMenuButtonCanClick;
        bool m_quitButtonCanClick;

        void setupUI();
    };
}


#endif //RAINDROPS_MAINMENUSTATE_HPP