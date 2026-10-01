//
// Created by golczewa on 1.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_ROOM_H
#define ISLAND_WITH_NO_NAME_ROOM_H
#include "maps.h"
#include "tileMap.h"


class Room {
    std::unique_ptr<TileMap> tile_map;
    std::vector<std::unique_ptr<Prop>> props;
public:
    Room(MapData map_data);
    void draw();
};


#endif //ISLAND_WITH_NO_NAME_ROOM_H