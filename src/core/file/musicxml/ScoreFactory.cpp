#include "ScoreFactory.hpp"

namespace raindrops
{
    std::unique_ptr<MusicSheet> ScoreFactory::createFromReader(const MusicXmlReader& reader)
    {
        auto musicSheet = std::make_unique<MusicSheet>();

        musicSheet->setTitle(reader.getSongTitle());
        musicSheet->setComposer(reader.getSongComposer());
        //musicSheet->setHasBPMInfo(reader.getHasBPMInfo()); //TODO

        for (int i = 1; i <= reader.getNumberOfMeasures(); i++)
        {
            Measure measure;
            measure.setMeasureNumber(i);
            musicSheet->addMeasure(measure);
        }

        return musicSheet;
    }
}
