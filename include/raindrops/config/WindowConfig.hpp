#ifndef RAINDROPS_WINDOWCONFIG_HPP
#define RAINDROPS_WINDOWCONFIG_HPP

namespace raindrops
{
    struct WindowConfig {
        int width = 1280;
        int height = 720;
        bool fullscreen = false;
        bool vsync = true;
        bool resizable = true;

        [[nodiscard]] bool isValid() const
        {
            return width > 0 && height > 0;
        }
    };
}

#endif //RAINDROPS_WINDOWCONFIG_HPP