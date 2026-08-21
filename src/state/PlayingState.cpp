#include "PlayingState.hpp"
#include "ConfigManager.hpp"
#include "MainMenuState.hpp"
#include "StateMachine.hpp"
#include <ranges>

namespace raindrops
{
    PlayingState::PlayingState(StateMachine& stateMachine, IGraphics& renderer, MidiMonitor& midiMonitor, const bool replace)
    : State { stateMachine, renderer, midiMonitor, replace, "PlayingState" }
    , m_config { ConfigManager::getInstance().getConfig() }
    {
        m_noteWidth = m_config.musicSheetDisplayConfig.noteWidth;
        m_staffLineThicknessScaleFactor = 0.005f; //TODO: config.
        m_staffLineBufferRatio = 0.12f; //TODO: config.

        std::unique_ptr<MusicSheet> selectedSong { stateMachine.getSelectedSong() };
        if (selectedSong)
        {
            loadMusicSheet(std::move(selectedSong));
        }
        else if (!m_musicSheet)
        {
            std::println("Warning: No music sheet provided");
        }

        positionUIComponents();
        m_currentTime = std::chrono::steady_clock::now();
        m_previousTime = m_currentTime;
        m_conductor.resume();
    }

    void PlayingState::pause()
    {
        m_conductor.pause();
    }

    void PlayingState::resume()
    {
        m_conductor.resume();
    }

    void PlayingState::update()
    {
        if (raylib::Keyboard::IsKeyPressed(KEY_ESCAPE))
        {
            m_stateMachine.lastState();
        }

        m_currentTime = std::chrono::steady_clock::now();
        m_deltaTime = std::chrono::duration<float>(m_currentTime - m_previousTime).count();
        m_previousTime = m_currentTime;

        m_conductor.update(m_deltaTime);
    }

    void PlayingState::draw()
    {
        m_renderer.drawStart();

        drawMusicSheet();

        m_renderer.drawEnd();
    }

    void PlayingState::onWindowResize()
    {
        positionUIComponents();
    }

    void PlayingState::loadMusicSheet(std::unique_ptr<MusicSheet> musicSheet)
    {
        m_musicSheet = std::move(musicSheet);
        m_compositionComposer = m_musicSheet->getComposer();
        m_compositionTitle = m_musicSheet->getTitle();
    }

    void PlayingState::drawMusicSheet()
    {
        const Vector2<float> labelSize { 800, 100 };

        if (!m_musicSheet)
        {
            m_renderer.drawText("No song loaded. Please select a song from the selection region", 100, 100, 16, Colour::black);
            return;
        }

        m_renderer.drawText(m_musicSheet->getTitle(), 100, 100, 20, Colour::black);

        //TODO: Draw staves and measures.
        drawStaffLines();
        for (const auto& [index, measure] : m_musicSheet->getMeasures() | std::views::enumerate)
        {
            const float measureX { static_cast<float>(index) * m_measureWidth - m_conductor.getScrollOffset() };

            if (measureX + m_measureWidth < 0 || measureX > static_cast<float>(m_renderer.getWindowWidth()))
            {
                continue;
            }

            drawMeasure(measure, measureX, 0);
        }
    }

    void PlayingState::drawStaffLines()
    {
        for (StaffLine staffLine : m_staff.getLines())
        {
            if (staffLine.isVisible())
            {
                m_renderer.drawLine(0, staffLine.getPositionY(),
                    static_cast<float>(m_renderer.getWindowWidth()), staffLine.getPositionY(),
                    m_staffLineThickness, Colour::black);
            }
        }
    }

    void PlayingState::drawMeasure(const Measure& measure, float positionX, float positionY)
    {
        //TODO: Measure numbers for testing, but change it to actual vertical lines ||
        const std::string measureNumber { std::format("M{}", measure.getMeasureNumber()) };
        m_renderer.drawText(measureNumber, positionX, positionY, 12, Colour::grey);
    }

    void PlayingState::drawNote(int pitch, int duration, float positionX, float positionY)
    {
        //TODO
    }

    void PlayingState::positionUIComponents()
    {
        // This mess is to try and position all the staff lines within window bounds + additional whitespace buffer.
        const float buffer { static_cast<float>(m_renderer.getWindowHeight()) * m_staffLineBufferRatio };
        const float staffLineDrawArea { static_cast<float>(m_renderer.getWindowHeight()) - 2.0f * buffer };
        m_staffLineSpacing = staffLineDrawArea / (m_staff.getNumberOfLines() + 1);
        m_staffLineThickness = static_cast<float>(m_renderer.getWindowHeight()) * m_staffLineThicknessScaleFactor;

        for (int i = 0; i < m_staff.getNumberOfLines(); i++)
        {
            const float linePositionY { buffer + m_staffLineSpacing * static_cast<float>(i + 1) - m_staffLineThickness / 2.0f };
            m_staff.getLine(i).setPositionY(static_cast<int>(linePositionY));
        }

        m_measureWidth = m_noteWidth * 8.0f; //TODO: Assuming ~8 notes per measure, do something else maybe.
    }
}
