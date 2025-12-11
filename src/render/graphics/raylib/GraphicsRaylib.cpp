#include "GraphicsRaylib.hpp"
#include <iostream>

namespace raindrops
{
    GraphicsRaylib::GraphicsRaylib()
    {
        std::cout << "GraphicsRaylib constructed.\n";
    }

    GraphicsRaylib::~GraphicsRaylib()
    {
        std::cout << "GraphicsRaylib destructed.\n";
    }

    void GraphicsRaylib::draw() const
    {
        std::cout << "GraphicsRaylib::draw()\n";
    }
}
