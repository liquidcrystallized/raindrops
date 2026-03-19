#ifndef RAINDROPS_IMUSICXMLREADER_HPP
#define RAINDROPS_IMUSICXMLREADER_HPP

#include <string>

namespace raindrops
{
    class IMusicXmlReader {
    public:
        virtual ~IMusicXmlReader() = default;

        [[nodiscard]] virtual bool tryLoadFileIntoStream(const std::string& filePath) = 0;

        /**
         * Make sure the input from a file we're reading contains music xml content.
         * @param inputStream Stream of file contents, a string or something.
         * @return true if contents are music xml, false if not.
         */
        [[nodiscard]] virtual bool tryParseFileInputStream(std::istream& inputStream) = 0;

        [[nodiscard]] virtual std::string getRawFileContents() const = 0;

        [[nodiscard]] virtual std::string getMusicXmlVersion() const = 0;

        [[nodiscard]] virtual std::string getMusicComposer() const = 0;

        [[nodiscard]] virtual std::string getMusicTitle() const = 0;
    };
}

#endif //RAINDROPS_IMUSICXMLREADER_HPP