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

TEST_CASE("MusicXmlReader::getMeasures")
{
    raindrops::MxReader mx {};
    raindrops::MusicXmlReader musicXmlReader { mx };

    musicXmlReader.tryLoadFileIntoStream(TestInputFiles::clairDeLuneFilePath);
    std::istringstream ss { musicXmlReader.getRawFileContents() };
    musicXmlReader.tryParseFileInputStream(ss);

    CHECK( musicXmlReader.getMeasures().size() == 72 );
}

TEST_CASE("MusicXmlReader::getMeasures - No piano part - Should return empty measures")
{
    raindrops::MxReader mx {};
    raindrops::MusicXmlReader musicXmlReader { mx };

    musicXmlReader.tryLoadFileIntoStream(TestInputFiles::pitchesPitchesFilePath);
    std::istringstream ss { musicXmlReader.getRawFileContents() };

    musicXmlReader.tryParseFileInputStream(ss);
    CHECK( musicXmlReader.getMeasures().empty() );
}

TEST_CASE("MusicXmlReader::getMeasures - No measures - Should return empty measures")
{
    raindrops::MxReader mx {};
    raindrops::MusicXmlReader musicXmlReader { mx };

    musicXmlReader.tryLoadFileIntoStream(TestInputFiles::noMeasuresXmlFilePath);
    std::istringstream ss { musicXmlReader.getRawFileContents() };

    musicXmlReader.tryParseFileInputStream(ss);
    CHECK( musicXmlReader.getMeasures().empty() );
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

// This is just for stepping through with a debugger to see how mx works, and what the functions return.
// Based on the "Reading MusicXML with mx::api" example found here: https://github.com/webern/mx
TEST_CASE("Reading MusicXML with mx::api")
{
    auto& manager = mx::api::DocumentManager::getInstance();
    const auto idResult = manager.createFromFile( TestInputFiles::clairDeLuneFilePath );
    const auto scoreResult = manager.getData(idResult);
    manager.destroyDocument(idResult);

    const auto& score = scoreResult;

    CHECK( score.parts.size() > 0 );

    // Drill down into the data structure to retrieve a note.
    const auto& part = score.parts.at( 0 );
    const auto& measure = part.measures.at( 0 );
    const auto& staff = measure.staves.at( 0 );
    const auto& voice = staff.voices.at( 0 );
    const auto& note = voice.notes.at( 0 );

    CHECK( true );
}

TEST_SUITE_END();