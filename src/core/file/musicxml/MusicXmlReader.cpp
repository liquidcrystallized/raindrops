#include "MusicXmlReader.hpp"
#include <iostream>

namespace raindrops
{
    MusicXmlReader::MusicXmlReader(IMusicXmlReader& reader)
    : m_reader { reader }
    {
        std::cout << "MusicXmlReader constructed.\n";
    }

    MusicXmlReader::~MusicXmlReader()
    {
        std::cout << "MusicXmlReader destructed.\n";
    }

    bool MusicXmlReader::tryLoadFileIntoStream(const std::string& filePath) const
    {
        if (!m_reader.tryLoadFileIntoStream(filePath))
        {
            std::cerr << "MusicXmlReader::tryLoadFileIntoStream failed.\n";
            return false;
        }

        return true;
    }

    bool MusicXmlReader::tryParseFileInputStream(std::istream& inputStream) const
    {
        if (!m_reader.tryParseFileInputStream(inputStream))
        {
            std::cerr << "MusicXmlReader::tryParseFileInputStream failed\n";
            return false;
        }

        return true;
    }

    std::string MusicXmlReader::getRawFileContents() const
    {
        return m_reader.getRawFileContents();
    }

    std::string MusicXmlReader::getMusicXmlVersion() const
    {
        return m_reader.getMusicXmlVersion();
    }
}
