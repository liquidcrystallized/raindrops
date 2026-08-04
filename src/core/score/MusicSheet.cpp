#include "MusicSheet.hpp"

namespace raindrops
{
    MusicSheet::MusicSheet()
    {
        m_hasBPMInfo = false;
    }

    std::string MusicSheet::getFilePath()
    {
        if (m_filePath.empty())
        {
            return {};
        }

        return m_filePath;
    }

    void MusicSheet::setFilePath(const std::string& filePath)
    {
        m_filePath = filePath;
    }

    std::string MusicSheet::getTitle()
    {
        if (m_title.empty())
        {
            return {};
        }

        return m_title;
    }

    void MusicSheet::setTitle(const std::string& title)
    {
        m_title = title;
    }

    std::string MusicSheet::getSubTitle()
    {
        if (m_subTitle.empty())
        {
            return {};
        }

        return m_subTitle;
    }

    void MusicSheet::setSubTitle(const std::string& subTitle)
    {
        m_subTitle = subTitle;
    }

    std::string MusicSheet::getComposer()
    {
        if (m_composer.empty())
        {
            return {};
        }

        return m_composer;
    }

    void MusicSheet::setComposer(const std::string& composer)
    {
        m_composer = composer;
    }

    bool MusicSheet::getHasBPMInfo() const
    {
        return m_hasBPMInfo;
    }

    void MusicSheet::setHasBPMInfo(const bool hasBPMInfo)
    {
        m_hasBPMInfo = hasBPMInfo;
    }

    int MusicSheet::getMeasureCount() const
    {
        return static_cast<int>(m_measures.size());
    }

    const std::vector<Measure>& MusicSheet::getMeasures() const
    {
        return m_measures;
    }

    void MusicSheet::addMeasure(const Measure& measure)
    {
        m_measures.push_back(measure);
    }
}
