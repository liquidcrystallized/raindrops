#ifndef RAINDROPS_MUSICSHEETRENDERER_HPP
#define RAINDROPS_MUSICSHEETRENDERER_HPP

#include "IGraphics.hpp"
#include "ApplicationConfig.hpp"
#include "Conductor.hpp"
#include "MusicSheet.hpp"
#include "Staff.hpp"

namespace raindrops
{
    class MusicSheetRenderer {
    public:
        explicit MusicSheetRenderer(IGraphics&);

        void render(const MusicSheet&, const Conductor&);
        void recalculateStaffElementSizes();
    private:
        IGraphics& m_renderer;
        const ApplicationConfig& m_config;

        Staff m_staff {};

        float m_measureWidth {};
        float m_noteWidth {};
        float m_staffLineBufferRatio {}; // How much (in percentage %) of the window height as top/bot buffer.
        float m_staffLineThickness {};
        float m_staffLineThicknessScaleFactor {};

        void drawStaffLines() const;
        void drawMeasure(const Measure&, float positionX) const;
        void drawNote();
        [[nodiscard]] bool isWithinView(float positionX) const;
    };
}


#endif //RAINDROPS_MUSICSHEETRENDERER_HPP