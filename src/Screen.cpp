#include "Screen.hpp"

Screen::Screen(ScreenManager& screenManager, sf::RenderWindow& renderWindow, bool replace)
: m_screenManager{ screenManager }
, m_renderWindow{ renderWindow }
, m_replacing{ replace }
{

}

std::unique_ptr<Screen> Screen::next()
{
    return std::move( m_next );
}

bool Screen::is_replacing() const
{
    return m_replacing;
}
