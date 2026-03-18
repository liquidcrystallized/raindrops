#include "GraphicsRaylib.hpp"
#include "raygui-defguard.hpp"

namespace raindrops
{
    GraphicsRaylib::GraphicsRaylib()
    {
        SetTraceLogLevel(LOG_NONE);

        // Graphics related setup
        m_window.SetConfigFlags(FLAG_WINDOW_RESIZABLE);
        m_window.Init(1280, 720, "raindrops [dev]");
        m_window.SetTargetFPS(60);

        // Note: Default raylib font looks bad if not in multiples of 10.
        rgc::Globals::Style::GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
    }

    GraphicsRaylib::~GraphicsRaylib() = default;

    void GraphicsRaylib::drawStart()
    {
        m_window.BeginDrawing();
        m_window.ClearBackground(raylib::Color::RayWhite()); //TODO: Uh, move this somewhere.
    }

    void GraphicsRaylib::drawEnd()
    {
        m_window.EndDrawing();
    }

    int GraphicsRaylib::getWindowWidth() const
    {
        return m_window.GetWidth();
    }

    void GraphicsRaylib::setWindowWidth(const int width)
    {
        m_window.SetSize(width, m_window.GetHeight());
    }

    int GraphicsRaylib::getWindowHeight() const
    {
        return m_window.GetHeight();
    }

    void GraphicsRaylib::setWindowHeight(const int height)
    {
        m_window.SetSize(m_window.GetWidth(), height);
    }

    bool GraphicsRaylib::windowResized() const
    {
        return m_window.IsResized();
    }

    void GraphicsRaylib::drawLine(const float startX, const float startY, const float endX, const float endY, const int thickness, std::string colour)
    {
        const raylib::Vector2 startPosition { startX, startY };
        const raylib::Vector2 endPosition { endX, endY };
        const raylib::Color lineColour { raylib::Color::Black() };
        lineColour.DrawLine(startPosition, endPosition, static_cast<float>(thickness));
    }

    void GraphicsRaylib::drawCircle(const float centreX, const float centreY, const float radius, std::string colour)
    {
        const raylib::Vector2 centerPosition { centreX, centreY };
        const raylib::Color circleColour { raylib::Color::Black() };
        centerPosition.DrawCircle(radius, circleColour);
    }

    void GraphicsRaylib::drawText(const std::string text, const float positionX, const float positionY, const int fontSize, std::string colour)
    {
        raylib::Text::Draw(text, static_cast<int>(positionX), static_cast<int>(positionY), fontSize, raylib::Color::Black());
    }

    void GraphicsRaylib::toggleTestMode()
    {
        m_window.SetTargetFPS(1);
        m_window.SetConfigFlags(FLAG_WINDOW_HIDDEN);
    }
}
