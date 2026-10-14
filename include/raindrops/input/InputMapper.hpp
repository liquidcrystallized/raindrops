#ifndef RAINDROPS_INPUTMAPPER_HPP
#define RAINDROPS_INPUTMAPPER_HPP

#include "IKeyboardInput.hpp"

namespace raindrops
{
    enum class Action {
        Back,
        Pause,
        None
    };

    class InputMapper {
    public:
        explicit InputMapper(IKeyboardInput& device);

        [[nodiscard]] Action getTriggeredAction() const;

    private:
        IKeyboardInput& m_device;
    };
}


#endif //RAINDROPS_INPUTMAPPER_HPP