#include "Application.hpp"
#include "ConfigManager.hpp"
#include "GraphicsRaylib.hpp"
#include "KeyboardInputRaylib.hpp"

int main()
{
    auto& configManger = raindrops::ConfigManager::getInstance();

    bool configLoaded = configManger.loadFromDefaultLocation();

    if (!configLoaded)
    {
        std::println("Creating and using default config.");
        configManger.resetToDefaults();
        configManger.saveToDefaultLocation();
        configManger.loadFromDefaultLocation();
    }

    raindrops::GraphicsRaylib renderer {};
    raindrops::KeyboardInputRaylib keyboardInput {};
    raindrops::Application application { renderer, keyboardInput };

    return 0;
}
