cmake_minimum_required(VERSION 3.28)
project(raindrops LANGUAGES CXX)

set(CMAKE_VERBOSE_MAKEFILE on)

#---------------------------------------------------------------------------------------
# Disable compiler extensions for portability
#---------------------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

#---------------------------------------------------------------------------------------
# raindrops application
#---------------------------------------------------------------------------------------
set(RAINDROPS_SOURCES
        src/midi/IMidiInputListener.hpp
        src/midi/MidiDevice.hpp
        src/midi/MidiDevice.cpp
        src/midi/MidiMessageList.hpp
        src/midi/MidiMonitor.hpp
        src/midi/MidiMonitor.cpp
        src/midi/MidiReceiver.hpp
        src/midi/MidiReceiver.cpp
        src/Application.hpp
        src/Application.cpp
)

add_executable(raindrops
        ${RAINDROPS_SOURCES}
        src/main.cpp
)

#---------------------------------------------------------------------------------------
# raindrops tests
#---------------------------------------------------------------------------------------
set(RAINDROPS_TESTS_SOURCES
        tests/unit_tests/midi/MidiDeviceTests.cpp
        tests/unit_tests/midi/MidiMonitorTests.cpp
)

add_executable(raindrops_tests
        ${RAINDROPS_SOURCES}
        ${RAINDROPS_TESTS_SOURCES}
        tests/TestMain.cpp
)

#---------------------------------------------------------------------------------------
# Dependencies from vcpkg
#---------------------------------------------------------------------------------------
# SFML
find_package(SFML COMPONENTS Graphics Window Audio System CONFIG REQUIRED)
target_link_libraries(raindrops PRIVATE SFML::Graphics SFML::Window SFML::Audio SFML::System)
target_link_libraries(raindrops_tests PRIVATE SFML::Graphics SFML::Window SFML::Audio SFML::System)

# Doctest
find_package(doctest CONFIG REQUIRED)
target_link_libraries(raindrops_tests PRIVATE doctest::doctest)

# rtmidi
find_package(rtmidi CONFIG REQUIRED)
target_link_libraries(raindrops PRIVATE RtMidi::rtmidi)
target_link_libraries(raindrops_tests PRIVATE RtMidi::rtmidi)

#---------------------------------------------------------------------------------------
# Build flags
#---------------------------------------------------------------------------------------
target_compile_options(raindrops PRIVATE
        -Wall
        -Wextra
        -Wsign-conversion
        -Wpedantic
        #-Werror
)
