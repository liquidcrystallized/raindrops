#include "Renderer.hpp"

namespace raindrops
{
    Renderer::Renderer(IGraphics& graphics) : m_graphics { graphics } {}

    Renderer::~Renderer() = default;

    void Renderer::drawStart() const
    {
        m_graphics.drawStart();
    }

    void Renderer::drawEnd() const
    {
        m_graphics.drawEnd();
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

    bool Renderer::windowResized() const
    {
        return m_graphics.windowResized();
    }

    void Renderer::toggleTestMode() const
    {
        m_graphics.toggleTestMode();
    }
}
