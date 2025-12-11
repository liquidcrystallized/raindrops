#ifndef RAINDROPS_GRAPHICSRAYLIB_HPP
#define RAINDROPS_GRAPHICSRAYLIB_HPP

#include "IGraphics.hpp"

namespace raindrops
{
    class GraphicsRaylib final : public IGraphics {
    public:
        GraphicsRaylib();
        ~GraphicsRaylib() override;

        void draw() const override;
    };
}


#endif //RAINDROPS_GRAPHICSRAYLIB_HPP