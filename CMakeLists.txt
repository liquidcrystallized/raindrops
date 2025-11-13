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

#---------------------------------------------------------------------------------------
# external includes
#---------------------------------------------------------------------------------------
include_directories(external/raylib/src)
include_directories(external/raylib-cpp/include)
include_directories(external/doctest/doctest)
include_directories(external/rtmidi)
include_directories(external/raygui/src)
add_subdirectory(external/raylib)
add_subdirectory(external/raylib-cpp)
add_subdirectory(external/doctest)
add_subdirectory(external/rtmidi)

#---------------------------------------------------------------------------------------
# raindrops application
#---------------------------------------------------------------------------------------
set(RAINDROPS_HEADERS
        include/raindrops/midi/IMidiInputListener.hpp
        include/raindrops/midi/MidiDevice.hpp
        include/raindrops/midi/MidiMessageList.hpp
        include/raindrops/midi/MidiMonitor.hpp
        include/raindrops/midi/MidiReceiver.hpp
        include/raindrops/state/MainMenuState.hpp
        include/raindrops/state/PlayingState.hpp
        include/raindrops/state/SettingsMenuState.hpp
        include/raindrops/state/State.hpp
        include/raindrops/state/StateMachine.hpp
        include/raindrops/Application.hpp
)
set(RAINDROPS_SOURCES
        src/midi/MidiDevice.cpp
        src/midi/MidiMonitor.cpp
        src/midi/MidiReceiver.cpp
        src/state/MainMenuState.cpp
        src/state/PlayingState.cpp
        src/state/SettingsMenuState.cpp
        src/state/State.cpp
        src/state/StateMachine.cpp
        src/Application.cpp
)

add_executable(raindrops
        ${RAINDROPS_HEADERS}
        ${RAINDROPS_SOURCES}
        src/main.cpp
)

target_include_directories(raindrops PRIVATE
        include/raindrops/midi
        include/raindrops/state
        include/raindrops
)

#---------------------------------------------------------------------------------------
# raindrops tests
#---------------------------------------------------------------------------------------
set(RAINDROPS_TESTS_SOURCES
        tests/unit_tests/midi/MidiDeviceTests.cpp
        tests/unit_tests/midi/MidiMonitorTests.cpp
        tests/unit_tests/midi/MidiReceiverTests.cpp
        tests/unit_tests/state/StateMachineTests.cpp
)

add_executable(raindrops_tests
        ${RAINDROPS_HEADERS}
        ${RAINDROPS_SOURCES}
        ${RAINDROPS_TESTS_SOURCES}
        tests/TestMain.cpp
)

target_include_directories(raindrops_tests PRIVATE
        include/raindrops/midi
        include/raindrops/state
        include/raindrops
)

#---------------------------------------------------------------------------------------
# Dependencies
#---------------------------------------------------------------------------------------
# Raylib
target_link_libraries(raindrops PRIVATE raylib)
target_link_libraries(raindrops_tests PRIVATE raylib)

# Doctest
target_link_libraries(raindrops_tests PRIVATE doctest::doctest)

# rtmidi
target_link_libraries(raindrops PRIVATE rtmidi)
target_link_libraries(raindrops_tests PRIVATE rtmidi)

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
