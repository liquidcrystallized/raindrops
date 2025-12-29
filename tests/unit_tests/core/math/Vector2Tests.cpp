#include "core/math/Vector2.hpp"
#include <doctest.h>
#include <cmath>
#include <limits>
#include <stdexcept>

TEST_SUITE_BEGIN("Vector2");

TEST_CASE("Vector2 correctly initialised")
{
    SUBCASE("Positive integers")
    {
        raindrops::Vector2<int> vector2 { 1, 2 };
        CHECK( vector2.getX() == 1);
        CHECK( vector2.getY() == 2 );
    }
    SUBCASE("Zero values")
    {
        raindrops::Vector2<int> vector2 { 0, 0 };
        CHECK( vector2.getX() == 0 );
        CHECK( vector2.getY() == 0 );
    }
    SUBCASE("Negative integers")
    {
        raindrops::Vector2<int> vector2 { -1, -3 };
        CHECK( vector2.getX() == -1 );
        CHECK( vector2.getY() == -3 );
    }
    SUBCASE("Maximum integer values")
    {
        raindrops::Vector2<int> maxVector { std::numeric_limits<int>::max(), std::numeric_limits<int>::max() };
        CHECK( maxVector.getX() == std::numeric_limits<int>::max() );
        CHECK( maxVector.getY() == std::numeric_limits<int>::max() );
    }
    SUBCASE("Minimum integer values")
    {
        raindrops::Vector2<int> minVector { std::numeric_limits<int>::min(), std::numeric_limits<int>::min() };
        CHECK( minVector.getX() == std::numeric_limits<int>::min() );
        CHECK( minVector.getY() == std::numeric_limits<int>::min() );
    }
    SUBCASE("Float initialisation")
    {
        raindrops::Vector2<float> vector2 { 1.5f, 2.5f };
        CHECK( vector2.getX() == 1.5f );
        CHECK( vector2.getY() == 2.5f );
    }
    SUBCASE("Double initialisation")
    {
        raindrops::Vector2<double> vector2 { 1.5, 2.5 };
        CHECK( vector2.getX() == 1.5 );
        CHECK( vector2.getY() == 2.5 );
    }
}

TEST_CASE("Vector2 values correctly set")
{
    SUBCASE("Int")
    {
        raindrops::Vector2<int> vector2 { 1, 2 };
        vector2.setX(10);
        vector2.setY(20);
        CHECK( vector2.getX() == 10 );
        CHECK( vector2.getY() == 20 );
    }
    SUBCASE("Float")
    {
        raindrops::Vector2<float> vector2 { 1.5f, 2.5f };
        vector2.setX(3.5f);
        vector2.setY(-4.5f);
        CHECK( vector2.getX() == 3.5f );
        CHECK( vector2.getY() == -4.5f );
    }
}

TEST_CASE("Type conversion and concept enforcement")
{
    // Should compile
    raindrops::Vector2<int> intVector { 1, 2 };
    raindrops::Vector2<float> floatVector { 1.0f, 2.0f };

    // Should not compile, but eh.
    //raindrops::Vector2<bool> boolVector;
    //raindrops::Vector2<char> charVector;
}

TEST_SUITE_END();