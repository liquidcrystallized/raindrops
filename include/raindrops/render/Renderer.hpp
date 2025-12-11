#ifndef RAINDROPS_RENDERER_HPP
#define RAINDROPS_RENDERER_HPP

#include "IGraphics.hpp"

namespace raindrops
{
    class Renderer {
    public:
        explicit Renderer(const IGraphics&);
        ~Renderer();

        void draw() const;
    private:
        const IGraphics& m_graphics;
    };
}


#endif //RAINDROPS_RENDERER_HPP