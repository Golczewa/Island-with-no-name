cmake_minimum_required(VERSION 4.3)
project(island_with_no_name)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG master
)

FetchContent_MakeAvailable(raylib)

add_executable(island_with_no_name src/main.cpp
        src/player.cpp
        src/player.h
        src/tools/animation.h
)

target_link_libraries(island_with_no_name
        raylib
)
