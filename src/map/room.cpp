//
// Created by golczewa on 1.10.2026.
//

#include "room.h"

Room::Room(const MapData& map_data,Player* player) {
    tile_map=std::make_unique<TileMap>(map_data.tiles_path,map_data.tile_number ,map_data.tiles);
    for (auto& prop: map_data.props) {
        props.push_back(std::make_unique<Prop>(prop.first,prop.second));
    }
    for (auto& enemy:map_data.enemies) {
        enemies.push_back(EnemyFactory::create_enemy(enemy.first,enemy.second,player));
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
        map[pos.x*16+pos.y]=1;
    }
    return map;
}
