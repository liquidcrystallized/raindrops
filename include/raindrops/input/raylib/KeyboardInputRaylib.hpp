#ifndef RAINDROPS_KEYBOARDINPUTRAYLIB_HPP
#define RAINDROPS_KEYBOARDINPUTRAYLIB_HPP

#include "IKeyboardInput.hpp"

namespace raindrops
{
    class KeyboardInputRaylib : public IKeyboardInput {
    public:
        [[nodiscard]] bool isKeyPressed(Key key) const override;
    };
}


#endif //RAINDROPS_KEYBOARDINPUTRAYLIB_HPP