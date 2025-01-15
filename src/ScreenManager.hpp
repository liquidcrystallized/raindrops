#ifndef RAINDROPS_SCREENMANAGER_HPP
#define RAINDROPS_SCREENMANAGER_HPP


#include "Screen.hpp"
#include <iostream>
#include <memory>
#include <stack>

class ScreenManager {
public:
    ScreenManager();

    void run(std::unique_ptr<Screen> screen);

    void next_screen();
    void last_screen();

    void update_current_screen();
    void draw_current_screen();

    [[nodiscard]] bool is_running() const;
    void quit();

    template <typename T>
    static std::unique_ptr<T> build(ScreenManager& screenManager, sf::RenderWindow& renderWindow, bool replace = true);

private:
    std::stack<std::unique_ptr<Screen>> m_screens;

    bool m_resume;
    bool m_running;
};

template <typename T>
std::unique_ptr<T> ScreenManager::build(ScreenManager& screenManager, sf::RenderWindow& renderWindow, bool replace)
{
    auto new_screen = std::unique_ptr<T>{ nullptr };

    try
    {
        new_screen = std::make_unique<T>(screenManager, renderWindow, replace);
    }
    catch(std::runtime_error& exception)
    {
        std::cout << "Creation of new screen was unsuccessful\n";
        std::cout << exception.what() << std::endl;
    }

    return new_screen;
}

#endif //RAINDROPS_SCREENMANAGER_HPP
