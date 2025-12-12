#include "GraphicsRaylib.hpp"
#include "Renderer.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("Renderer");

TEST_CASE("Renderer gets correct width and height")
{
    SUBCASE("Renderer: raylib")
    {
        raindrops::GraphicsRaylib raylib {};
        raylib.setWindowWidth(1280);
        raylib.setWindowHeight(720);

        raindrops::Renderer renderer { raylib };

        int expectedWindowWidth { 1280 };
        int expectedWindowHeight { 720 };

        CHECK( expectedWindowWidth == renderer.getWindowWidth() );
        CHECK( expectedWindowHeight == renderer.getWindowHeight() );
    }
}

TEST_CASE("Renderer sets correct width and height")
{
    SUBCASE("Renderer: raylib")
    {
        raindrops::GraphicsRaylib raylib {};
        raylib.setWindowWidth(1280);
        raylib.setWindowHeight(720);

        raindrops::Renderer renderer { raylib };
        renderer.setWindowWidth(1920);
        renderer.setWindowHeight(1080);

        int expectedWindowWidth { 1920 };
        int expectedWindowHeight { 1080 };

        CHECK( expectedWindowWidth == renderer.getWindowWidth() );
        CHECK( expectedWindowHeight == renderer.getWindowHeight() );
    }
}

TEST_SUITE_END();