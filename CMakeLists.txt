cmake_minimum_required(VERSION 4.3)
project(island_with_no_name)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

include(FetchContent)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG master
)

FetchContent_MakeAvailable(raylib)

add_executable(island_with_no_name src/main.cpp
        src/game/player.cpp
        src/game/player.h
        src/tools/animation.h
        src/tools/animation.cpp
        src/map/tileMap.cpp
        src/map/tileMap.h
        src/map/maps.h
        src/map/room.cpp
        src/map/room.h
        src/map/prop.cpp
        src/map/prop.h
        src/tools/collisionWorld.cpp
        src/tools/collisionWorld.h
        src/game/game.cpp
        src/game/game.h
        src/enemies/enemy.cpp
        src/enemies/enemy.h
        src/enemies/testEnemy.cpp
        src/enemies/testEnemy.h
        src/enemies/enemyFactory.cpp
        src/enemies/enemyFactory.h
        src/tools/vectorTools.cpp
        src/tools/vectorTools.h
        src/tools/body.h
        src/tools/timer.cpp
        src/tools/timer.h
        src/bullets/bullet.cpp
        src/bullets/bullet.h
        src/tools/navigationAgent.cpp
        src/tools/navigationAgent.h
        src/bullets/defaultBullet.cpp
        src/bullets/defaultBullet.h
        src/enemies/creature.cpp
        src/enemies/creature.h
        src/game/gameUI.cpp
        src/game/gameUI.h
        src/map/heal.cpp
        src/map/heal.h
)

target_link_libraries(island_with_no_name
        raylib
)
