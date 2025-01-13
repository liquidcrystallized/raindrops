cmake_minimum_required(VERSION 3.28)
project(raindrops)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(raindrops src/main.cpp)

target_include_directories(raindrops PRIVATE
        ${PROJECT_SOURCE_DIR}/external/SFML)