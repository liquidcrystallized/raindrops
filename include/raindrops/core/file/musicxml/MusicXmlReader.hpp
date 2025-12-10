#ifndef RAINDROPS_MUSICXMLREADER_HPP
#define RAINDROPS_MUSICXMLREADER_HPP

#include "IMusicXmlReader.hpp"

namespace raindrops
{
    class MusicXmlReader {
    public:
        explicit MusicXmlReader(const IMusicXmlReader&);
        ~MusicXmlReader();

         [[nodiscard]] std::string read() const;

    private:
        const IMusicXmlReader& m_reader;
    };
}


#endif //RAINDROPS_MUSICXMLREADER_HPP