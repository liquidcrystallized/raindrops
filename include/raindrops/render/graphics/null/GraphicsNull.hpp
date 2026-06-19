#ifndef RAINDROPS_GRAPHICSNULL_HPP
#define RAINDROPS_GRAPHICSNULL_HPP

#include "IGraphics.hpp"

namespace raindrops
{
    /**
     * @brief Null implementation of IGraphics for use in unit tests.
     *
     * Just a headless implementation that pretty much does nothing.
     * No drawing, no inits, no nothing.
     * For tests where rendering is not required. Don't want to make
     * windows and call some extern dependency when not needed.
     */
    class GraphicsNull final : public IGraphics {
    public:
        GraphicsNull() = default;
        ~GraphicsNull() override = default;

        GraphicsNull(const GraphicsNull&) = delete;
        GraphicsNull& operator=(const GraphicsNull&) = delete;

        GraphicsNull(GraphicsNull&&) noexcept = default;
        GraphicsNull& operator=(GraphicsNull&&) noexcept = default;

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
        int m_windowWidth { 640 };
        int m_windowHeight { 480 };
        bool m_windowResized { false };
        bool m_testMode { false };
    };
}

#endif //RAINDROPS_GRAPHICSNULL_HPP