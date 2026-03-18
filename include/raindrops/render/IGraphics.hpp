#ifndef RAINDROPS_IRENDERER_HPP
#define RAINDROPS_IRENDERER_HPP

#include <string>

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

        /**
         * Window management stuff.
         */

        [[nodiscard]] virtual int getWindowWidth() const = 0;
        virtual void setWindowWidth(int width) = 0;

        [[nodiscard]] virtual int getWindowHeight() const = 0;
        virtual void setWindowHeight(int height) = 0;

        [[nodiscard]] virtual bool windowResized() const = 0;

        /**
         * Basic shape drawing functions.
         */

        virtual void drawLine(float startX, float startY, float endX, float endY, int thickness, std::string colour) = 0;
        virtual void drawCircle(float centreX, float centreY, float radius, std::string colour) = 0;

        /**
         * Text rendering functions.
         */

        virtual void drawText(std::string text, float positionX, float positionY, int fontSize, std::string colour) = 0;

        /**
         * Enable things like headless mode. For use with unit tests.
         */

        virtual void toggleTestMode() = 0;
    };
}


#endif //RAINDROPS_IRENDERER_HPP