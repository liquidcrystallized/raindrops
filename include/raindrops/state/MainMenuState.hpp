#ifndef RAINDROPS_MAINMENUSTATE_HPP
#define RAINDROPS_MAINMENUSTATE_HPP

#include "State.hpp"

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
        raylib::Rectangle m_testRectangle;
    };
}


#endif //RAINDROPS_MAINMENUSTATE_HPP