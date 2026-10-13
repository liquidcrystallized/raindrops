#include "MockKeyboardInput.hpp"

namespace raindrops
{
    void MockKeyboardInput::pressKey(const Key key)
    {
        m_pressedKeys.insert(key);
    }

    void MockKeyboardInput::clear()
    {
        m_pressedKeys.clear();
    }

    bool MockKeyboardInput::isKeyPressed(const Key key) const
    {
        return m_pressedKeys.contains(key);
    }
}
