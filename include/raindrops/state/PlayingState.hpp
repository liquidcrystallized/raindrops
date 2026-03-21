#ifndef RAINDROPS_PLAYINGSTATE_HPP
#define RAINDROPS_PLAYINGSTATE_HPP

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

        //TODO: Get rid of these magic numbers :c
        float m_staffLineSpacing { 30.0f };
        float m_noteWidth { 40.0f };
        float m_measureWidth { 150.0f };
        Vector2<int> m_sheetStartPosition;

        void drawMusicSheet();
        void drawStaffLines(float positionY, int staffCount);
        void drawMeasure(Measure& measure, float positionX, float positionY);
        void drawNote(int pitch, int duration, float positionX, float positionY);
    };
}


#endif //RAINDROPS_PLAYINGSTATE_HPP