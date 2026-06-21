#include "ApplicationConfig.hpp"
#include <iostream>

namespace raindrops
{
    void ApplicationConfig::print() const
    {
        std::cout << "=== Raindrops Configuration ===\n";
        std::cout << "MIDI Port: " << midiConfig.port << '\n';
        std::cout << "MIDI Channel: " << midiConfig.channel << '\n';
        std::cout << "MIDI Auto-Detect: " << (midiConfig.autoDetect ? "Yes" : "No") << '\n';
        std::cout << "Window: " << windowConfig.width << "x" << windowConfig.height << '\n';
        std::cout << "Fullscreen: " << (windowConfig.fullscreen ? "Yes" : "No") << '\n';
        std::cout << "VSync: " << (windowConfig.vsync ? "Yes" : "No") << '\n';
        std::cout << "Note Width: " << musicSheetDisplayConfig.noteWidth << '\n';
        std::cout << "Measure Width: " << musicSheetDisplayConfig.measureWidth << '\n';
        std::cout << "Staff Spacing: " << musicSheetDisplayConfig.staffSpacing << '\n';
        std::cout << "Font Size: " << musicSheetDisplayConfig.fontSize << '\n';
        std::cout << "================================\n";
    }
}
