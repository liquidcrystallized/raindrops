#ifndef RAINDROPS_CONFIGMANAGER_HPP
#define RAINDROPS_CONFIGMANAGER_HPP

#include "ApplicationConfig.hpp"

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
    };
}

#endif //RAINDROPS_CONFIGMANAGER_HPP