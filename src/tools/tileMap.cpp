//
// Created by golczewa on 29.09.2026.
//

#include "tileMap.h"

#include <iostream>
#include <stdexcept>

TileMap::TileMap(const std::string& path,int number,std::vector<int>& _map)
    :sprite_path(path),tile_number(number),map(_map){}

void TileMap::draw() {
    if (map.size()==192) {
        Vector2 tile_pos={0,0};
        for (int i=0;i<map.size();i++) {
            if (map[i]>=tile_number) {
                throw std::invalid_argument("invalid map");
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
        throw std::invalid_argument("invalid map");
    }
}
