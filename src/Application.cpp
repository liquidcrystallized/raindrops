#include "Application.hpp"

void Application::run()
{
    m_renderWindow.create(sf::VideoMode({640, 480}), "raindrops [dev]");
    m_renderWindow.setFramerateLimit(60);

    while (m_renderWindow.isOpen())
    {
        m_renderWindow.clear();
        m_renderWindow.display();
    }
}
