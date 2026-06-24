#ifndef RAINDROPS_DEFAULTCONFIGFACTORY_HPP
#define RAINDROPS_DEFAULTCONFIGFACTORY_HPP

#include "ApplicationConfig.hpp"

namespace raindrops
{
    /**
     * @brief Provides a single place to set some defaults for a newly created configs.
     */
    class DefaultConfigFactory {
    public:
        static ApplicationConfig create();
    };
}

#endif //RAINDROPS_DEFAULTCONFIGFACTORY_HPP