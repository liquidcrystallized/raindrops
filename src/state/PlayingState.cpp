#include "PlayingState.hpp"
#include "ConfigManager.hpp"
#include "MainMenuState.hpp"
#include "StateMachine.hpp"

namespace raindrops
{
    PlayingState::PlayingState(StateMachine& stateMachine, IGraphics& renderer, MidiMonitor& midiMonitor, const bool replace)
    : State { stateMachine, renderer, midiMonitor, replace, "PlayingState" }
    , m_sheetStartPosition { 100, 50 }
    {
        m_config = ConfigManager::getInstance().getConfig();
        m_staffLineSpacing = m_config.musicSheetDisplayConfig.staffSpacing;
        m_noteWidth = m_config.musicSheetDisplayConfig.noteWidth;

        std::unique_ptr<MusicSheet> selectedSong = stateMachine.getSelectedSong();
        if (selectedSong)
        {
            loadMusicSheet(std::move(selectedSong));
        }
        else if (!m_musicSheet)
        {
            std::cout << "Warning: No music sheet provided\n";
        }
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
        //TODO
    }

    void PlayingState::loadMusicSheet(std::unique_ptr<MusicSheet> musicSheet)
    {
        m_musicSheet = std::move(musicSheet);
        m_compositionComposer = m_musicSheet->getComposer();
        m_compositionTitle = m_musicSheet->getTitle();
    }

    //TODO: Rewrite to be less verbose.
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
    }

    void PlayingState::drawStaffLines(float positionY, int staffCount)
    {
        //TODO
    }

    void PlayingState::drawMeasure(Measure& measure, float positionX, float positionY)
    {
        //TODO
    }

    void PlayingState::drawNote(int pitch, int duration, float positionX, float positionY)
    {
        //TODO
    }
}
