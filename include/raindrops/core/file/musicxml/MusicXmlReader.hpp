#ifndef RAINDROPS_MUSICXMLREADER_HPP
#define RAINDROPS_MUSICXMLREADER_HPP

#include "IMusicXmlReader.hpp"

namespace raindrops
{
    class MusicXmlReader {
    public:
        explicit MusicXmlReader(IMusicXmlReader&);
        ~MusicXmlReader();

        [[nodiscard]] bool tryLoadFileIntoStream(const std::string& filePath) const;

        [[nodiscard]] bool tryParseFileInputStream(std::istream& inputStream) const;

        [[nodiscard]] std::string getRawFileContents() const;

        [[nodiscard]] std::string getMusicXmlVersion() const;

    private:
        IMusicXmlReader& m_reader;
    };
}


#endif //RAINDROPS_MUSICXMLREADER_HPP