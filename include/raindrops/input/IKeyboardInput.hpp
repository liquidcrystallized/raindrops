#ifndef RAINDROPS_IKEYBOARDINPUT_HPP
#define RAINDROPS_IKEYBOARDINPUT_HPP

namespace raindrops
{
    enum class Key {
        Escape,
        P,
        Space
    };

    /**
     * @brief Abstraction for keyboard stuff so this project isn't tied to any particular third party dependency.
     */
    class IKeyboardInput {
    public:
        virtual ~IKeyboardInput() = default;
        [[nodiscard]] virtual bool isKeyPressed(Key key) const = 0;
    };
}

#endif //RAINDROPS_IKEYBOARDINPUT_HPP