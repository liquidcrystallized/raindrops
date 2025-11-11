#include "raindrops/state/MainMenuState.hpp"
#include "raindrops/state/PlayingState.hpp"
#include "raindrops/state/StateMachine.hpp"
#include <iostream>

namespace raindrops
{
    MainMenuState::MainMenuState(StateMachine &stateMachine, sf::RenderWindow &renderWindow, const bool replace)
    : State { stateMachine, renderWindow, replace, "MainMenuState" }
    {
        m_testRectangle.setSize({100, 100});
        m_testRectangle.setFillColor(sf::Color::Red);
        std::cout << "MainMenuState Init\n";
    }

    void MainMenuState::pause()
    {
        std::cout << "MainMenuState Pause\n";
    }

    void MainMenuState::resume()
    {
        std::cout << "MainMenuState Resume\n";
    }

    void MainMenuState::update()
    {
        while (const std::optional event = m_renderWindow.pollEvent())
        {
            if (event->getIf<sf::Event::Closed>())
            {
                m_renderWindow.close();
            }

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                switch (keyPressed->code)
                {
                    case sf::Keyboard::Key::Escape:
                        m_stateMachine.lastState();
                        break;
                    case sf::Keyboard::Key::M:
                        m_next = StateMachine::build<PlayingState>(m_stateMachine, m_renderWindow, false);
                        break;
                    default:
                        break;
                }
            }
        }
    }

    void MainMenuState::draw()
    {
        m_renderWindow.clear();
        m_renderWindow.draw(m_testRectangle);
        m_renderWindow.display();
    }
}
