#ifndef RAINDROPS_APPLICATION_HPP
#define RAINDROPS_APPLICATION_HPP


#include "SFML/Graphics/RenderWindow.hpp"

class Application {
public:
    void run();

private:
    sf::RenderWindow m_renderWindow;
};


#endif //RAINDROPS_APPLICATION_HPP
