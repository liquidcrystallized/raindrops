#include "GraphicsRaylib.hpp"
#include "StateMachine.hpp"
#include "MainMenuState.hpp"
#include "PlayingState.hpp"
#include "Renderer.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("StateMachine");

TEST_CASE("State transitions")
{
    raindrops::StateMachine stateMachine;
    raindrops::GraphicsRaylib raylib {};
    raindrops::Renderer renderer { raylib };
    raindrops::MidiMonitor midiMonitor {};
    renderer.setWindowWidth(640);
    renderer.setWindowHeight(480);
    renderer.toggleTestMode();

    auto mainMenu = raindrops::StateMachine::build<raindrops::MainMenuState>(stateMachine, renderer, midiMonitor, true);
    stateMachine.run(std::move(mainMenu));

    // Check initial state
    CHECK( stateMachine.running() == true );
    CHECK( stateMachine.getCurrentState()->getName() == "MainMenuState" );

    // Check transition to playing state
    auto playingState = raindrops::StateMachine::build<raindrops::PlayingState>(stateMachine, renderer, midiMonitor, true);
    stateMachine.run(std::move(playingState));
    CHECK( stateMachine.getCurrentState()->getName() == "PlayingState" );

    // Check going "back" a state
    stateMachine.lastState(); // Flag for pop
    stateMachine.nextState(); // Pop and run whatever state is currently at the top
    CHECK( stateMachine.getCurrentState()->getName() == "MainMenuState" );
}

TEST_CASE("State management")
{
    raindrops::StateMachine stateMachine;
    raindrops::GraphicsRaylib raylib {};
    raindrops::Renderer renderer { raylib };
    raindrops::MidiMonitor midiMonitor {};
    renderer.setWindowWidth(640);
    renderer.setWindowHeight(480);
    renderer.toggleTestMode();

    auto mainMenu = raindrops::StateMachine::build<raindrops::MainMenuState>(stateMachine, renderer, midiMonitor, true);
    stateMachine.run(std::move(mainMenu));

    stateMachine.quit();
    CHECK( stateMachine.running() == false );
}

TEST_CASE("State transitions with replacement")
{
    raindrops::StateMachine stateMachine;
    raindrops::GraphicsRaylib raylib {};
    raindrops::Renderer renderer { raylib };
    raindrops::MidiMonitor midiMonitor {};
    renderer.setWindowWidth(640);
    renderer.setWindowHeight(480);
    renderer.toggleTestMode();

    // Test state replacement
    auto mainMenu = raindrops::StateMachine::build<raindrops::MainMenuState>(stateMachine, renderer, midiMonitor, true);
    stateMachine.run(std::move(mainMenu));

    CHECK( stateMachine.getCurrentState()->getName() == "MainMenuState" );

    // Replace with PlayingState
    auto playingState = raindrops::StateMachine::build<raindrops::PlayingState>(stateMachine, renderer, midiMonitor, true);
    stateMachine.run(std::move(playingState));
    CHECK( stateMachine.getCurrentState()->getName() == "PlayingState" );

    // Replace back to MainMenuState
    auto mainMenuAgain = raindrops::StateMachine::build<raindrops::MainMenuState>(stateMachine, renderer, midiMonitor, true);
    stateMachine.run(std::move(mainMenuAgain));
    CHECK( stateMachine.getCurrentState()->getName() == "MainMenuState" );
}

TEST_CASE("State management quit without running")
{
    raindrops::StateMachine stateMachine;
    raylib::Window dummyWindow { 640, 480 };
    raindrops::MidiMonitor midiMonitor {};
    dummyWindow.SetTargetFPS(1);
    dummyWindow.SetConfigFlags(FLAG_WINDOW_HIDDEN);
    stateMachine.quit();
    CHECK( stateMachine.running() == false );
}

TEST_SUITE_END();