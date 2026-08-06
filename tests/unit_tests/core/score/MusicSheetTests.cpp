#include "MusicSheet.hpp"
#include "Measure.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("MusicSheet");

TEST_CASE("Music sheet default constructor")
{
    raindrops::MusicSheet sheet;

    CHECK( sheet.getMeasureCount() == 0 );
    CHECK( sheet.getHasBPMInfo() == false );
    CHECK( sheet.getTitle().empty() );
    CHECK( sheet.getComposer().empty() );
}

TEST_CASE("Music sheet xml filepath")
{
    raindrops::MusicSheet sheet;

    const std::string filePath { "some/path/to/a/musicxml" };
    sheet.setFilePath(filePath);

    CHECK( sheet.getFilePath() == filePath );
}

TEST_CASE("Music sheet title get/set")
{
    raindrops::MusicSheet sheet;

    const std::string workTitle { "夜の向日葵" };
    sheet.setTitle(workTitle);

    CHECK( sheet.getTitle() == workTitle );
}

TEST_CASE("Music sheet subtitle get/set")
{
    raindrops::MusicSheet sheet;

    const std::string subtitle { "subtitle" };
    sheet.setSubTitle(subtitle);

    CHECK ( sheet.getSubTitle() == subtitle );
}

TEST_CASE("Music sheet composer get/set")
{
    raindrops::MusicSheet sheet;

    const std::string composer { "松本 文紀 (szak)" };
    sheet.setComposer(composer);

    CHECK( sheet.getComposer() == composer );
}

TEST_CASE("Music sheet has BPM info get/set")
{
    raindrops::MusicSheet sheet;

    bool hasBPMInfo { true };
    sheet.setHasBPMInfo(hasBPMInfo);

    CHECK( sheet.getHasBPMInfo() == hasBPMInfo );
}

TEST_CASE("Music sheet add measures")
{
    raindrops::MusicSheet sheet;

    raindrops::Measure measure1;
    measure1.setMeasureNumber(1);

    raindrops::Measure measure2;
    measure2.setMeasureNumber(2);

    sheet.addMeasure(measure1);
    sheet.addMeasure(measure2);

    CHECK( sheet.getMeasureCount() == 2 );
}

TEST_CASE("Music sheet file path get/set")
{
    raindrops::MusicSheet sheet;

    const std::string expectedPath = "/path/to/song.musicxml";
    sheet.setFilePath(expectedPath);

    CHECK( sheet.getFilePath() == expectedPath );
}

TEST_CASE("Music sheet BPM info flag toggle")
{
    raindrops::MusicSheet sheet;

    CHECK( sheet.getHasBPMInfo() == false );

    sheet.setHasBPMInfo(true);

    CHECK( sheet.getHasBPMInfo() == true );
}

TEST_CASE("Music sheet measure retrieval by count")
{
    raindrops::MusicSheet sheet;

    for (int i = 0; i < 5; i++)
    {
        raindrops::Measure measure;
        measure.setMeasureNumber(i+1);
        sheet.addMeasure(measure);
    }

    const std::vector<raindrops::Measure>& measures = sheet.getMeasures();

    CHECK( measures.size() == 5 );
    CHECK( measures[0].getMeasureNumber() == 1 );
    CHECK( measures[4].getMeasureNumber() == 5 );
}

TEST_CASE("Music sheet set vector of measures")
{
    raindrops::MusicSheet sheet;
    std::vector<raindrops::Measure> measures {};

    raindrops::Measure measure1 {};
    measure1.setMeasureNumber(1);

    raindrops::Measure measure2 {};
    measure2.setMeasureNumber(2);

    measures.push_back(measure1);
    measures.push_back(measure2);
    sheet.setMeasures(measures);

    CHECK( sheet.getMeasureCount() == 2 );
}

TEST_SUITE_END();