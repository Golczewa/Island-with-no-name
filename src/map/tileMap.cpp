//
// Created by golczewa on 29.09.2026.
//

#include "tileMap.h"

#include <iostream>
#include <stdexcept>

TileMap::TileMap(const std::string& path,int number,std::vector<int>& _map)
    :sprite_path(path),tile_number(number),map(_map) {
    sprite=LoadTexture(sprite_path.c_str());
    tiles={0,0,static_cast<float>(sprite.width)/tile_number,static_cast<float>(sprite.height)};
}

TileMap::~TileMap() {
    UnloadTexture(sprite);
}

void TileMap::draw() {
    if (map.size()==192) {
        Vector2 tile_pos={0,0};
        for (int i=0;i<map.size();i++) {
            if (map[i]>=tile_number) {
                throw std::invalid_argument("invalid map - unknown tile");
            }
            tiles.x=static_cast<float>(map[i])*static_cast<float>(sprite.width)/tile_number;
            DrawTextureRec(sprite,tiles,tile_pos,WHITE);
            tile_pos.x+=16;
            if (tile_pos.x==256 and i!=0) {
                tile_pos.x=0;
                tile_pos.y+=16;
            }
        }
    }else {
        throw std::invalid_argument("invalid map - map must have 192 tiles");
    }
}
