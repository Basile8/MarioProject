cmake_minimum_required(VERSION 3.6)
project(MarioProject)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets CONFIG REQUIRED)

file (GLOB_RECURSE CIR2_mario src/*.cpp src/*.h src/*.txt)

add_executable(MarioProject ${CIR2_mario})

target_link_libraries(MarioProject Qt5::Widgets)