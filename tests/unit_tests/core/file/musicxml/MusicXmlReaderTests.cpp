#include "MusicXmlReader.hpp"
#include "MxReader.hpp"
#include <doctest.h>
#include <sstream>
#include <string>

TEST_SUITE_BEGIN("MusicXmlReader");

/**
 * MusicXml "Hello World".
 * https://www.w3.org/2021/06/musicxml40/tutorial/hello-world/
 */
std::string musicXmlReaderTestFileContents = R"(
<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<!DOCTYPE score-partwise PUBLIC
    "-//Recordare//DTD MusicXML 3.1 Partwise//EN"
    "http://www.musicxml.org/dtds/partwise.dtd">
<score-partwise version="3.1">
  <part-list>
    <score-part id="P1">
      <part-name>Music</part-name>
    </score-part>
  </part-list>
  <part id="P1">
    <measure number="1">
      <attributes>
        <divisions>1</divisions>
        <key>
          <fifths>0</fifths>
        </key>
        <time>
          <beats>4</beats>
          <beat-type>4</beat-type>
        </time>
        <clef>
          <sign>G</sign>
          <line>2</line>
        </clef>
      </attributes>
      <note>
        <pitch>
          <step>C</step>
          <octave>4</octave>
        </pitch>
        <duration>4</duration>
        <type>whole</type>
      </note>
    </measure>
  </part>
</score-partwise>
)";

std::string nonMusicXmlFileContents = R"(
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque vitae volutpat mauris.
Curabitur vulputate, velit et fermentum vestibulum, est est fermentum magna, ut pretium nulla
velit vitae augue. Sed ultricies, nisl ac dapibus molestie, urna ligula interdum nulla, vel
ullamcorper nibh arcu lacinia dolor. Integer auctor odio nec urna tempor, sed egestas ipsum viverra.
Nulla non quam viverra, sodales ipsum vel, luctus magna. Aliquam lacus turpis, tempus eu lacus vitae,
cursus fringilla nibh. Duis molestie est eu viverra luctus. Duis in blandit diam. Proin sem leo, feugiat
non accumsan id, convallis pellentesque tortor. Donec in pellentesque lorem, vitae consectetur est.
In lobortis, nunc ac semper varius, lorem neque pharetra orci, nec ullamcorper eros nulla id magna.
Phasellus vel sapien pulvinar, facilisis leo ac, interdum nisi. Orci varius natoque penatibus et
magnis dis parturient montes, nascetur ridiculus mus. Nullam eu placerat nisl, non suscipit purus.
Fusce aliquam porttitor ex in mollis.
)";

TEST_CASE("MusicXmlReader successfully parses string stream of MusicXml file contents")
{
    raindrops::MxReader mx {};
    raindrops::MusicXmlReader musicXmlReader { mx };

    std::istringstream ss { musicXmlReaderTestFileContents };

    bool contentsAreMusicXml = musicXmlReader.tryParseFileInputStream(ss);

    CHECK( contentsAreMusicXml == true );
}

TEST_SUITE_END();