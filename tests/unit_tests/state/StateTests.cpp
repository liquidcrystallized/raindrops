#include "MainMenuState.hpp"
#include "StateMachine.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("State");

TEST_CASE("Default State/Screen window centre is correct")
{
    raindrops::StateMachine stateMachine;
    raylib::Window dummyWindow { 640, 480 };
    dummyWindow.SetTargetFPS(1);

    auto mainMenu = raindrops::StateMachine::build<raindrops::MainMenuState>(stateMachine, dummyWindow, true);
    stateMachine.run(std::move(mainMenu));

    raylib::Vector2 expectedDummyWindowCentre { 640 / 2.0f, 480 / 2.0f };

    CHECK( expectedDummyWindowCentre.GetX() == stateMachine.getCurrentState()->getWindowCentrePosition().GetX() );
    CHECK( expectedDummyWindowCentre.GetY() == stateMachine.getCurrentState()->getWindowCentrePosition().GetY() );
}

TEST_CASE("Arbitrary setting of new centre")
{
    raindrops::StateMachine stateMachine;
    raylib::Window dummyWindow { 640, 480 };
    dummyWindow.SetTargetFPS(1);

    auto mainMenu = raindrops::StateMachine::build<raindrops::MainMenuState>(stateMachine, dummyWindow, true);
    stateMachine.run(std::move(mainMenu));

    float centreX { 500 };
    float centreY { 600 };
    stateMachine.getCurrentState()->setWindowCentrePosition(centreX, centreY);

    CHECK( centreX == stateMachine.getCurrentState()->getWindowCentrePosition().GetX() );
    CHECK( centreY == stateMachine.getCurrentState()->getWindowCentrePosition().GetY() );
}

TEST_SUITE_END();