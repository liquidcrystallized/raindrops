cmake_minimum_required(VERSION 3.28)
project(raindrops LANGUAGES CXX)

set(CMAKE_VERBOSE_MAKEFILE on)

# Disable compiler extensions for portability
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include_directories(external/SFML/include)
add_subdirectory(external/SFML)

# Build an executable called "raindrops"
add_executable(raindrops src/main.cpp
        src/ScreenManager.hpp
        src/ScreenManager.cpp
        src/Screen.hpp
        src/Screen.cpp
        src/Application.hpp
        src/Application.cpp
        src/IntroScreen.hpp
        src/IntroScreen.cpp
)

# Link dependencies
target_link_libraries(raindrops
    sfml-graphics
    sfml-system)