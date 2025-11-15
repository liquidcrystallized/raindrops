#ifndef RAINDROPS_RAYGUI_DEFGUARD_HPP
#define RAINDROPS_RAYGUI_DEFGUARD_HPP

/**
 * @brief This file solves a funky bug(?) with raygui/raygui-cpp
 * where the includes would throw multiple linker errors due to
 * being included multiple times somehow. This just has to go in
 * any random cpp file.
 */
#define RAYGUI_IMPLEMENTATION
#include <raygui-cpp.h>

#endif //RAINDROPS_RAYGUI_DEFGUARD_HPP