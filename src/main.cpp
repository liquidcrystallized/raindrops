#include "Application.hpp"
#include "GraphicsRaylib.hpp"
#include "Renderer.hpp"

int main()
{
    raindrops::GraphicsRaylib raylib {};
    raindrops::Renderer renderer { raylib }; //TODO: Choose renderer based on config.
    raindrops::Application application { renderer };

    return 0;
}
