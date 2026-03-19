#include "MusicXmlReader.hpp"
#include <iostream>

namespace raindrops
{
    MusicXmlReader::MusicXmlReader(IMusicXmlReader& reader) : m_reader { reader } {}

    MusicXmlReader::~MusicXmlReader() = default;

    bool MusicXmlReader::tryLoadFileIntoStream(const std::string& filePath) const
    {
        return m_reader.tryLoadFileIntoStream(filePath);
    }

    bool MusicXmlReader::tryParseFileInputStream(std::istream& inputStream) const
    {
        return m_reader.tryParseFileInputStream(inputStream);
    }

    std::string MusicXmlReader::getRawFileContents() const
    {
        return m_reader.getRawFileContents();
    }

    std::string MusicXmlReader::getMusicXmlVersion() const
    {
        return m_reader.getMusicXmlVersion();
    }

    std::string MusicXmlReader::getMusicComposer() const
    {
        return m_reader.getMusicComposer();
    }

    std::string MusicXmlReader::getMusicTitle() const
    {
        return m_reader.getMusicTitle();
    }
}
