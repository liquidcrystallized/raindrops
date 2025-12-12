#ifndef RAINDROPS_RENDERER_HPP
#define RAINDROPS_RENDERER_HPP

#include "IGraphics.hpp"

namespace raindrops
{
    /**
     * A layer between a graphics framework and the application.
     */
    class Renderer {
    public:
        explicit Renderer(IGraphics&);
        ~Renderer();

        void drawStart() const;
        void drawEnd() const;

        [[nodiscard]] int getWindowWidth() const;
        void setWindowWidth(int width) const;

        [[nodiscard]] int getWindowHeight() const;
        void setWindowHeight(int height) const;

        [[nodiscard]] bool windowResized() const;

        void toggleTestMode() const;
    private:
        IGraphics& m_graphics;
    };
}


#endif //RAINDROPS_RENDERER_HPP