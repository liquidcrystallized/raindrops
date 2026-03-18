#ifndef RAINDROPS_GRAPHICSRAYLIB_HPP
#define RAINDROPS_GRAPHICSRAYLIB_HPP

#include "IGraphics.hpp"
#include "raylib-cpp.hpp"

namespace raindrops
{
    class GraphicsRaylib final : public IGraphics {
    public:
        GraphicsRaylib();
        ~GraphicsRaylib() override;

        void drawStart() override;
        void drawEnd() override;

        [[nodiscard]] int getWindowWidth() const override;
        void setWindowWidth(int width) override;

        [[nodiscard]] int getWindowHeight() const override;
        void setWindowHeight(int height) override;

        [[nodiscard]] bool windowResized() const override;

        void drawLine(float startX, float startY, float endX, float endY, int thickness, Colour colour) override;
        void drawCircle(float centreX, float centreY, float radius, Colour colour) override;

        void drawText(std::string text, float positionX, float positionY, int fontSize, Colour colour) override;

        void toggleTestMode() override;

    private:
        raylib::Window m_window;
        raylib::Image m_image;

        static raylib::Color setColour(Colour colour);
    };
}


#endif //RAINDROPS_GRAPHICSRAYLIB_HPP