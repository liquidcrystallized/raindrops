#ifndef RAINDROPS_APPLICATION_HPP
#define RAINDROPS_APPLICATION_HPP


#include "ScreenManager.hpp"

class Application {
public:
    void run();

private:
    ScreenManager m_screenManager;
    sf::RenderWindow m_renderWindow;
};


#endif //RAINDROPS_APPLICATION_HPP
