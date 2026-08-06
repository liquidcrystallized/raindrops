#ifndef RAINDROPS_MUSICSHEET_HPP
#define RAINDROPS_MUSICSHEET_HPP

#include "Measure.hpp"
#include <string>
#include <vector>

namespace raindrops
{
    /**
     * @brief Full complete (not yet) representation of a "Music Sheet". Mainly used for displaying
     * songs during song selection and loading them to populate the play screen.
     */
    class MusicSheet {
    public:
        MusicSheet();

        std::string getFilePath();
        void setFilePath(const std::string& filePath);

        std::string getTitle();
        void setTitle(const std::string& title);

        std::string getSubTitle();
        void setSubTitle(const std::string& subTitle);

        std::string getComposer();
        void setComposer(const std::string& composer);

        [[nodiscard]] bool getHasBPMInfo() const;
        void setHasBPMInfo(bool hasBPMInfo);

        [[nodiscard]] int getMeasureCount() const;
        [[nodiscard]] const std::vector<Measure>& getMeasures() const;
        void addMeasure(const Measure& measure);
        void setMeasures(const std::vector<Measure>& measures);
    private:
        std::string m_filePath {};
        std::string m_title {};
        std::string m_subTitle {};
        std::string m_composer {};
        std::string m_lyricist {};
        std::string m_copyright {};

        // Parts or instruments in a musical score.
        int m_numberOfParts {};

        // Whether BPM info is present in the sheet. If it is set to false, each measure's BPM is set to a default of 120.
        bool m_hasBPMInfo {};

        int m_numberOfMeasures;
        std::vector<Measure> m_measures {};
    };
}


#endif //RAINDROPS_MUSICSHEET_HPP