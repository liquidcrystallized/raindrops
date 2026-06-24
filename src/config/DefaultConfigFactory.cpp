#include "DefaultConfigFactory.hpp"

namespace raindrops
{
    ApplicationConfig DefaultConfigFactory::create()
    {
        ApplicationConfig config;

        config.appName = "raindrops";
        config.appVersion = "0.1.0";

        config.midiConfig.port = 0;
        config.midiConfig.channel = 0;
        config.midiConfig.autoDetect = true;

        config.windowConfig.width = 1280;
        config.windowConfig.height = 720;
        config.windowConfig.fullscreen = false;
        config.windowConfig.vsync = true;
        config.windowConfig.resizable = true;

        config.musicSheetDisplayConfig.noteWidth = 40.0f;
        config.musicSheetDisplayConfig.measureWidth = 150.0f;
        config.musicSheetDisplayConfig.staffSpacing = 30.0f;
        config.musicSheetDisplayConfig.fontSize = 16;

        return config;
    }
}
