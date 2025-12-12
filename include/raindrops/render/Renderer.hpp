#ifndef RAINDROPS_RENDERER_HPP
#define RAINDROPS_RENDERER_HPP

#include "IGraphics.hpp"

namespace raindrops
{
    class Renderer {
    public:
        explicit Renderer(IGraphics&);
        ~Renderer();

        void draw() const;

        [[nodiscard]] int getWindowWidth() const;
        void setWindowWidth(int width) const;

        [[nodiscard]] int getWindowHeight() const;
        void setWindowHeight(int height) const;
    private:
        IGraphics& m_graphics;
    };
}


#endif //RAINDROPS_RENDERER_HPP