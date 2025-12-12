#include "Renderer.hpp"
#include <iostream>

namespace raindrops
{
    Renderer::Renderer(IGraphics& graphics)
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

    int Renderer::getWindowWidth() const
    {
        return m_graphics.getWindowWidth();
    }

    void Renderer::setWindowWidth(const int width) const
    {
        m_graphics.setWindowWidth(width);
    }

    int Renderer::getWindowHeight() const
    {
        return m_graphics.getWindowHeight();
    }

    void Renderer::setWindowHeight(const int height) const
    {
        m_graphics.setWindowHeight(height);
    }
}
