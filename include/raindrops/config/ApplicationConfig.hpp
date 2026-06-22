#ifndef RAINDROPS_APPLICATIONCONFIG_HPP
#define RAINDROPS_APPLICATIONCONFIG_HPP

#include "MidiConfig.hpp"
#include "MusicSheetDisplayConfig.hpp"
#include "WindowConfig.hpp"
#include <string>

namespace raindrops
{
    /**
     * @brief Aggregates all other configs.
     */
    struct ApplicationConfig {
        MidiConfig midiConfig {};
        MusicSheetDisplayConfig musicSheetDisplayConfig {};
        WindowConfig windowConfig {};

        std::string appName { "raindrops" };
        std::string appVersion { "0.1.0" };

        [[nodiscard]] bool isValid() const
        {
            return  midiConfig.isValid() &&
                    musicSheetDisplayConfig.isValid() &&
                    windowConfig.isValid();
        }

        // Debug convenience.
        void print() const;
    };
}

#endif //RAINDROPS_APPLICATIONCONFIG_HPP