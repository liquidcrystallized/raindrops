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
        src/state/State.cpp
        src/state/StateMachine.cpp
        src/Application.cpp
)

add_executable(raindrops
        ${RAINDROPS_HEADERS}
        ${RAINDROPS_SOURCES}
        src/main.cpp
)

include_directories(raindrops PRIVATE include)

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

include_directories(raindrops_tests PRIVATE include)

#---------------------------------------------------------------------------------------
# Dependencies from vcpkg
#---------------------------------------------------------------------------------------
# Raylib
find_package(raylib CONFIG REQUIRED)
target_link_libraries(raindrops PRIVATE raylib)
target_link_libraries(raindrops_tests PRIVATE raylib)

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
