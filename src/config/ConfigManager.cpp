#include "ConfigManager.hpp"
#include "DefaultConfigFactory.hpp"

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
}
