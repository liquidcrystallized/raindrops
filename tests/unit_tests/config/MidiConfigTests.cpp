#include "MidiConfig.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("MidiConfig");

TEST_CASE("MidiConfig default values")
{
    raindrops::MidiConfig config {};

    CHECK( config.port == 0 );
    CHECK( config.channel == 0 );
    CHECK( config.autoDetect == true );
}

TEST_CASE("MidiConfig can be modified")
{
    raindrops::MidiConfig config {};

    SUBCASE("Set specific MIDI port")
    {
        config.port = 5;
        CHECK( config.port == 5 );
    }
    SUBCASE("Set specific MIDI channel")
    {
        config.channel = 10;
        CHECK( config.channel == 10);
    }
    SUBCASE("Set auto-detect")
    {
        config.autoDetect = false;
        CHECK( config.autoDetect == false );
    }
    SUBCASE("Set all values")
    {
        config.port = 6;
        config.channel = 7;
        config.autoDetect = false;

        CHECK( config.port == 6 );
        CHECK( config.channel == 7 );
        CHECK( config.autoDetect == false );
    }
}

TEST_CASE("MidiConfig validation")
{
    raindrops::MidiConfig config {};

    SUBCASE("Valid default config")
    {
        CHECK( config.isValid() == true );
    }
    SUBCASE("Valid specific port and channel")
    {
        SUBCASE("Arbitrary values")
        {
            config.port = 1;
            config.channel = 5;
            CHECK( config.isValid() == true );
        }
        SUBCASE("At bounds")
        {
            SUBCASE("Upper")
            {
                config.port = 128;
                config.channel = 16;
                CHECK( config.isValid() == true );
            }
            SUBCASE("Lower")
            {
                config.port = 0;
                config.channel = 0;
                CHECK( config.isValid() == true );
            }
        }
    }
    SUBCASE("Invalid port")
    {
        SUBCASE("Too high")
        {
            config.port = 129;
            CHECK( config.isValid() == false );
        }
        SUBCASE("Below 0")
        {
            config.port = -1;
            CHECK( config.isValid() == false );
        }
    }
    SUBCASE("Invalid channel")
    {
        SUBCASE("Too high")
        {
            config.channel = 17;
            CHECK( config.isValid() == false );
        }
        SUBCASE("Below 0")
        {
            config.channel = -1;
            CHECK( config.isValid() == false );
        }
    }
}

TEST_SUITE_END;