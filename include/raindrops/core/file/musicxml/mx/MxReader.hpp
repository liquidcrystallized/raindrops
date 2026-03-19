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

        [[nodiscard]] bool tryLoadFileIntoStream(const std::string& filePath) override;

        [[nodiscard]] bool tryParseFileInputStream(std::istream& inputStream) override;

        [[nodiscard]] std::string getRawFileContents() const override;

        [[nodiscard]] std::string getMusicXmlVersion() const override;

        [[nodiscard]] std::string getMusicComposer() const override;

        [[nodiscard]] std::string getMusicTitle() const override;

    private:
        mx::api::DocumentManager& m_documentManager;
        mx::api::ScoreData m_scoreData;
        std::string m_musicXmlVersion;
        std::string m_fileContents;
    };
}


#endif //RAINDROPS_MXREADER_HPP