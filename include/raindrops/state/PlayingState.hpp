#ifndef RAINDROPS_PLAYINGSTATE_HPP
#define RAINDROPS_PLAYINGSTATE_HPP

#include "State.hpp"

namespace raindrops
{
    class PlayingState final : public State {
    public:
        PlayingState(StateMachine& stateMachine, raylib::Window& renderWindow, bool replace = true);

        void pause() override;
        void resume() override;

        void update() override;
        void draw() override;
    private:
        raylib::Rectangle m_testRectangle;
    };
}


#endif //RAINDROPS_PLAYINGSTATE_HPP