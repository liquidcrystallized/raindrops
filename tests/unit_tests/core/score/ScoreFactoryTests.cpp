#include "MxReader.hpp"
#include "MusicXmlReader.hpp"
#include "MusicSheet.hpp"
#include "ScoreFactory.hpp"
#include "TestInputFiles.hpp"
#include <doctest.h>
#include <sstream>

TEST_SUITE_BEGIN("ScoreFactory");

TEST_CASE("ScoreFactory::createFromReader creates valid MusicSheet")
{
    raindrops::MxReader mx {};
    raindrops::MusicXmlReader musicXmlReader { mx };

    musicXmlReader.tryLoadFileIntoStream(TestInputFiles::clairDeLuneFilePath);
    std::istringstream inputStream { musicXmlReader.getRawFileContents() };
    musicXmlReader.tryParseFileInputStream(inputStream);

    auto musicSheet = raindrops::ScoreFactory::createFromReader(musicXmlReader);

    CHECK( musicSheet != nullptr );
    CHECK( !musicSheet->getTitle().empty() );
    CHECK( !musicSheet->getComposer().empty() );
}

TEST_CASE("ScoreFactory sets correct title from MusicXML")
{
    raindrops::MxReader mx {};
    raindrops::MusicXmlReader musicXmlReader { mx };

    musicXmlReader.tryLoadFileIntoStream(TestInputFiles::clairDeLuneFilePath);
    std::istringstream inputStream { musicXmlReader.getRawFileContents() };
    musicXmlReader.tryParseFileInputStream(inputStream);

    auto musicSheet = raindrops::ScoreFactory::createFromReader(musicXmlReader);

    CHECK( musicSheet->getTitle() == musicXmlReader.getSongTitle() );
}

TEST_CASE("ScoreFactory sets correct composer from MusicXML")
{
    raindrops::MxReader mx {};
    raindrops::MusicXmlReader musicXmlReader { mx };

    musicXmlReader.tryLoadFileIntoStream(TestInputFiles::clairDeLuneFilePath);
    std::istringstream inputStream { musicXmlReader.getRawFileContents() };
    musicXmlReader.tryParseFileInputStream(inputStream);

    auto musicSheet = raindrops::ScoreFactory::createFromReader(musicXmlReader);

    CHECK( musicSheet->getComposer() == musicXmlReader.getSongComposer() );
}

TEST_CASE("ScoreFactory creates correct number of measures")
{
    raindrops::MxReader mx {};
    raindrops::MusicXmlReader musicXmlReader { mx };

    musicXmlReader.tryLoadFileIntoStream(TestInputFiles::clairDeLuneFilePath);
    std::istringstream inputStream { musicXmlReader.getRawFileContents() };
    musicXmlReader.tryParseFileInputStream(inputStream);

    auto musicSheet = raindrops::ScoreFactory::createFromReader(musicXmlReader);

    CHECK( musicSheet->getMeasureCount() == musicXmlReader.getNumberOfMeasures() );
}

TEST_CASE("ScoreFactory measures have sequential numbers")
{
    raindrops::MxReader mx {};
    raindrops::MusicXmlReader musicXmlReader { mx };

    musicXmlReader.tryLoadFileIntoStream(TestInputFiles::clairDeLuneFilePath);
    std::istringstream inputStream { musicXmlReader.getRawFileContents() };
    musicXmlReader.tryParseFileInputStream(inputStream);

    auto musicSheet = raindrops::ScoreFactory::createFromReader(musicXmlReader);

    const auto& measures = musicSheet->getMeasures();
    for (int i = 0; i < measures.size(); i++)
    {
        CHECK( measures[i].getMeasureNumber() == i + 1 );
    }
}

TEST_CASE("ScoreFactory handles empty measure count")
{
    raindrops::MxReader mx {};
    raindrops::MusicXmlReader musicXmlReader { mx };

    musicXmlReader.tryLoadFileIntoStream(TestInputFiles::noMeasuresXmlFilePath);
    std::istringstream inputStream { musicXmlReader.getRawFileContents() };
    musicXmlReader.tryParseFileInputStream(inputStream);

    auto musicSheet = raindrops::ScoreFactory::createFromReader(musicXmlReader);

    CHECK( musicSheet != nullptr );
    CHECK( musicSheet->getMeasureCount() == 0 );
}

TEST_SUITE_END;