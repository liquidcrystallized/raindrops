#include "MusicSheet.hpp"
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

TEST_SUITE_END();