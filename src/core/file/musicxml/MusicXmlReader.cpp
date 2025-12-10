#include "MusicXmlReader.hpp"
#include <iostream>

namespace raindrops
{
    MusicXmlReader::MusicXmlReader(const IMusicXmlReader& reader)
    : m_reader { reader }
    {
        std::cout << "MusicXmlReader constructed.\n";
    }

    MusicXmlReader::~MusicXmlReader()
    {
        std::cout << "MusicXmlReader destructed.\n";
    }

    std::string MusicXmlReader::read() const
    {
        return m_reader.read();
    }
}