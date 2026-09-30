//
// Created by golczewa on 29.09.2026.
//

#ifndef ISLAND_WITH_NO_NAME_TILEMAP_H
#define ISLAND_WITH_NO_NAME_TILEMAP_H
#include <string>

#include "raylib.h"

class TileMap {
    std::string sprite_path;
    Texture2D sprite=LoadTexture(sprite_path.c_str());
    int tile_number;
    Rectangle tiles={0,0,static_cast<float>(sprite.width)/tile_number,static_cast<float>(sprite.height)};
public:
    TileMap(const std::string& path,int number);

};


#endif //ISLAND_WITH_NO_NAME_TILEMAP_H
