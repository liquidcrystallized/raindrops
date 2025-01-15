#include <iostream>
#include "IntroScreen.hpp"

IntroScreen::IntroScreen(ScreenManager &screenManager, sf::RenderWindow &renderWindow, bool replace)
: Screen{ screenManager, renderWindow, replace }
, m_circleShape{ 100.f }
{
    m_circleShape.setFillColor(sf::Color::Green);

    std::cout << "IntroScreen Init\n";
}

void IntroScreen::pause()
{
    std::cout << "IntroScreen Pause\n";
}

void IntroScreen::resume()
{
    std::cout << "IntroScreen Resume\n";
}

void IntroScreen::update()
{
    //for (auto event = sf::Event{}; m_renderWindow.pollEvent(event))
    const std::optional event = m_renderWindow.pollEvent();

    if (event->is<sf::Event::Closed>())
    {
        m_renderWindow.close();
    }
    else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
        {
            m_renderWindow.close();
        }
    }
}

void IntroScreen::draw()
{
    // Clear the previous drawing and draw the circle
    m_renderWindow.clear();
    m_renderWindow.draw(m_circleShape);
    m_renderWindow.display();
}
