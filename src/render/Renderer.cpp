#include "Renderer.hpp"
#include <iostream>

namespace raindrops
{
    Renderer::Renderer(const IGraphics& graphics)
    : m_graphics { graphics }
    {
        std::cout << "Renderer constructed.\n";
    }

    Renderer::~Renderer()
    {
        std::cout << "Renderer destructed.\n";
    }

    void Renderer::draw() const
    {
        std::cout << "Renderer: 'drawing' something arbitrary.\n";
        m_graphics.draw();
    }
}
