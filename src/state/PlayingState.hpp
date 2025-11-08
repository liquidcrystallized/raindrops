#ifndef RAINDROPS_PLAYINGSTATE_HPP
#define RAINDROPS_PLAYINGSTATE_HPP

#include "State.hpp"
#include <SFML/Graphics.hpp>

namespace raindrops
{
    class PlayingState final : public State {
    public:
        PlayingState(StateMachine& stateMachine, sf::RenderWindow& renderWindow, bool replace = true);

        void pause() override;
        void resume() override;

        void update() override;
        void draw() override;
    private:
        sf::RectangleShape m_testRectangle;
    };
}


#endif //RAINDROPS_PLAYINGSTATE_HPP