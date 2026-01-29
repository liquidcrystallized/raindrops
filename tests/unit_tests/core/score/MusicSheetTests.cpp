#include "MusicSheet.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("MusicSheet");

TEST_CASE("Music sheet xml filepath")
{
    raindrops::MusicSheet sheet;

    const std::string filePath { "some/path/to/a/musicxml" };
    sheet.setFilePath(filePath);

    CHECK( sheet.getFilePath() == filePath );
}

TEST_CASE("Music sheet title")
{
    raindrops::MusicSheet sheet;

    const std::string workTitle { "夜の向日葵" };
    sheet.setTitle(workTitle);

    CHECK( sheet.getTitle() == workTitle );
}

TEST_CASE("Music sheet subtitle")
{
    raindrops::MusicSheet sheet;

    const std::string subtitle { "subtitle" };
    sheet.setSubTitle(subtitle);

    CHECK ( sheet.getSubTitle() == subtitle );
}

TEST_CASE("Music sheet composer")
{
    raindrops::MusicSheet sheet;

    const std::string composer { "松本 文紀 (szak)" };
    sheet.setComposer(composer);

    CHECK( sheet.getComposer() == composer );
}

TEST_CASE("Music sheet has BPM info default initialisation false")
{
    raindrops::MusicSheet sheet;
    CHECK( sheet.getHasBPMInfo() == false );
}

TEST_CASE("Music sheet has BPM info")
{
    raindrops::MusicSheet sheet;

    bool hasBPMInfo { true };
    sheet.setHasBPMInfo(hasBPMInfo);

    CHECK( sheet.getHasBPMInfo() == hasBPMInfo );
}

TEST_SUITE_END();