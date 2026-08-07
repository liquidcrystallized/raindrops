#include "ScoreFactory.hpp"

namespace raindrops
{
    std::unique_ptr<MusicSheet> ScoreFactory::createFromReader(const MusicXmlReader& reader)
    {
        auto musicSheet = std::make_unique<MusicSheet>();

        musicSheet->setTitle(reader.getSongTitle());
        musicSheet->setComposer(reader.getSongComposer());
        //musicSheet->setHasBPMInfo(reader.getHasBPMInfo()); //TODO

        musicSheet->setMeasures(reader.getMeasures());

        return musicSheet;
    }
}
