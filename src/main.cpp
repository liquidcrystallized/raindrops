#include "Application.hpp"
#include "ConfigManager.hpp"
#include "GraphicsRaylib.hpp"

int main()
{
    auto& configManger = raindrops::ConfigManager::getInstance();

    bool configLoaded = configManger.loadFromDefaultLocation();

    if (!configLoaded)
    {
        std::cout << "Creating and using default config." << std::endl;
        configManger.resetToDefaults();
        configManger.saveToDefaultLocation();
        configManger.loadFromDefaultLocation();
    }

    raindrops::GraphicsRaylib renderer {}; //TODO: Choose renderer based on config.
    raindrops::Application application { renderer };

    return 0;
}
