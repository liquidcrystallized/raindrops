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

        void toggleTestMode() override;

    private:
        raylib::Window m_window;
    };
}


#endif //RAINDROPS_GRAPHICSRAYLIB_HPP