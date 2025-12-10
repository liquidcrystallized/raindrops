#ifndef RAINDROPS_IMUSICXMLREADER_HPP
#define RAINDROPS_IMUSICXMLREADER_HPP

#include <string>

namespace raindrops
{
    class IMusicXmlReader {
    public:
        virtual ~IMusicXmlReader() = default;

        // Not sure about the return value yet.
        [[nodiscard]] virtual std::string read() const = 0;
    };
}

#endif //RAINDROPS_IMUSICXMLREADER_HPP