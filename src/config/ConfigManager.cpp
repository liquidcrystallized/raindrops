#include "ConfigManager.hpp"
#include "DefaultConfigFactory.hpp"
#include <glaze/json.hpp>
#include <fstream>
#include <print>

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

    bool ConfigManager::loadFromFile(const std::filesystem::path& filePath)
    {
        std::println("Attempting to load config from: {}", filePath.string());

        if (parseConfigFile(filePath))
        {
            std::println("Config loaded successfully.");
            return true;
        }

        std::println("Failed to load config.");
        resetToDefaults();
        return false;
    }

    bool ConfigManager::saveToFile(const std::filesystem::path& filePath) const
    {
        std::println("Saving config to: {}", filePath.string());

        if (ensureDirectoryExists(filePath))
        {
            if (serializeConfigFile(filePath))
            {
                std::println("Config successfully saved.");
                return true;
            }

            std::println("Failed to save config.");
            return false;
        }

        std::println("Failed to create directory for: {}", filePath.string());
        return false;
    }

    bool ConfigManager::loadFromDefaultLocation()
    {
        const std::filesystem::path defaultPath = getDefaultConfigPath();
        return loadFromFile(defaultPath);
    }

    bool ConfigManager::saveToDefaultLocation() const
    {
        const std::filesystem::path defaultPath = getDefaultConfigPath();
        return saveToFile(defaultPath);
    }

    void ConfigManager::resetToDefaults()
    {
        m_config = DefaultConfigFactory::create();
    }

    bool ConfigManager::ensureDirectoryExists(const std::filesystem::path& filePath)
    {
        const std::filesystem::path directory = std::filesystem::path(filePath).parent_path();

        try
        {
            std::filesystem::create_directories(directory);
            return true;
        }
        catch (const std::filesystem::filesystem_error& error)
        {
            std::println("Failed to ensure directory exists: {}", error.what());
            return false;
        }
    }

    bool ConfigManager::parseConfigFile(const std::filesystem::path& filePath)
    {
        std::ifstream file(filePath);
        if (!file.is_open())
        {
            std::println("Could not open file for parsing: {}", filePath.string());
            return false;
        }

        auto buffer = std::string(std::istreambuf_iterator(file), {});
        file.close();

        auto deserializedConfig = glz::read_json<ApplicationConfig>(buffer);
        m_config = deserializedConfig.value();

        return true;
    }

    bool ConfigManager::serializeConfigFile(const std::filesystem::path& filePath) const
    {
        std::ofstream file(filePath);
        if (!file.is_open())
        {
            std::println("Could not open file for writing: {}", filePath.string());
            return false;
        }

        const std::string buffer = glz::write_json(m_config).value_or("error");

        file << buffer;
        file.close();
        return true;
    }

    std::filesystem::path ConfigManager::getDefaultConfigPath()
    {
        std::filesystem::path platformSpecificUserApplicationConfigDirectory;
        const std::filesystem::path applicationConfigSubdirectory { "liquidcrystallized/raindrops/config.json" };

#if defined(_WIN32)
        const char* appDataPath = std::getenv("APPDATA");
        if (appDataPath)
        {
            platformSpecificUserApplicationConfigDirectory = std::filesystem::path(appDataPath) / applicationConfigSubdirectory;
        }
        else
        {
            std::cout << "Appdata doesn't exist\n";
        }
#elif defined(__linux__)
        const char* xdgConfigHomePath = std::getenv("XDG_CONFIG_HOME");
        if (xdgConfigHomePath)
        {
            platformSpecificUserApplicationConfigDirectory = std::filesystem::path(xdgConfigHomePath) / applicationConfigSubdirectory;
        }
        else
        {
            std::println("XDG_CONFIG_HOME environment variable not set.");
        }
#else
        std::cout << "getDefaultConfigPath() unsupported platform.\n";
#endif

        return platformSpecificUserApplicationConfigDirectory;
    }
}
