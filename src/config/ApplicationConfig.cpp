#include "ApplicationConfig.hpp"
#include <print>

namespace raindrops
{
    void ApplicationConfig::print() const
    {
        std::println("=== Raindrops Configuration ===");
        std::println("MIDI Port: {}", midiConfig.port);
        std::println("MIDI Channel: {}", midiConfig.channel);
        std::println("MIDI Auto-Detect: {}", midiConfig.autoDetect ? "Yes" : "No");
        std::println("Window: {}x{}", windowConfig.width, windowConfig.height);
        std::println("Fullscreen: {}", windowConfig.fullscreen ? "Yes" : "No");
        std::println("VSync: {}", windowConfig.vsync ? "Yes" : "No");
        std::println("Note Width: {}", musicSheetDisplayConfig.noteWidth);
        std::println("Measure Width: {}", musicSheetDisplayConfig.measureWidth);
        std::println("Staff Spacing: {}", musicSheetDisplayConfig.staffSpacing);
        std::println("Font Size: {}", musicSheetDisplayConfig.fontSize);
        std::println("================================");
    }
}
