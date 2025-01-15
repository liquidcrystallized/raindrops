#include "ScreenManager.hpp"
#include <iostream>

ScreenManager::ScreenManager()
: m_resume{ false }
, m_running{ false }
{
    std::cout << "ScreenManager Init\n";
}

void ScreenManager::run(std::unique_ptr<Screen> screen)
{
    m_running = true;

    m_screens.push(std::move(screen));
}

void ScreenManager::next_screen()
{
    if (m_resume)
    {
        // Cleanup the current screen
        if (!m_screens.empty())
        {
            m_screens.pop();
        }

        // Resume previous screen
        if (!m_screens.empty())
        {
            m_screens.top()->resume();
        }

        m_resume = false;
    }

    // There needs to be a screen
    if (!m_screens.empty())
    {
        std::unique_ptr<Screen> temp = m_screens.top()->next();

        // Only change screens if there's a next one existing
        if (temp != nullptr)
        {
            // Replace the running screen
            if (temp->is_replacing())
            {
                m_screens.pop();
            }
            // Pause the running screen
            else
            {
                m_screens.top()->pause();
            }

            m_screens.push(std::move(temp));
        }
    }
}

void ScreenManager::last_screen()
{
    m_resume = true;
}

void ScreenManager::update_current_screen()
{
    // Allow the current screen to update its contents
    m_screens.top()->update();
}

void ScreenManager::draw_current_screen()
{
    // Allow the current screen to draw its contents
    m_screens.top()->draw();
}

bool ScreenManager::is_running() const
{
    return m_running;
}

void ScreenManager::quit()
{
    m_running = false;
}
