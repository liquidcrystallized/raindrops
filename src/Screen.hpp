#ifndef RAINDROPS_SCREEN_HPP
#define RAINDROPS_SCREEN_HPP


#include "ScreenManager.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

class Screen {
public:
    Screen(ScreenManager& screenManager, sf::RenderWindow& renderWindow, bool replace = true);
    virtual ~Screen() = default;

    Screen(const Screen&) = delete;
    Screen& operator=(const Screen&) = delete;

    virtual void pause() = 0;
    virtual void resume() = 0;

    virtual void update() = 0;
    virtual void draw() = 0;

    std::unique_ptr<Screen> next();

    [[nodiscard]] bool is_replacing() const;

protected:
    ScreenManager& m_screenManager;
    sf::RenderWindow& m_renderWindow;

    std::unique_ptr<Screen> m_next;

    bool m_replacing;
};


#endif //RAINDROPS_SCREEN_HPP
