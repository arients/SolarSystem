cmake_minimum_required(VERSION 3.28)
project(SolarSystem)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(SolarSystem main.cpp ${SOURCES})

target_link_libraries(SolarSystem sfml-graphics sfml-window sfml-system)