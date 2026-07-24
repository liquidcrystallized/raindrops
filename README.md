> The application is currently under development and no binaries are provided yet.
> Binaries will be provided when the application reaches 1.0 status.

# What is this?

raindrops is an application that displays music notes in an intuitive way to 
help piano players sight-read. This application does not teach you how to play the
piano, it is expected that users already know at least the basics from a teacher
or some other learning source. You'll also need a midi keyboard/digital piano that can connect directly to your
device via USB.

## Loading songs

This application accepts MusicXML files for songs. Currently supported formats are:

- [x] .xml
- [x] .musicxml
- [ ] .mxl

### Why MusicXML instead of Midi?

Music sheets/scores are information dense and midi files lack the information required to properly
display them. To briefly name a *few things* missing from a MIDI file:

- Dynamics, both individual markings (p, ff) and changes (crescendo, dimuendo)
- Articulation (slurs, staccato, accents, etc)
- Pedal markings
- Performance directions/indications (*dolce*, violent, *molto espressivo*)
- Tempo/style indications (*andante*, swing 8th notes, rock feel)
- Beaming information/Stem direction

As this application focuses on the development of *sight reading skills*, basically being able to read any music
sheet/score placed in front of the player with confidence, missing the above elements and more is detrimental to the application's functionality and goals.

The [unofficial MusicXML test suite music xml files](https://github.com/lilypond/lilypond/tree/master/input/regression/musicxml)
supplied by the [LilyPond](https://lilypond.org/) devs can be used as test "songs" for development. The license for the tests and files 
are [MIT](https://lilypond.org/doc/v2.24/input/regression/musicxml/collated-files.html).

## License and Dependencies

Sources in this repository are released under the GPLv3 license.

These are the licenses for the dependencies:

- [raylib](https://github.com/raysan5/raylib) - Zlib
- [raylib-cpp](https://github.com/RobLoach/raylib-cpp) - Zlib
- [raygui](https://github.com/raysan5/raygui) - Zlib
- [raygui-cpp](https://github.com/scastd/raygui-cpp/) - Zlib
- [doctest](https://github.com/doctest/doctest) - MIT
- [rtmidi](https://github.com/thestk/rtmidi) - [LICENSE](https://github.com/thestk/rtmidi/blob/master/LICENSE)
- [mx](https://github.com/webern/mx) - MIT
- [glaze](https://github.com/stephenberry/glaze) - MIT
