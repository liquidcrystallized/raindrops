#ifndef RAINDROPS_IRENDERER_HPP
#define RAINDROPS_IRENDERER_HPP


namespace raindrops
{
    class IGraphics {
    public:
        virtual ~IGraphics() = default;

        /**
         * Some graphics frameworks have functions indicating when
         * drawing starts and ends, so draw is split here.
         */
        virtual void drawStart() = 0;
        virtual void drawEnd() = 0;

        [[nodiscard]] virtual int getWindowWidth() const = 0;
        virtual void setWindowWidth(int width) = 0;

        [[nodiscard]] virtual int getWindowHeight() const = 0;
        virtual void setWindowHeight(int height) = 0;

        /**
         * Enable things like headless mode. For use with unit tests.
         */
        virtual void toggleTestMode() = 0;
    };
}


#endif //RAINDROPS_IRENDERER_HPP