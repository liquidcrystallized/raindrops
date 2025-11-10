#include "PlayingState.hpp"
#include "MainMenuState.hpp"
#include "StateMachine.hpp"
#include <iostream>

namespace raindrops
{
    PlayingState::PlayingState(StateMachine &stateMachine, sf::RenderWindow &renderWindow, const bool replace)
    : State { stateMachine, renderWindow, replace }
    {
        m_testRectangle.setSize({100, 100});
        m_testRectangle.setFillColor(sf::Color::Green);
        std::cout << "PlayingState Init\n";
    }

    void PlayingState::pause()
    {
        std::cout << "PlayingState Pause\n";
    }

    void PlayingState::resume()
    {
        std::cout << "PlayingState Resume\n";
    }

    void PlayingState::update()
    {
        while (const std::optional event = m_renderWindow.pollEvent())
        {
            if (event->getIf<sf::Event::Closed>())
            {
                m_stateMachine.quit();
            }

            if (const auto keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                switch (keyPressed->code)
                {
                    case sf::Keyboard::Key::Escape:
                        m_stateMachine.lastState();
                        break;
                    case::sf::Keyboard::Key::M:
                        m_next = StateMachine::build<MainMenuState>(m_stateMachine, m_renderWindow, false);
                        break;
                    default:
                        break;
                }
            }
        }
    }

    void PlayingState::draw()
    {
        m_renderWindow.clear();
        m_renderWindow.draw(m_testRectangle);
        m_renderWindow.display();
    }
}
