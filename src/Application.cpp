#include "Application.hpp"
#include "IntroScreen.hpp"

void Application::run()
{
    // Create render window
    m_renderWindow.create(sf::VideoMode({ 640, 480 }), "raindrops v0.1.0", sf::Style::Titlebar | sf::Style::Close);
    m_renderWindow.setFramerateLimit(60);

    // Initialise screen manager
    m_screenManager.run(ScreenManager::build<IntroScreen>(m_screenManager, m_renderWindow, true));

    // Main application loop
    while (m_screenManager.is_running())
    {
        m_screenManager.next_screen();
        m_screenManager.update_current_screen();
        m_screenManager.draw_current_screen();
    }
}
