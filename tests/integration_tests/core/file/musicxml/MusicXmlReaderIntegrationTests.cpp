#include "MusicSheet.hpp"
#include "MusicXmlReader.hpp"
#include "MxReader.hpp"
#include "ScoreFactory.hpp"
#include "TestInputFiles.hpp"
#include <doctest.h>
#include <sstream>

TEST_SUITE_BEGIN("MusicXmlReader Integration");

TEST_CASE("Load measures from MusicXML into an empty MusicSheet")
{
    raindrops::MxReader mx {};
    raindrops::MusicXmlReader musicXmlReader { mx };

    if (musicXmlReader.tryLoadFileIntoStream(TestInputFiles::pitchesPitchesFilePath))
    {
        std::istringstream inputStream { musicXmlReader.getRawFileContents() };

        if (musicXmlReader.tryParseFileInputStream(inputStream))
        {
            std::unique_ptr<raindrops::MusicSheet> musicSheet = raindrops::ScoreFactory::createFromReader(musicXmlReader);

            CHECK( musicSheet->getMeasureCount() == musicXmlReader.getNumberOfMeasures() );
        }
    }
}

TEST_SUITE_END;