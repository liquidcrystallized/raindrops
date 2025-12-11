#include "GraphicsRaylib.hpp"
#include "Renderer.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("Renderer");

// Temp
TEST_CASE("")
{
    raindrops::GraphicsRaylib raylib {};
    raindrops::Renderer renderer { raylib };

    renderer.draw();

    CHECK( true );
}

TEST_SUITE_END();