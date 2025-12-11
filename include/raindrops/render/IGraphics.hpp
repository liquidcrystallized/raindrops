#ifndef RAINDROPS_IRENDERER_HPP
#define RAINDROPS_IRENDERER_HPP


namespace raindrops
{
    class IGraphics {
    public:
        virtual ~IGraphics() = default;

        virtual void draw() const = 0;
    };
}


#endif //RAINDROPS_IRENDERER_HPP