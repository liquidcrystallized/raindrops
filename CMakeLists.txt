cmake_minimum_required(VERSION 3.28)
project(raindrops)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include_directories(external/SFML/include)
add_subdirectory(external/SFML)

add_executable(raindrops src/main.cpp)

target_link_libraries(raindrops
    sfml-graphics
    sfml-system)