#ifndef RAINDROPS_SETTINGSMENUSTATE_HPP
#define RAINDROPS_SETTINGSMENUSTATE_HPP

#include "State.hpp"

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
        raylib::Rectangle m_testRectangle;
    };
}


#endif //RAINDROPS_SETTINGSMENUSTATE_HPP