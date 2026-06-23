#include "ConfigManager.hpp"
#include <doctest.h>

TEST_SUITE_BEGIN("ConfigManager");

TEST_CASE("ConfigManager is a singleton (two instances have the same address)")
{
    auto& instance1 = raindrops::ConfigManager::getInstance();
    auto& instance2 = raindrops::ConfigManager::getInstance();

    CHECK( &instance1 == &instance2 );
}

TEST_SUITE_END;