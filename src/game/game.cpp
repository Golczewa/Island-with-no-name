//
// Created by golczewa on 6.10.2026.
//

#include "game.h"
#include "player.h"

Game::Game()
    : player(std::make_unique<Player>(this)),
      curr_room(std::make_unique<Room>(map_library.map1)) {}

Game::~Game() = default;

void Game::process() {
    player->process();
}

void Game::draw() {
    curr_room->draw();
    player->draw();
}

MapData Game::get_map(int room_id) {
    for (auto& map:map_library.maps) {
        if (room_id==map.id) {
            return map;
        }
    }
    throw std::invalid_argument("Unknown room id");
}

void Game::change_room(int room_id) {
    if (room_id==-1) {
        return;
    }
    curr_room=std::make_unique<Room>(get_map(room_id));
}

