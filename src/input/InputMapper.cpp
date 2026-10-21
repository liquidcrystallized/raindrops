#include "InputMapper.hpp"

namespace raindrops
{
    InputMapper::InputMapper(IKeyboardInput& device) : m_device { device } {}

    Action InputMapper::getTriggeredAction() const
    {
        if (m_device.isKeyPressed(Key::Escape)) return Action::Back;
        if (m_device.isKeyPressed(Key::P)) return Action::Pause;
        return Action::None;
    }
}
