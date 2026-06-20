#include "WindowConfig.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("WindowConfig");

TEST_CASE("WindowConfig default value")
{
    raindrops::WindowConfig config;

    CHECK( config.width == 1280 );
    CHECK( config.height == 720 );
    CHECK( config.fullscreen == false );
    CHECK( config.vsync == true );
    CHECK( config.resizable == true );
}

TEST_CASE("WindowConfig can be modified")
{
    raindrops::WindowConfig config;

    SUBCASE("Set custom width and height")
    {
        config.width = 1920;
        config.height = 1080;

        CHECK( config.width == 1920 );
        CHECK( config.height == 1080 );
    }
    SUBCASE("Enable fullscreen")
    {
        config.fullscreen = true;
        CHECK( config.fullscreen == true );
    }
    SUBCASE("Disable vsync")
    {
        config.vsync = false;
        CHECK( config.vsync == false );
    }
    SUBCASE("Disable resize")
    {
        config.resizable = false;
        CHECK( config.resizable == false );
    }
    SUBCASE("Set all values")
    {
        config.width = 3840;
        config.height = 2160;
        config.fullscreen = true;
        config.vsync = false;
        config.resizable = false;

        CHECK( config.width == 3840 );
        CHECK( config.height == 2160 );
        CHECK( config.fullscreen == true );
        CHECK( config.vsync == false );
        CHECK( config.resizable == false );
    }
}

TEST_CASE("WindowConfig validation")
{
    raindrops::WindowConfig config;

    SUBCASE("Valid default config")
    {
        CHECK( config.isValid() == true );
    }
    SUBCASE("Valid custom resolution")
    {
        config.width = 1920;
        config.height = 1080;

        CHECK( config.isValid() == true );
    }
    SUBCASE("Invalid width - zero")
    {
        config.width = 0;
        CHECK( config.isValid() == false );
    }
    SUBCASE("Invalid width - negative")
    {
        config.width = -100;
        CHECK( config.isValid() == false );
    }
    SUBCASE("Invalid height - zero")
    {
        config.height = 0;
        CHECK( config.isValid() == false );
    }
    SUBCASE("Invalid height - negative")
    {
        config.height = -100;
        CHECK( config.isValid() == false );
    }
}

TEST_SUITE_END;