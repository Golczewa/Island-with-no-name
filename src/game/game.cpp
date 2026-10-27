//
// Created by golczewa on 6.10.2026.
//

#include "game.h"
#include "player.h"

Game::Game()
    : player(std::make_unique<Player>(this)){
    game_ui_=std::make_unique<GameUI>(player.get());
    change_room(1);
}

Game::~Game() = default;

void Game::process() {
    player->process();
    curr_room->process();
    game_ui_->process();
}

void Game::draw() {
    curr_room->draw();
    player->draw();
    game_ui_->draw();
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
    if (curr_room) {
        curr_room->cleanup();
    }
    auto it = visited.find(room_id);
    if (it == visited.end()) {
        it = visited.emplace(room_id,
                std::make_unique<Room>(get_map(room_id), player.get())).first;
    }
    curr_room = it->second.get();
    curr_room->register_collisions();
}

