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

    void GraphicsRaylib::toggleTestMode()
    {
        m_window.SetTargetFPS(1);
        m_window.SetConfigFlags(FLAG_WINDOW_HIDDEN);
    }
}
