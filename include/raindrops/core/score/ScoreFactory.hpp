#ifndef RAINDROPS_SCOREFACTORY_HPP
#define RAINDROPS_SCOREFACTORY_HPP

#include "MusicXmlReader.hpp"
#include "MusicSheet.hpp"
#include <memory>

namespace raindrops
{
    /**
     * @brief Converts any parsed MusicXML data and populates a custom music sheet object.
     */
    class ScoreFactory {
    public:
        static std::unique_ptr<MusicSheet> createFromReader(const MusicXmlReader& reader);

    private:
        ScoreFactory() = default;
    };
}


#endif //RAINDROPS_SCOREFACTORY_HPP