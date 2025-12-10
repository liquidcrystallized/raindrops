#include "MxReader.hpp"
#include <iostream>

namespace raindrops
{
    MxReader::MxReader()
    {
        std::cout << "MxReader constructed.\n";
    }

    MxReader::~MxReader()
    {
        std::cout << "MxReader destructed.\n";
    }

    std::string MxReader::read() const
    {
        return "MxReader\n";
    }
}