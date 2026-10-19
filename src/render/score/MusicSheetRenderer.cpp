#include "MusicSheetRenderer.hpp"
#include "ConfigManager.hpp"
#include <ranges>

namespace raindrops
{
    MusicSheetRenderer::MusicSheetRenderer(IGraphics& renderer)
    : m_renderer { renderer }
    , m_config { ConfigManager::getInstance().getConfig() }
    {
        m_noteWidth = m_config.musicSheetDisplayConfig.noteWidth;
        m_staffLineBufferRatio = m_config.musicSheetDisplayConfig.staffLineBufferRatio;
        m_staffLineThicknessScaleFactor = m_config.musicSheetDisplayConfig.staffLineThicknessScaleFactor;
    }

    void MusicSheetRenderer::render(const MusicSheet& musicSheet, const Conductor& conductor)
    {
        drawStaffLines();
        for (const auto&[index, measure] : musicSheet.getMeasures() | std::views::enumerate)
        {
            m_measureWidth = m_noteWidth * 8.0f; //TODO: Assuming ~8 notes per measure, temporary for testing.
            const float measurePositionX { static_cast<float>(index) * m_measureWidth - conductor.getScrollOffset() };

            if (isWithinView(measurePositionX))
            {
                drawMeasure(measure, measurePositionX);
            }
        }
    }

    void MusicSheetRenderer::drawStaffLines() const
    {
        for (StaffLine staffLine : m_staff.getLines())
        {
            if (staffLine.isVisible())
            {
                m_renderer.drawLine(0,
                    static_cast<float>(staffLine.getPositionY()),
                    static_cast<float>(m_renderer.getWindowWidth()),
                    static_cast<float>(staffLine.getPositionY()),
                    m_staffLineThickness, Colour::black);
            }
        }
    }

    void MusicSheetRenderer::drawMeasure(const Measure& measure, const float positionX) const
    {
        const std::string measureNumber { std::format("M{}", measure.getMeasureNumber()) };
        //TODO: Move text drawing somewhere else.
        m_renderer.drawText(measureNumber, positionX, 0, 12, Colour::grey);

        m_renderer.drawLine(positionX, static_cast<float>(m_staff.getLine(0).getPositionY()),
                            positionX, static_cast<float>(m_staff.getLine(4).getPositionY()),
                            m_staffLineThickness, Colour::black);

        m_renderer.drawLine(positionX, static_cast<float>(m_staff.getLine(11).getPositionY()),
                            positionX, static_cast<float>(m_staff.getLine(15).getPositionY()),
                            m_staffLineThickness, Colour::black);
    }

    void MusicSheetRenderer::drawNote()
    {
        //TODO
    }

    bool MusicSheetRenderer::isWithinView(const float positionX) const
    {
        return !(positionX + m_measureWidth < 0 || positionX > static_cast<float>(m_renderer.getWindowWidth()));
    }

    void MusicSheetRenderer::recalculateStaffElementSizes()
    {
        // This mess is to try and position all the staff lines within window bounds + additional whitespace buffer.
        const float buffer { static_cast<float>(m_renderer.getWindowHeight()) * m_staffLineBufferRatio };
        const float staffLineDrawArea { static_cast<float>(m_renderer.getWindowHeight()) - 2.0f * buffer };
        const float staffLineSpacing = staffLineDrawArea / (static_cast<float>(m_staff.getNumberOfLines()) + 1);
        m_staffLineThickness = static_cast<float>(m_renderer.getWindowHeight()) * m_staffLineThicknessScaleFactor;

        for (int i = 0; i < m_staff.getNumberOfLines(); i++)
        {
            const float linePositionY { buffer + staffLineSpacing * static_cast<float>(i + 1) - m_staffLineThickness / 2.0f };
            m_staff.getLine(i).setPositionY(static_cast<int>(linePositionY));
        }

        m_measureWidth = m_noteWidth * 8.0f; //TODO: Assuming ~8 notes per measure, do something else maybe.
    }
}