#include "MusicSheetDisplayConfig.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("MusicSheetDisplayConfig");

TEST_CASE("MusicSheetDisplayConfig default values")
{
    raindrops::MusicSheetDisplayConfig config {};

    CHECK( config.noteWidth == 40.0f );
    CHECK( config.measureWidth == 150.0f );
    CHECK( config.staffSpacing == 30.0f );
    CHECK( config.fontSize == 16 );
}

TEST_CASE("MusicSheetDisplayConfig can be modified")
{
    raindrops::MusicSheetDisplayConfig config {};

    SUBCASE("Set custom note width")
    {
        config.noteWidth = 50.0f;
        CHECK( config.noteWidth == 50.0f );
    }
    SUBCASE("Set custom measure width")
    {
        config.measureWidth = 200.0f;
        CHECK( config.measureWidth == 200.0f );
    }
    SUBCASE("Set custom spacing")
    {
        config.staffSpacing = 40.0f;
        CHECK( config.staffSpacing == 40.0f );
    }
    SUBCASE("Set custom font size")
    {
        config.fontSize = 20;
        CHECK( config.fontSize == 20);
    }
}

TEST_CASE("MusicSheetDisplayConfig validation")
{
    raindrops::MusicSheetDisplayConfig config {};

    SUBCASE("Valid default config")
    {
        CHECK( config.isValid() == true );
    }
    SUBCASE("Valid custom values")
    {
        config.noteWidth = 35.0f;
        config.measureWidth = 125.0f;
        config.staffSpacing = 25.0f;
        config.fontSize = 10;

        CHECK( config.isValid() == true );
    }
    SUBCASE("Invalid noteWith - zero")
    {
        config.noteWidth = 0.0f;
        CHECK( config.isValid() == false );
    }
    SUBCASE("Invalid noteWidth - negative")
    {
        config.noteWidth = -5.0f;
        CHECK( config.isValid() == false );
    }
    SUBCASE("Invalid staffSpacing - zero")
    {
        config.staffSpacing = 0.0f;
        CHECK( config.isValid() == false );
    }
    SUBCASE("Invalid staffSpacing - negative")
    {
        config.staffSpacing = -10.0f;
        CHECK( config.isValid() == false );
    }
    SUBCASE("Invalid measureWidth - zero")
    {
        config.measureWidth = 0.0f;
        CHECK( config.isValid() == false );
    }
    SUBCASE("Invalid measureWidth - negative")
    {
        config.measureWidth = -20.0f;
        CHECK( config.isValid() == false );
    }
}

TEST_SUITE_END;