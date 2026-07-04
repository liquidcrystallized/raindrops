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

TEST_CASE("ConfigManager reset to defaults works")
{
    raindrops::ConfigManager& manager = raindrops::ConfigManager::getInstance();

    raindrops::ApplicationConfig newConfig {};
    newConfig.midiConfig.port = 1;
    newConfig.windowConfig.width = 1920;
    newConfig.appVersion = "2.0.0";
    manager.setConfig(newConfig);

    manager.resetToDefaults();
    const raindrops::ApplicationConfig& currentConfig = manager.getConfig();

    CHECK( currentConfig.midiConfig.port == 0 );
    CHECK( currentConfig.windowConfig.width == 1280 );
    CHECK( currentConfig.appVersion == "0.1.0" );
}

TEST_CASE("ConfigManager saveToFile creates valid JSON")
{
    raindrops::ConfigManager& manager = raindrops::ConfigManager::getInstance();
    const std::filesystem::path testFile = "./config.json";

    raindrops::ApplicationConfig newConfig {};
    newConfig.midiConfig.port = 7;
    newConfig.midiConfig.channel = 12;
    newConfig.midiConfig.autoDetect = false;
    newConfig.windowConfig.width = 1920;
    newConfig.windowConfig.height = 1080;
    newConfig.windowConfig.fullscreen = true;
    newConfig.musicSheetDisplayConfig.staffSpacing = 35.0f;
    manager.setConfig(newConfig);

    bool configSaved = manager.saveToFile(testFile);

    CHECK( configSaved == true );
    CHECK( std::filesystem::exists(testFile) );
    std::filesystem::remove(testFile);
}

TEST_CASE("ConfigManager saveToFile creates directories if needed")
{
    raindrops::ConfigManager& manager = raindrops::ConfigManager::getInstance();
    const std::filesystem::path testFile = "./user/config.json";
    const std::filesystem::path testFileFolder = testFile.parent_path();

    bool configSaved = manager.saveToFile(testFile);
    CHECK( configSaved == true );

    CHECK( std::filesystem::exists(testFileFolder) );
    std::filesystem::remove_all(testFileFolder);
}

TEST_CASE("ConfigManager save and load")
{
    raindrops::ConfigManager& manager = raindrops::ConfigManager::getInstance();
    const std::filesystem::path testFile = "./config.json";

    raindrops::ApplicationConfig newConfig {};
    newConfig.midiConfig.port = 7;
    newConfig.midiConfig.channel = 12;
    newConfig.midiConfig.autoDetect = false;
    newConfig.windowConfig.width = 1920;
    newConfig.windowConfig.height = 1080;
    newConfig.windowConfig.fullscreen = true;
    newConfig.musicSheetDisplayConfig.staffSpacing = 35.0f;
    manager.setConfig(newConfig);

    manager.saveToFile(testFile);
    manager.resetToDefaults();

    bool configLoaded = manager.loadFromFile(testFile);
    CHECK( configLoaded == true );

    const raindrops::ApplicationConfig& config = manager.getConfig();
    CHECK( config.midiConfig.port == 7 );
    CHECK( config.midiConfig.channel == 12 );
    CHECK( config.midiConfig.autoDetect == false );
    CHECK( config.windowConfig.width == 1920 );
    CHECK( config.windowConfig.height == 1080 );
    CHECK( config.windowConfig.fullscreen == true );
    CHECK( config.musicSheetDisplayConfig.staffSpacing == 35.0f );

    std::filesystem::remove(testFile);
}

TEST_SUITE_END;