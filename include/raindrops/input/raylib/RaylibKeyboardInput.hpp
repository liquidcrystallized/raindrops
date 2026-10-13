#ifndef RAINDROPS_RAYLIBKEYBOARDINPUT_HPP
#define RAINDROPS_RAYLIBKEYBOARDINPUT_HPP

#include "IKeyboardInput.hpp"

namespace raindrops
{
    class RaylibKeyboardInput : public IKeyboardInput {
    public:
        [[nodiscard]] bool isKeyPressed(Key key) const override;
    };
}


#endif //RAINDROPS_RAYLIBKEYBOARDINPUT_HPP