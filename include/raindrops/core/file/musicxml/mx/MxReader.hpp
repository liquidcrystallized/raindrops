#ifndef RAINDROPS_MXREADER_HPP
#define RAINDROPS_MXREADER_HPP

#include "IMusicXmlReader.hpp"
#include <mx/api/DocumentManager.h>
#include <fstream>

namespace raindrops
{
    class MxReader final : public IMusicXmlReader {
    public:
        MxReader();
        ~MxReader() override;

        bool tryLoadFileIntoStream(const std::string& filePath) override;

        bool tryParseFileInputStream(std::istream& inputStream) override;

        [[nodiscard]] std::string getRawFileContents() const override;

        [[nodiscard]] std::string getMusicXmlVersion() const override;

        [[nodiscard]] int getNumberOfMeasures() const override;
        [[nodiscard]] std::vector<Measure> getMeasures() const override;

        [[nodiscard]] int getNumberOfParts() const override;

        [[nodiscard]] std::string getSongComposer() const override;

        [[nodiscard]] std::string getSongTitle() const override;

    private:
        mx::api::DocumentManager& m_documentManager;
        mx::api::ScoreData m_scoreData;
        std::string m_musicXmlVersion;
        std::string m_fileContents;
        int numberOfMeasures;
        int numberOfParts;

        // Stuff below is just a couple of helper methods to wrangle the data from the mx library.
        // There's probably a cleaner way of doing this but eh, this stuffs only specific to
        // using mx so ¯\_(ツ)_/¯
        static int convertMxPitchDataToMidiKey(mx::api::Step step, int octave, int alter);
        static Note createNoteFromMxNote(const mx::api::NoteData& mxNote);
        static std::vector<Note> extractNotesFromMxStaff(const mx::api::StaffData& staff);
        static Measure convertFromMxMeasure(const mx::api::MeasureData& mxMeasure, int index);
    };
}


#endif //RAINDROPS_MXREADER_HPP