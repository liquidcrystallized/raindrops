#ifndef RAINDROPS_MODE_HPP
#define RAINDROPS_MODE_HPP

#include <string>

namespace raindrops
{
    /**
     * @brief https://en.wikipedia.org/wiki/Mode_(music), https://www.w3.org/2021/06/musicxml40/musicxml-reference/elements/mode/
     */
    enum class Mode {
        none,
        major,
        minor,
        dorian,
        phrygian,
        lydian,
        mixolydian,
        aeolian,
        ionian,
        locrian
    };

    inline std::string to_string(const Mode mode)
    {
        switch (mode)
        {
            case Mode::major:       return "major";
            case Mode::minor:       return "minor";
            case Mode::dorian:      return "dorian";
            case Mode::phrygian:    return "phrygian";
            case Mode::lydian:      return "lydian";
            case Mode::mixolydian:  return "mixolydian";
            case Mode::aeolian:     return "aeolian";
            case Mode::ionian:      return "ionian";
            case Mode::locrian:     return "locrian";
            default:                return "none";
        }
    }

    inline bool operator==(const std::string& str, const Mode mode)
    {
        return to_string(mode) == str;
    }

    inline bool operator==(const Mode mode, const std::string& str)
    {
        return str == to_string(mode);
    }
}

#endif //RAINDROPS_MODE_HPP