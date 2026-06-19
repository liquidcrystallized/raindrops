#include "GraphicsNull.hpp"
#include "MainMenuState.hpp"
#include "MidiMonitor.hpp"
#include "StateMachine.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("State");

TEST_CASE("Default State/Screen window centre is correct")
{
    raindrops::StateMachine stateMachine;
    raindrops::GraphicsNull renderer {};
    raindrops::MidiMonitor midiMonitor {};
    renderer.setWindowWidth(640);
    renderer.setWindowHeight(480);

    auto mainMenu = raindrops::StateMachine::build<raindrops::MainMenuState>(stateMachine, renderer, midiMonitor, true);
    stateMachine.run(std::move(mainMenu));

    raylib::Vector2 expectedDummyWindowCentre { 640 / 2.0f, 480 / 2.0f };

    CHECK( expectedDummyWindowCentre.GetX() == stateMachine.getCurrentState()->getWindowCentrePosition().getX() );
    CHECK( expectedDummyWindowCentre.GetY() == stateMachine.getCurrentState()->getWindowCentrePosition().getY() );
}

TEST_CASE("Arbitrary setting of new centre")
{
    raindrops::StateMachine stateMachine;
    raindrops::GraphicsNull renderer {};
    raindrops::MidiMonitor midiMonitor {};
    renderer.setWindowWidth(640);
    renderer.setWindowHeight(480);

    auto mainMenu = raindrops::StateMachine::build<raindrops::MainMenuState>(stateMachine, renderer, midiMonitor, true);
    stateMachine.run(std::move(mainMenu));

    float centreX { 500 };
    float centreY { 600 };
    stateMachine.getCurrentState()->setWindowCentrePosition(centreX, centreY);

    CHECK( centreX == stateMachine.getCurrentState()->getWindowCentrePosition().getX() );
    CHECK( centreY == stateMachine.getCurrentState()->getWindowCentrePosition().getY() );
}

TEST_CASE("State initialization and properties")
{
    raindrops::StateMachine stateMachine;
    raindrops::GraphicsNull renderer {};
    raindrops::MidiMonitor midiMonitor {};
    renderer.setWindowWidth(640);
    renderer.setWindowHeight(480);

    // Test default state properties
    auto mainMenu = raindrops::StateMachine::build<raindrops::MainMenuState>(stateMachine, renderer, midiMonitor, true);
    stateMachine.run(std::move(mainMenu));

    CHECK( stateMachine.getCurrentState()->isReplacing() == true );
    CHECK( stateMachine.getCurrentState()->getName() == "MainMenuState" );
    CHECK( &stateMachine.getCurrentState()->getMidiMonitor() == &midiMonitor );
}


TEST_SUITE_END();