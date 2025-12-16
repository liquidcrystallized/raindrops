#include "MxReader.hpp"
#include <iostream>

namespace raindrops
{
    MxReader::MxReader()
    : m_documentManager { mx::api::DocumentManager::getInstance() }
    {
        std::cout << "MxReader constructed.\n";
    }

    MxReader::~MxReader()
    {
        std::cout << "MxReader destructed.\n";
    }

    bool MxReader::tryLoadFileIntoStream(const std::string& filePath)
    {
        std::ifstream fileStream { filePath };

        if (!fileStream)
        {
            std::cerr << "Failed to open file " << filePath << '\n';
            fileStream.close();
            return false;
        }

        std::string line {};
        while (getline(fileStream, line))
        {
            m_fileContents.append(line);
        }

        fileStream.close();
        return true;
    }

    bool MxReader::tryParseFileInputStream(std::istream& inputStream)
    {
        try
        {
            const int documentID = m_documentManager.createFromStream(inputStream);
            m_scoreData = m_documentManager.getData(documentID);
            m_documentManager.destroyDocument(documentID);
        }
        catch (std::runtime_error& error)
        {
            std::cout << error.what() << '\n';
        }

        if (m_scoreData.parts.size() != 1)
        {
            return false;
        }

        return true;
    }

    std::string MxReader::getRawFileContents() const
    {
        if (m_fileContents.empty())
        {
            return {};
        }

        return m_fileContents;
    }

    std::string MxReader::getMusicXmlVersion() const
    {
        return {};
    }
}