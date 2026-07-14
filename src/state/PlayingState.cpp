#include "PlayingState.hpp"
#include "ConfigManager.hpp"
#include "MainMenuState.hpp"
#include "StateMachine.hpp"

namespace raindrops
{
    PlayingState::PlayingState(StateMachine& stateMachine, IGraphics& renderer, MidiMonitor& midiMonitor, const bool replace)
    : State { stateMachine, renderer, midiMonitor, replace, "PlayingState" }
    {
        m_config = ConfigManager::getInstance().getConfig();
        m_noteWidth = m_config.musicSheetDisplayConfig.noteWidth;
        m_staffLineThickness = 3; //TODO: Config.

        std::unique_ptr<MusicSheet> selectedSong = stateMachine.getSelectedSong();
        if (selectedSong)
        {
            loadMusicSheet(std::move(selectedSong));
        }
        else if (!m_musicSheet)
        {
            std::cout << "Warning: No music sheet provided\n";
        }

        positionUIComponents();
    }

    void PlayingState::pause()
    {
        //TODO
    }

    void PlayingState::resume()
    {
        //TODO
    }

    void PlayingState::update()
    {
        if (raylib::Keyboard::IsKeyPressed(KEY_ESCAPE))
        {
            m_stateMachine.lastState();
        }
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

    void PlayingState::drawMeasure(Measure& measure, float positionX, float positionY)
    {
        //TODO
    }

    void PlayingState::drawNote(int pitch, int duration, float positionX, float positionY)
    {
        //TODO
    }

    void PlayingState::positionUIComponents()
    {
        m_staffLineSpacing = m_renderer.getWindowHeight() / (m_staff.getNumberOfLines() + 1);

        for (int i = 0; i < m_staff.getNumberOfLines(); i++)
        {
            const float linePositionY = m_staffLineSpacing * (i + 1) - m_staffLineThickness / 2.0f;
            m_staff.getLine(i).setPositionY(linePositionY);
        }
    }
}
