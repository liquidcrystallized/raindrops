#include "ConfigManager.hpp"
#include "DefaultConfigFactory.hpp"
#include <glaze/json.hpp>
#include <filesystem>
#include <fstream>
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

    bool ConfigManager::parseConfigFile(const std::string& filePath)
    {
        std::ifstream file(filePath);
        if (!file.is_open())
        {
            std::cerr << "Could not open file for parsing: " << filePath << '\n';
            return false;
        }

        auto buffer = std::string(std::istreambuf_iterator(file), {});
        file.close();

        auto deserializedConfig = glz::read_json<ApplicationConfig>(buffer);
        m_config = deserializedConfig.value();

        return true;
    }

    bool ConfigManager::serializeConfigFile(const std::string& filePath) const
    {
        std::ofstream file(filePath);
        if (!file.is_open())
        {
            std::cerr << "Could not open file for writing: " << filePath << '\n';
            return false;
        }

        const std::string buffer = glz::write_json(m_config).value_or("error");

        file << buffer;
        file.close();
        return true;
    }
}
