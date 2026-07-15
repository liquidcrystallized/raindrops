#ifndef RAINDROPS_PLAYINGSTATE_HPP
#define RAINDROPS_PLAYINGSTATE_HPP

#include "ApplicationConfig.hpp"
#include "Staff.hpp"
#include "State.hpp"
#include "MusicSheet.hpp"

namespace raindrops
{
    class PlayingState final : public State {
    public:
        PlayingState(StateMachine&, IGraphics&, MidiMonitor&, bool replace = true);

        void pause() override;
        void resume() override;

        void update() override;
        void draw() override;

        void onWindowResize() override;

        void loadMusicSheet(std::unique_ptr<MusicSheet> musicSheet);
    private:
        std::unique_ptr<MusicSheet> m_musicSheet;
        std::string m_compositionComposer {};
        std::string m_compositionTitle {};

        Staff m_staff {};

        ApplicationConfig  m_config;
        float m_staffLineBufferRatio {}; // How much (in percentage %) of the window height as top/bot buffer.
        float m_staffLineSpacing {};
        float m_staffLineThickness {};
        float m_staffLineThicknessScaleFactor {};
        float m_noteWidth {};
        float m_measureWidth {};

        void drawMusicSheet();
        void drawStaffLines();
        void drawMeasure(Measure& measure, float positionX, float positionY);
        void drawNote(int pitch, int duration, float positionX, float positionY);

        void positionUIComponents();
    };
}


#endif //RAINDROPS_PLAYINGSTATE_HPP