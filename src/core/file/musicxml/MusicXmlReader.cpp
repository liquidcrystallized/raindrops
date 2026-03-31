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

    int MusicXmlReader::getNumberOfMeasures() const
    {
        return m_reader.getNumberOfMeasures();
    }

    int MusicXmlReader::getNumberOfParts() const
    {
        return m_reader.getNumberOfParts();
    }

    std::string MusicXmlReader::getSongComposer() const
    {
        return m_reader.getSongComposer();
    }

    std::string MusicXmlReader::getSongTitle() const
    {
        return m_reader.getSongTitle();
    }
}
