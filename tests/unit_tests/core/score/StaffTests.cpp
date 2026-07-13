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

TEST_CASE("Staff can edit internally stored staff lines")
{
    raindrops::Staff staff {};
    staff.getLine(0).setPositionY(100);

    CHECK( staff.getLine(0).getPositionY() == 100 );
}

TEST_CASE("Staff can edit internally stored lines multi case")
{
    raindrops::Staff staff {};

    for (int i = 0; i < staff.getNumberOfLines(); i++)
    {
        staff.getLine(i).setPositionY(i * 2);
    }

    CHECK( staff.getLine(4).getPositionY() == 8 );
    CHECK( staff.getLine(8).getPositionY() == 16 );
}

TEST_CASE("Staff can edit internally stored lines multi case + reference works")
{
    raindrops::Staff staff {};

    int someVal { 0 };
    for (raindrops::StaffLine& staffLine : staff.getLines())
    {
        staffLine.setPositionY(someVal * 2);
        someVal++;
    }

    CHECK( staff.getLine(4).getPositionY() == 8 );
    CHECK( staff.getLine(8).getPositionY() == 16 );
}

TEST_SUITE_END;