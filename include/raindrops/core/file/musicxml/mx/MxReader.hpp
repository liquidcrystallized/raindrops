#ifndef RAINDROPS_MXREADER_HPP
#define RAINDROPS_MXREADER_HPP

#include "IMusicXmlReader.hpp"

namespace raindrops
{
    class MxReader final : public IMusicXmlReader {
    public:
        MxReader();
        ~MxReader() override;

        [[nodiscard]] std::string read() const override;
    };
}


#endif //RAINDROPS_MXREADER_HPP