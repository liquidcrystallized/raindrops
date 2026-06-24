#include "DefaultConfigFactory.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("DefaultConfigFactory");

TEST_CASE("DefaultConfigFactory creates valid ApplicationConfig")
{
    raindrops::ApplicationConfig config = raindrops::DefaultConfigFactory::create();

    CHECK( config.isValid() == true );
}

TEST_CASE("DefaultConfigFactory sets correct metadata defaults")
{
    raindrops::ApplicationConfig config = raindrops::DefaultConfigFactory::create();

    CHECK( config.appName == "raindrops" );
    CHECK( config.appVersion == "0.1.0" );
}

TEST_CASE("DefaultConfigFactory sets correct MIDI defaults")
{
    raindrops::ApplicationConfig config = raindrops::DefaultConfigFactory::create();

    CHECK( config.midiConfig.port == 0 );
    CHECK( config.midiConfig.channel == 0 );
    CHECK( config.midiConfig.autoDetect == true );
}

TEST_CASE("DefaultConfigFactory sets correct window defaults")
{
    raindrops::ApplicationConfig config = raindrops::DefaultConfigFactory::create();

    CHECK( config.windowConfig.width == 1280 );
    CHECK( config.windowConfig.height == 720 );
    CHECK( config.windowConfig.fullscreen == false );
    CHECK( config.windowConfig.vsync == true );
    CHECK( config.windowConfig.resizable == true );
}

TEST_CASE("DefaultConfigFactory sets correct display defaults")
{
    raindrops::ApplicationConfig config = raindrops::DefaultConfigFactory::create();

    CHECK( config.musicSheetDisplayConfig.noteWidth == 40.0f );
    CHECK( config.musicSheetDisplayConfig.measureWidth == 150.0f );
    CHECK( config.musicSheetDisplayConfig.staffSpacing == 30.0f );
    CHECK( config.musicSheetDisplayConfig.fontSize == 16 );
}

TEST_CASE("DefaultConfigFactory returns a new instance each time")
{
    raindrops::ApplicationConfig config1 = raindrops::DefaultConfigFactory::create();
    raindrops::ApplicationConfig config2 = raindrops::DefaultConfigFactory::create();

    // Should be different objects with the same defaults.
    CHECK( config1.midiConfig.port == config2.midiConfig.port );
    CHECK( &config1 != &config2 );
}

TEST_SUITE_END;