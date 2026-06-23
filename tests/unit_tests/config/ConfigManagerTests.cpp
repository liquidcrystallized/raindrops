#include "ConfigManager.hpp"
#include "ApplicationConfig.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("ConfigManager");

TEST_CASE("ConfigManager is a singleton (two instances have the same address)")
{
    raindrops::ConfigManager& instance1 = raindrops::ConfigManager::getInstance();
    raindrops::ConfigManager& instance2 = raindrops::ConfigManager::getInstance();

    CHECK( &instance1 == &instance2 );
}

TEST_CASE("ConfigManager loads default config")
{
    raindrops::ConfigManager& manager = raindrops::ConfigManager::getInstance();
    const raindrops::ApplicationConfig& config = manager.getConfig();

    CHECK( config.midiConfig.port == 0 );
    CHECK( config.windowConfig.width == 1280 );
    CHECK( config.appName == "raindrops" );
}

TEST_CASE("ConfigManager overrides config with another")
{
    raindrops::ConfigManager& manager = raindrops::ConfigManager::getInstance();

    raindrops::ApplicationConfig newConfig {};
    newConfig.midiConfig.port = 1;
    newConfig.windowConfig.width = 1920;
    newConfig.appVersion = "2.0.0";
    manager.setConfig(newConfig);

    const raindrops::ApplicationConfig& currentConfig = manager.getConfig();

    CHECK( currentConfig.midiConfig.port == 1 );
    CHECK( currentConfig.windowConfig.width == 1920 );
    CHECK( currentConfig.appVersion == "2.0.0" );
}

TEST_SUITE_END;