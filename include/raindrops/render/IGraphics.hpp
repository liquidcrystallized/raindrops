#ifndef RAINDROPS_IRENDERER_HPP
#define RAINDROPS_IRENDERER_HPP


namespace raindrops
{
    class IGraphics {
    public:
        virtual ~IGraphics() = default;

        virtual void draw() const = 0;

        [[nodiscard]] virtual int getWindowWidth() const = 0;
        virtual void setWindowWidth(int width) = 0;

        [[nodiscard]] virtual int getWindowHeight() const = 0;
        virtual void setWindowHeight(int height) = 0;
    };
}


#endif //RAINDROPS_IRENDERER_HPP