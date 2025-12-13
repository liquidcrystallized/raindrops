#include "core/math/Vector2.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("Vector2");

TEST_CASE("Vector2 correctly initialised")
{
    raindrops::Vector2 vector2 { 1, 2 };

    int expectedX = 1;
    int expectedY = 2;

    CHECK( expectedX == vector2.getX() );
    CHECK( expectedY == vector2.getY() );
}

TEST_CASE("Vector2 values correctly set")
{
    raindrops::Vector2 vector2 { 1, 2 };
    vector2.setX(10);
    vector2.setY(20);

    int expectedX = 10;
    int expectedY = 20;

    CHECK( expectedX == vector2.getX() );
    CHECK( expectedY == vector2.getY() );
}

TEST_SUITE_END();