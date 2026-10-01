//
// Created by golczewa on 1.10.2026.
//

#include "room.h"

Room::Room(MapData map_data) {
    tile_map=std::make_unique<TileMap>(map_data.tiles_path,map_data.tile_number ,map_data.tiles);
    for (auto& prop: map_data.props) {
        props.push_back(std::make_unique<Prop>(prop.first,prop.second));
    }
}

void Room::draw() {
    tile_map->draw();
    for (auto& prop :props) {
        prop->draw();
    }
}
