//
// Created by golczewa on 29.09.2026.
//

#ifndef ISLAND_WITH_NO_NAME_TILEMAP_H
#define ISLAND_WITH_NO_NAME_TILEMAP_H
#include <string>
#include <vector>
#include "../tools/collisionWorld.h"
#include "raylib.h"

class TileMap {
    std::string sprite_path;
    Texture2D sprite;
    int tile_number;
    std::vector<int> map;
    std::vector<int> tile_cols;
    Rectangle tiles;
    std::vector<Collision> collisions;
public:
    TileMap(const std::string path,int number,std::vector<int> _map,std::vector<int> cols);
    ~TileMap();
    void draw();
    void add_tile_collision(Collision collision);
    [[nodiscard]] std::vector<int>& get_map();
    [[nodiscard]] std::vector<int>& get_cols();
};


#endif //ISLAND_WITH_NO_NAME_TILEMAP_H
