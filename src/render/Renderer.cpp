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

    void Renderer::drawLine(const float startX, const float startY, const float endX, const float endY, const int thickness, const Colour colour) const
    {
        m_graphics.drawLine(startX, startY, endX, endY, thickness, colour);
    }

    void Renderer::drawCircle(const float centreX, const float centreY, const float radius, const Colour colour) const
    {
        m_graphics.drawCircle(centreX, centreY, radius, colour);
    }

    void Renderer::drawText(const std::string& text, const float positionX, const float positionY, const int fontSize, const Colour colour) const
    {
        m_graphics.drawText(text, positionX, positionY, fontSize, colour);
    }

    void Renderer::toggleTestMode() const
    {
        m_graphics.toggleTestMode();
    }
}
