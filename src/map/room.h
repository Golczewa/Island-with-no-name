//
// Created by golczewa on 1.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_ROOM_H
#define ISLAND_WITH_NO_NAME_ROOM_H
#include "maps.h"
#include "tileMap.h"
#include "../enemies/enemy.h"
#include "../enemies/enemyFactory.h"


class Room {
    int id;
    std::unique_ptr<TileMap> tile_map;
    std::vector<std::unique_ptr<Prop>> props;
    std::vector<std::unique_ptr<Enemy>> enemies;

public:
    Paths paths;
    Room(const MapData& map_data);
    void draw();
    void process();
};


#endif //ISLAND_WITH_NO_NAME_ROOM_H