#include "GraphicsNull.hpp"

namespace raindrops
{
    void GraphicsNull::drawStart() { }
    void GraphicsNull::drawEnd() { }

    int GraphicsNull::getWindowWidth() const
    {
        return m_windowWidth;
    }

    void GraphicsNull::setWindowWidth(const int width)
    {
        m_windowWidth = width;
    }

    int GraphicsNull::getWindowHeight() const
    {
        return m_windowHeight;
    }

    void GraphicsNull::setWindowHeight(const int height)
    {
        m_windowHeight = height;
    }

    bool GraphicsNull::windowResized() const
    {
        return m_windowResized;
    }

    void GraphicsNull::drawLine(float startX, float startY, float endX, float endY, int thickness, Colour colour) { }
    void GraphicsNull::drawCircle(float centreX, float centreY, float radius, Colour colour) { }
    void GraphicsNull::drawText(std::string text, float positionX, float positionY, int fontSize, Colour colour) { }

    void GraphicsNull::toggleTestMode()
    {
        m_testMode = true;
    }
}
