#ifndef RAINDROPS_CONFIGMANAGER_HPP
#define RAINDROPS_CONFIGMANAGER_HPP

#include "ApplicationConfig.hpp"
#include <filesystem>

namespace raindrops
{
    /**
     * @brief Manages loading, saving and accessing application configuration.
     * Implemented as a singleton.
     */
    class ConfigManager {
    public:
        ConfigManager(const ConfigManager&) = delete;
        ConfigManager& operator=(const ConfigManager&) = delete;
        ConfigManager(ConfigManager&&) = delete;
        ConfigManager& operator=(ConfigManager&&) = delete;

        static ConfigManager& getInstance();

        [[nodiscard]] const ApplicationConfig& getConfig() const;
        void setConfig(const ApplicationConfig& config);

        void resetToDefaults();

    private:
        ApplicationConfig m_config;

        ConfigManager() = default;

        static bool ensureDirectoryExists(const std::filesystem::path& filePath);
        bool parseConfigFile(const std::filesystem::path& filePath);
        [[nodiscard]] bool serializeConfigFile(const std::filesystem::path& filePath) const;
    };
}

#endif //RAINDROPS_CONFIGMANAGER_HPP