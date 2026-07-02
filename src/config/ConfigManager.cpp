#include "ConfigManager.hpp"
#include "DefaultConfigFactory.hpp"
#include <filesystem>
#include <iostream>

namespace raindrops
{
    ConfigManager& ConfigManager::getInstance()
    {
        static ConfigManager instance;
        return instance;
    }

    const ApplicationConfig& ConfigManager::getConfig() const
    {
        return m_config;
    }

    void ConfigManager::setConfig(const ApplicationConfig& config)
    {
        m_config = config;
    }

    void ConfigManager::resetToDefaults()
    {
        m_config = DefaultConfigFactory::create();
    }

    bool ConfigManager::ensureDirectoryExists(const std::string& filePath)
    {
        const std::filesystem::path directory = std::filesystem::path(filePath).parent_path();

        try
        {
            std::filesystem::create_directory(directory);
            return true;
        }
        catch (const std::filesystem::filesystem_error& e)
        {
            std::cerr << "Failed to ensure directory exists: " << e.what() << '\n';
            return false;
        }
    }
}
