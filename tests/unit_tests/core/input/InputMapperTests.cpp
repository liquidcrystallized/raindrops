#include "InputMapper.hpp"
#include "MockKeyboardInput.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("InputMapper");

TEST_CASE("Maps Key::P to Action::Pause")
{
    raindrops::MockKeyboardInput mockKeyboardInput {};
    raindrops::InputMapper inputMapper(mockKeyboardInput);

    mockKeyboardInput.pressKey(raindrops::Key::P);
    raindrops::Action action = inputMapper.getTriggeredAction();

    CHECK( action == raindrops::Action::Pause );
}

TEST_CASE("Returns None when no keys are pressed")
{
    raindrops::MockKeyboardInput mockKeyboardInput {};
    raindrops::InputMapper inputMapper(mockKeyboardInput);

    CHECK( inputMapper.getTriggeredAction() == raindrops::Action::None );
}

TEST_SUITE_END();