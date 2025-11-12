#include "StateMachine.hpp"
#include "MainMenuState.hpp"
#include "PlayingState.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("StateMachine");

TEST_CASE("State transitions")
{
    raindrops::StateMachine stateMachine;
    raylib::Window dummyWindow { 640, 480 };
    dummyWindow.SetTargetFPS(1);

    auto mainMenu = raindrops::StateMachine::build<raindrops::MainMenuState>(stateMachine, dummyWindow, true);
    stateMachine.run(std::move(mainMenu));

    // Check initial state
    CHECK( stateMachine.running() == true );
    CHECK( stateMachine.getCurrentStateName() == "MainMenuState" );

    // Check transition to playing state
    auto playingState = raindrops::StateMachine::build<raindrops::PlayingState>(stateMachine, dummyWindow, true);
    stateMachine.run(std::move(playingState));
    CHECK( stateMachine.getCurrentStateName() == "PlayingState" );

    // Check going "back" a state
    stateMachine.lastState(); // Flag for pop
    stateMachine.nextState(); // Pop and run whatever state is currently at the top
    CHECK( stateMachine.getCurrentStateName() == "MainMenuState" );
}

TEST_CASE("State management")
{
    raindrops::StateMachine stateMachine;
    raylib::Window dummyWindow { 640, 480 };

    auto mainMenu = raindrops::StateMachine::build<raindrops::MainMenuState>(stateMachine, dummyWindow, true);
    stateMachine.run(std::move(mainMenu));

    stateMachine.quit();
    CHECK( stateMachine.running() == false );
}

TEST_SUITE_END();