#ifndef RAINDROPS_IMUSICXMLREADER_HPP
#define RAINDROPS_IMUSICXMLREADER_HPP

#include <string>

namespace raindrops
{
    class IMusicXmlReader {
    public:
        virtual ~IMusicXmlReader() = default;

        virtual bool tryLoadFileIntoStream(const std::string& filePath) = 0;

        /**
         * Make sure the input from a file we're reading contains music xml content.
         * @param inputStream Stream of file contents, a string or something.
         * @return true if contents are music xml, false if not.
         */
        virtual bool tryParseFileInputStream(std::istream& inputStream) = 0;

        [[nodiscard]] virtual std::string getRawFileContents() const = 0;

        [[nodiscard]] virtual std::string getMusicXmlVersion() const = 0;

        /**
         * Number of parts, or instruments in a musical score. Basically the lines where
         * the clefs are positioned, typically with around 5 stave lines. Part can potentially have
         * more of these, separating the treble and bass.
         * @return Number of "playable" parts.
         */
        [[nodiscard]] virtual int getNumberOfParts() const = 0;

        [[nodiscard]] virtual std::string getSongComposer() const = 0;

        [[nodiscard]] virtual std::string getSongTitle() const = 0;
    };
}

#endif //RAINDROPS_IMUSICXMLREADER_HPP