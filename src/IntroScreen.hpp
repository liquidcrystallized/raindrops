#ifndef RAINDROPS_INTROSCREEN_HPP
#define RAINDROPS_INTROSCREEN_HPP


#include "Screen.hpp"
#include <SFML/Graphics/CircleShape.hpp>

class IntroScreen final : public Screen {
public:
    IntroScreen(ScreenManager& screenManager, sf::RenderWindow& renderWindow, bool replace = true);

    void pause() override;
    void resume() override;

    void update() override;
    void draw() override;

private:
    // For testing
    sf::CircleShape m_circleShape;
};


#endif //RAINDROPS_INTROSCREEN_HPP
