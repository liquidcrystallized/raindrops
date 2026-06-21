#include "ApplicationConfig.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("ApplicationConfig");

TEST_CASE("ApplicationConfig default values")
{
    raindrops::ApplicationConfig config {};

    // Brief check, no need to do full thing.
    CHECK( config.midiConfig.port == 0 );
    CHECK( config.musicSheetDisplayConfig.staffSpacing == 30.0f );
    CHECK( config.windowConfig.height == 720 );

    // Metadata defaults.
    CHECK( config.appName == "Raindrops" );
    CHECK( config.appVersion == "0.1.0" );
}

TEST_CASE("ApplicationConfig can be modified")
{
    raindrops::ApplicationConfig config {};

    config.midiConfig.channel = 10;
    config.musicSheetDisplayConfig.noteWidth = 20.0f;
    config.windowConfig.width = 1920;

    CHECK( config.midiConfig.channel == 10 );
    CHECK( config.musicSheetDisplayConfig.noteWidth == 20.0f );
    CHECK( config.windowConfig.width == 1920 );
}

TEST_CASE("ApplicationConfig validation")
{
    raindrops::ApplicationConfig config {};

    SUBCASE("Valid default config")
    {
        CHECK( config.isValid() == true );
    }
    SUBCASE("Invalid if MIDI config is invalid")
    {
        config.midiConfig.port = 200;
        CHECK( config.isValid() == false );
    }
    SUBCASE("Invalid if music sheet display config is invalid")
    {
        config.musicSheetDisplayConfig.staffSpacing = - 1.0f;
        CHECK( config.isValid() == false );
    }
    SUBCASE("Invalid if window config is invalid")
    {
        config.windowConfig.width = 0;
        CHECK( config.isValid() == false );
    }
}

TEST_CASE("ApplicationConfig copy")
{
    raindrops::ApplicationConfig original {};
    original.midiConfig.port = 2;
    original.windowConfig.width = 1024;

    raindrops::ApplicationConfig copied = original;

    CHECK( copied.midiConfig.port == 2 );
    CHECK( copied.windowConfig.width == 1024 );
}

TEST_SUITE_END;