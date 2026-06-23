cmake_minimum_required(VERSION 3.25.1)
project(raindrops LANGUAGES CXX)

set(CMAKE_VERBOSE_MAKEFILE on)

#---------------------------------------------------------------------------------------
# Disable compiler extensions for portability
#---------------------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 23)
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
#include_directories(external/raygui/src)
include_directories(external/raygui-cpp/include)
include_directories(external/mx/Sourcecode/include)
include_directories(external/mx/Sourcecode/private/)
include_directories(external/glaze/include/)
#add_subdirectory(external/raylib)
add_subdirectory(external/raylib-cpp)
add_subdirectory(external/doctest)
add_subdirectory(external/rtmidi)
add_subdirectory(external/raygui-cpp)
add_subdirectory(external/mx)
add_subdirectory(external/glaze)

#---------------------------------------------------------------------------------------
# raindrops application
#---------------------------------------------------------------------------------------
set(RAINDROPS_HEADERS
        include/raindrops/config/ApplicationConfig.hpp
        include/raindrops/config/ConfigManager.hpp
        include/raindrops/config/MidiConfig.hpp
        include/raindrops/config/MusicSheetDisplayConfig.hpp
        include/raindrops/config/WindowConfig.hpp
        include/raindrops/core/file/musicxml/mx/MxReader.hpp
        include/raindrops/core/file/musicxml/IMusicXmlReader.hpp
        include/raindrops/core/file/musicxml/MusicXmlReader.hpp
        include/raindrops/core/math/Vector2.hpp
        include/raindrops/core/score/Measure.hpp
        include/raindrops/core/score/Mode.hpp
        include/raindrops/core/score/MusicSheet.hpp
        include/raindrops/core/score/ScoreFactory.hpp
        include/raindrops/core/score/Staff.hpp
        include/raindrops/core/score/StaffLine.hpp
        include/raindrops/midi/IMidiInputListener.hpp
        include/raindrops/midi/MidiDevice.hpp
        include/raindrops/midi/MidiMessageList.hpp
        include/raindrops/midi/MidiMonitor.hpp
        include/raindrops/midi/MidiReceiver.hpp
        include/raindrops/render/controls/VerticalStackPanel.hpp
        include/raindrops/render/graphics/null/GraphicsNull.hpp
        include/raindrops/render/graphics/raylib/GraphicsRaylib.hpp
        include/raindrops/render/graphics/Colour.hpp
        include/raindrops/render/IGraphics.hpp
        include/raindrops/state/MainMenuState.hpp
        include/raindrops/state/MidiSetupMenuState.hpp
        include/raindrops/state/PlayingState.hpp
        include/raindrops/state/SettingsMenuState.hpp
        include/raindrops/state/SongSelectionState.hpp
        include/raindrops/state/State.hpp
        include/raindrops/state/StateMachine.hpp
        include/raindrops/Application.hpp
        include/raindrops/raygui-defguard.hpp
)
set(RAINDROPS_SOURCES
        src/config/ApplicationConfig.cpp
        src/config/ConfigManager.cpp
        src/core/file/musicxml/mx/MxReader.cpp
        src/core/file/musicxml/MusicXmlReader.cpp
        src/core/math/Vector2.cpp
        src/core/score/Measure.cpp
        src/core/score/MusicSheet.cpp
        src/core/score/ScoreFactory.cpp
        src/core/score/Staff.cpp
        src/core/score/StaffLine.cpp
        src/midi/MidiDevice.cpp
        src/midi/MidiMonitor.cpp
        src/midi/MidiReceiver.cpp
        src/render/controls/VerticalStackPanel.cpp
        src/render/graphics/null/GraphicsNull.cpp
        src/render/graphics/raylib/GraphicsRaylib.cpp
        src/state/MainMenuState.cpp
        src/state/MidiSetupMenuState.cpp
        src/state/PlayingState.cpp
        src/state/SettingsMenuState.cpp
        src/state/SongSelectionState.cpp
        src/state/State.cpp
        src/state/StateMachine.cpp
        src/Application.cpp
)

set(RAINDROPS_INCLUDE_DIRECTORIES
        include/raindrops/config
        include/raindrops/core/file/musicxml/mx
        include/raindrops/core/file/musicxml
        include/raindrops/core/math
        include/raindrops/core/score
        include/raindrops/midi
        include/raindrops/render/controls
        include/raindrops/render/graphics
        include/raindrops/render/graphics/null
        include/raindrops/render/graphics/raylib
        include/raindrops/render
        include/raindrops/state
        include/raindrops
        include/tests
)

add_executable(raindrops
        ${RAINDROPS_HEADERS}
        ${RAINDROPS_SOURCES}
        src/main.cpp
)

target_include_directories(raindrops PRIVATE
        ${RAINDROPS_INCLUDE_DIRECTORIES}
)

#---------------------------------------------------------------------------------------
# raindrops tests
#---------------------------------------------------------------------------------------
set(RAINDROPS_INTEGRATION_TESTS_SOURCES
        tests/integration_tests/core/file/musicxml/MusicXmlReaderIntegrationTests.cpp
)

set(RAINDROPS_UNIT_TESTS_SOURCES
        tests/unit_tests/config/ApplicationConfigTests.cpp
        tests/unit_tests/config/ConfigManagerTests.cpp
        tests/unit_tests/config/MidiConfigTests.cpp
        tests/unit_tests/config/MusicSheetDisplayConfigTests.cpp
        tests/unit_tests/config/WindowConfigTests.cpp
        tests/unit_tests/core/file/musicxml/MusicXmlReaderTests.cpp
        tests/unit_tests/core/math/Vector2Tests.cpp
        tests/unit_tests/core/score/MeasureTests.cpp
        tests/unit_tests/core/score/ModeTests.cpp
        tests/unit_tests/core/score/MusicSheetTests.cpp
        tests/unit_tests/core/score/ScoreFactoryTests.cpp
        tests/unit_tests/core/score/StaffTests.cpp
        tests/unit_tests/core/score/StaffLineTests.cpp
        tests/unit_tests/midi/MidiDeviceTests.cpp
        tests/unit_tests/midi/MidiMonitorTests.cpp
        tests/unit_tests/midi/MidiReceiverTests.cpp
        tests/unit_tests/render/RendererTests.cpp
        tests/unit_tests/state/StateMachineTests.cpp
        tests/unit_tests/state/StateTests.cpp
)

add_executable(raindrops_tests
        ${RAINDROPS_HEADERS}
        ${RAINDROPS_SOURCES}
        ${RAINDROPS_INTEGRATION_TESTS_SOURCES}
        ${RAINDROPS_UNIT_TESTS_SOURCES}
        tests/TestMain.cpp
)

target_include_directories(raindrops_tests PRIVATE
        ${RAINDROPS_INCLUDE_DIRECTORIES}
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

# raygui-cpp
target_link_libraries(raindrops PRIVATE raygui_cpp)
target_link_libraries(raindrops_tests PRIVATE raygui_cpp)

# mx (music xml)
target_link_libraries(raindrops PRIVATE mx)
target_link_libraries(raindrops_tests PRIVATE mx)

# glaze
target_link_libraries(raindrops PRIVATE glaze::glaze)
target_link_libraries(raindrops_tests PRIVATE glaze::glaze)

# Suppress warnings from external
get_target_property(raygui_cpp_include_dirs raygui_cpp INTERFACE_INCLUDE_DIRECTORIES)
set_target_properties(raygui_cpp PROPERTIES INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "${raygui_cpp_include_dirs}")

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
