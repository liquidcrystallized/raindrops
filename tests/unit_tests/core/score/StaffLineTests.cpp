#include "StaffLine.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("StaffLine");

TEST_CASE("StaffLine default position Y is set correctly")
{
    raindrops::StaffLine line { 42, true };

    CHECK( line.getPositionY() == 42 );
}

TEST_CASE("StaffLine setPositionY updates the Y position")
{
    raindrops::StaffLine line { 10, true };
    line.setPositionY(20);

    CHECK( line.getPositionY() == 20 );
}

TEST_CASE("StaffLine setPositionY can set negative values")
{
    raindrops::StaffLine line { 0, true};
    line.setPositionY(-100);

    CHECK( line.getPositionY() == -100 );
}

TEST_CASE("StaffLine setPositionY can be zeroed")
{
    raindrops::StaffLine line { 50, true };
    line.setPositionY(0);

    CHECK( line.getPositionY() == 0 );
}

TEST_SUITE_END;