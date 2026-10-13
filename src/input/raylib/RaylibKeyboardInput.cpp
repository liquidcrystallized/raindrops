#include "RaylibKeyboardInput.hpp"
#include <raylib-cpp.hpp>

namespace raindrops
{
    bool RaylibKeyboardInput::isKeyPressed(const Key key) const
    {
        switch (key)
        {
            case Key::Escape:   return raylib::Keyboard::IsKeyPressed(KEY_ESCAPE);
            case Key::P:        return raylib::Keyboard::IsKeyPressed(KEY_P);
            case Key::Space:    return raylib::Keyboard::IsKeyPressed(KEY_SPACE);
            default:            return false;
        }
    }
}
