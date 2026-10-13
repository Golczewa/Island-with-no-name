//
// Created by golczewa on 1.10.2026.
//

#include "room.h"

#include <cmath>

Room::Room(const MapData& map_data,Player* player) {
    tile_map=std::make_unique<TileMap>(map_data.tiles_path,map_data.tile_number ,map_data.tiles);
    for (auto& prop: map_data.props) {
        props.push_back(std::make_unique<Prop>(prop.first,prop.second));
    }
    for (auto& enemy:map_data.enemies) {
        enemies.push_back(EnemyFactory::create_enemy(enemy.first,enemy.second,player,get_navigation_path()));
    }
    id=map_data.id;
    paths=map_data.paths;
}

void Room::draw() {
    tile_map->draw();
    for (auto& prop :props) {
        prop->draw();
    }
    for (auto& enemy:enemies) {
        enemy->draw();
    }
}

void Room::process() {
    for (auto& enemy:enemies) {
        enemy->process();
    }
}

std::vector<int> Room::get_navigation_path() const {
    std::vector<int> map(16*12);
    for (auto& prop:props) {
        auto pos=prop->get_position();
        int cx=std::floor(pos.x/16);
        int cy=std::floor(pos.y/16);
        const int offsets[5][2]={{0,0},{-1,0},{1,0},{0,-1},{0,1}};
        for (auto& o:offsets) {
            int x=cx+o[0];
            int y=cy+o[1];
            if (x<0||x>=16||y<0||y>=12) continue;
            map[x+y*16]=1;
        }
    }
    return map;
}
