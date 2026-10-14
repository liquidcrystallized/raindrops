#ifndef RAINDROPS_MOCKKEYBOARDINPUT_HPP
#define RAINDROPS_MOCKKEYBOARDINPUT_HPP

#include "IKeyboardInput.hpp"
#include <unordered_set>

namespace raindrops
{
    class MockKeyboardInput : public IKeyboardInput {
    public:
        void pressKey(Key key);
        void clear();

        bool isKeyPressed(Key key) const override;

    private:
        std::unordered_set<Key> m_pressedKeys {};
    };
}

#endif //RAINDROPS_MOCKKEYBOARDINPUT_HPP