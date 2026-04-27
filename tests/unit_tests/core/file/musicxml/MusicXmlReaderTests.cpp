#include "MusicXmlReader.hpp"
#include "MxReader.hpp"
#include "TestInputFiles.hpp"
#include <doctest.h>
#include <sstream>
#include <string>

TEST_SUITE_BEGIN("MusicXmlReader");

TEST_CASE("MusicXmlReader::tryParseFileInputStream - Are contents musicxml")
{
    raindrops::MxReader mx {};
    raindrops::MusicXmlReader musicXmlReader { mx };

    SUBCASE("Should be true - file contents are musicxml")
    {
        musicXmlReader.tryLoadFileIntoStream(TestInputFiles::helloWorldFilePath);
        std::istringstream ss { musicXmlReader.getRawFileContents() };
        bool contentsAreMusicXml = musicXmlReader.tryParseFileInputStream(ss);

        CHECK( contentsAreMusicXml == true );
    }
    SUBCASE("Should be false - file contents are not musicxml")
    {
        musicXmlReader.tryLoadFileIntoStream(TestInputFiles::nonMusicXmlFilePath);
        std::istringstream ss { musicXmlReader.getRawFileContents() };
        bool contentsAreMusicXml = musicXmlReader.tryParseFileInputStream(ss);

        CHECK( contentsAreMusicXml == false );
    }
}

TEST_CASE("MusicXmlReader::getMusicXmlVersion")
{
    raindrops::MxReader mx {};
    raindrops::MusicXmlReader musicXmlReader { mx };

    musicXmlReader.tryLoadFileIntoStream(TestInputFiles::helloWorldFilePath);
    std::istringstream ss { musicXmlReader.getRawFileContents() };
    musicXmlReader.tryParseFileInputStream(ss);

    CHECK( musicXmlReader.getMusicXmlVersion() == "3.1" );
}

TEST_CASE("MusicXmlReader::getNumberOfMeasures")
{
    raindrops::MxReader mx {};
    raindrops::MusicXmlReader musicXmlReader { mx };

    musicXmlReader.tryLoadFileIntoStream(TestInputFiles::pitchesPitchesFilePath);
    std::istringstream ss { musicXmlReader.getRawFileContents() };
    musicXmlReader.tryParseFileInputStream(ss);

    CHECK( musicXmlReader.getNumberOfMeasures() == 27 );
}

TEST_CASE("MusicXmlReader::getNumberOfParts")
{
    raindrops::MxReader mx {};
    raindrops::MusicXmlReader musicXmlReader { mx };

    SUBCASE("There is 1 part")
    {
        musicXmlReader.tryLoadFileIntoStream(TestInputFiles::helloWorldFilePath);
        std::istringstream ss { musicXmlReader.getRawFileContents() };
        musicXmlReader.tryParseFileInputStream(ss);

        CHECK( musicXmlReader.getNumberOfParts() == 1 );
    }
    SUBCASE("There are 2 parts")
    {
        //TODO
    }
}

TEST_SUITE_END();