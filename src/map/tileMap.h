//
// Created by golczewa on 29.09.2026.
//

#ifndef ISLAND_WITH_NO_NAME_TILEMAP_H
#define ISLAND_WITH_NO_NAME_TILEMAP_H
#include <string>
#include <vector>

#include "raylib.h"

class TileMap {
    std::string sprite_path;
    Texture2D sprite;
    int tile_number;
    std::vector<int> map;
    Rectangle tiles;
public:
    TileMap(const std::string path,int number,std::vector<int> _map);
    ~TileMap();
    void draw();
};


#endif //ISLAND_WITH_NO_NAME_TILEMAP_H
