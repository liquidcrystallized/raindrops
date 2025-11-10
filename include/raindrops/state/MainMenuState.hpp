#ifndef RAINDROPS_MAINMENUSTATE_HPP
#define RAINDROPS_MAINMENUSTATE_HPP

#include "State.hpp"
#include <SFML/Graphics.hpp>

namespace raindrops
{
    class MainMenuState final : public State {
    public:
        MainMenuState(StateMachine& stateMachine, sf::RenderWindow& renderWindow, bool replace = true);

        void pause() override;
        void resume() override;

        void update() override;
        void draw() override;
    private:
        sf::RectangleShape m_testRectangle;
    };
}


#endif //RAINDROPS_MAINMENUSTATE_HPP