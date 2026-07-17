#include "MxReader.hpp"
#include <mx/core/Document.h>
#include <mx/core/elements/ScorePartwise.h>
#include <iostream>

namespace raindrops
{
    MxReader::MxReader() : m_documentManager { mx::api::DocumentManager::getInstance() } {}

    MxReader::~MxReader() = default;

    bool MxReader::tryLoadFileIntoStream(const std::string& filePath)
    {
        std::ifstream fileStream { filePath, std::ios::binary };

        if (!fileStream)
        {
            std::cerr << "Failed to open file " << filePath << '\n';
            fileStream.close();
            return false;
        }

        fileStream.seekg(0, std::ios::end);
        const std::streamsize fileSize = fileStream.tellg();
        fileStream.seekg(0, std::ios::beg);

        m_fileContents.resize(static_cast<size_t>(fileSize));
        fileStream.read(m_fileContents.data(), fileSize);
        fileStream.close();

        return true;
    }

    bool MxReader::tryParseFileInputStream(std::istream& inputStream)
    {
        try
        {
            const int documentID = m_documentManager.createFromStream(inputStream);

            m_scoreData = m_documentManager.getData(documentID); // for the easier mx::api.
            m_musicXmlVersion = m_documentManager                // mx::core shenanigans.
                .getDocument(documentID)
                ->getScorePartwise()
                ->getAttributes()
                ->version.getValue();

            m_documentManager.destroyDocument(documentID);
        }
        catch (std::runtime_error& error)
        {
            std::cout << error.what() << '\n';
            return false;
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
        if (m_musicXmlVersion.empty())
        {
            return {};
        }

        return m_musicXmlVersion;
    }

    int MxReader::getNumberOfMeasures() const
    {
        return m_scoreData.getNumMeasures();
    }

    std::vector<Measure> MxReader::getMeasures() const
    {
        mx::api::PartData pianoPart {};
        for (const mx::api::PartData& partData : m_scoreData.parts)
        {
            if (partData.name == "Piano")
            {
                pianoPart = partData;
                break;
            }
        }

        if (pianoPart.name.empty() || pianoPart.measures.empty())
        {
            return {};
        }

        std::vector<Measure> measures;
        for (size_t i = 0; i < pianoPart.measures.size(); i++)
        {
            Measure measure;
            measure.setMeasureNumber(i);
            measures.push_back(measure);
        }

        return measures;
    }

    int MxReader::getNumberOfParts() const
    {
        return m_scoreData.parts.size();
    }

    std::string MxReader::getSongComposer() const
    {
        return m_scoreData.composer;
    }

    std::string MxReader::getSongTitle() const
    {
        return m_scoreData.workTitle;
    }
}
