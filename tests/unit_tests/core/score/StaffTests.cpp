#include "Staff.hpp"
#include "StaffLine.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("Staff");

TEST_CASE("Staff constructor creates correct number of lines")
{
    raindrops::Staff staff { 0, 10 };

    CHECK( staff.getNumberOfLines() == 16 );
}

TEST_CASE("Staff constructor creates lines with correct spacing")
{
    raindrops::Staff staff { 100, 10 };
    const std::vector<raindrops::StaffLine>& lines = staff.getLines();

    CHECK( lines[0].getPositionY() == 100 );
    CHECK( lines[1].getPositionY() == 110 );
    CHECK( lines[2].getPositionY() == 120 );
    CHECK( lines[3].getPositionY() == 130 );
    CHECK( lines[4].getPositionY() == 140 );
}

TEST_CASE("Staff constructor visible treble and bass clefs")
{
    raindrops::Staff staff { 0, 10 };
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

TEST_SUITE_END;