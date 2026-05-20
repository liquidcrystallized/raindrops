#include "Staff.hpp"
#include "StaffLine.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("Staff");

TEST_CASE("Staff constructor creates correct number of lines")
{
    raindrops::Staff staff { 0, 10, 5 };

    CHECK( staff.getNumberOfLines() == 5 );
}

TEST_CASE("Staff constructor creates lines with correct spacing")
{
    raindrops::Staff staff { 100, 10, 5 };
    const std::vector<raindrops::StaffLine>& lines = staff.getLines();

    CHECK( lines[0].getPositionY() == 100 );
    CHECK( lines[1].getPositionY() == 110 );
    CHECK( lines[2].getPositionY() == 120 );
    CHECK( lines[3].getPositionY() == 130 );
    CHECK( lines[4].getPositionY() == 140 );
}

TEST_CASE("Staff with non-standard number of lines")
{
    raindrops::Staff staff { 0, 5, 3 };
    const std::vector<raindrops::StaffLine>& lines = staff.getLines();

    CHECK( lines.size() == 3 );
    CHECK( lines[0].getPositionY() == 0 );
    CHECK( lines[1].getPositionY() == 5 );
    CHECK( lines[2].getPositionY() == 10 );
}

TEST_CASE("Staff with zero lines")
{
    raindrops::Staff staff { 0, 10, 0 };
    const std::vector<raindrops::StaffLine>& lines = staff.getLines();

    CHECK( lines.empty() );
}

TEST_SUITE_END;