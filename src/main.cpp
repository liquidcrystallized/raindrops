#include "Application.hpp"
#include "GraphicsRaylib.hpp"

int main()
{
    raindrops::GraphicsRaylib renderer {}; //TODO: Choose renderer based on config.
    raindrops::Application application { renderer };

    return 0;
}
