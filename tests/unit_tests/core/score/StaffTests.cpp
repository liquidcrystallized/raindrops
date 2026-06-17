#include "Staff.hpp"
#include "StaffLine.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("Staff");

TEST_CASE("Staff constructor creates correct number of lines")
{
    raindrops::Staff staff {};

    CHECK( staff.getNumberOfLines() == 16 );
}

TEST_CASE("Staff constructor visible treble and bass clefs")
{
    raindrops::Staff staff {};
    const std::vector<raindrops::StaffLine>& lines = staff.getLines();

    SUBCASE("Treble clef")
    {
        for (int i = 0; i < 5; i++)
        {
            CHECK( lines[i].isVisible() == true );
        }
    }
    SUBCASE("Bass clef")
    {
        for (int i = 11; i < lines.size(); i++)
        {
            CHECK( lines[i].isVisible() == true );
        }
    }
}

TEST_CASE("Staff constructor lines between clefs should be invisible")
{
    raindrops::Staff staff {};
    const std::vector<raindrops::StaffLine>& lines = staff.getLines();

    for (int i = 5; i < 11; i++)
    {
        CHECK( lines[i].isVisible() == false );
    }
}

TEST_SUITE_END;