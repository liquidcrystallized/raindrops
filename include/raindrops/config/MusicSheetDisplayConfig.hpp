#ifndef RAINDROPS_MUSICSHEETDISPLAYCONFIG_HPP
#define RAINDROPS_MUSICSHEETDISPLAYCONFIG_HPP

namespace raindrops
{
    /**
     * @brief Configuration for how a midi sheet looks when rendered.
     * Used only in the play screen.
     * There will need to be constant tweaks for some sane/nice looking defaults.
     */
    struct MusicSheetDisplayConfig {
        float noteWidth { 40.0f };
        float measureWidth { 150.0f };
        float staffSpacing { 30.0f };
        int fontSize { 16 };

        [[nodiscard]] bool isValid() const
        {
            return noteWidth > 0 && measureWidth > 0 && staffSpacing > 0 && fontSize > 0;
        }
    };
}

#endif //RAINDROPS_MUSICSHEETDISPLAYCONFIG_HPP