#include "GraphicsRaylib.hpp"
#include "raygui-defguard.hpp"
#include <iostream>

namespace raindrops
{
    GraphicsRaylib::GraphicsRaylib()
    {
        // Graphics related setup
        m_window.SetConfigFlags(FLAG_WINDOW_RESIZABLE);
        m_window.Init(1280, 720, "raindrops [dev]");
        m_window.SetTargetFPS(60);

        // Note: Default raylib font looks bad if not in multiples of 10.
        rgc::Globals::Style::GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
        std::cout << "GraphicsRaylib constructed.\n";
    }

    GraphicsRaylib::~GraphicsRaylib()
    {
        std::cout << "GraphicsRaylib destructed.\n";
    }

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

    void GraphicsRaylib::toggleTestMode()
    {
        m_window.SetTargetFPS(1);
        m_window.SetConfigFlags(FLAG_WINDOW_HIDDEN);
    }
}
