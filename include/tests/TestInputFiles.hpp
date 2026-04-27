#ifndef RAINDROPS_TESTINPUTFILES_HPP
#define RAINDROPS_TESTINPUTFILES_HPP

#include <string>

namespace TestInputFiles
{
    inline std::string pitchesPitchesFilePath { "../../tests/inputs/musicxml/01a-Pitches-Pitches.xml" };
    inline std::string helloWorldFilePath { "../../tests/inputs/musicxml/hello-world.xml" };
    inline std::string nonMusicXmlFilePath { "../../tests/inputs/musicxml/non-musicxml.xml" };
    inline std::string noMeasuresXmlFilePath { "../../tests/inputs/musicxml/no-measures.xml" };

    inline std::string clairDeLuneFilePath { "../../tests/inputs/musicxml/Claude_Debussy-Clair_de_Lune.musicxml" };
    inline std::string airOnTheGStringFilePath { "../../tests/inputs/musicxml/J.S_Bach-Air_on_the_G_String.musicxml" };
}

#endif //RAINDROPS_TESTINPUTFILES_HPP