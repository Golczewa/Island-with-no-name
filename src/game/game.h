//
// Created by golczewa on 6.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_GAME_H
#define ISLAND_WITH_NO_NAME_GAME_H
#include <memory>
#include  <set>
#include "gameUI.h"
#include "../map/room.h"
#include "../map/maps.h"

class Player;

class Game {
    MapLibrary map_library;
    std::unique_ptr<Player> player;
    std::unique_ptr<GameUI> game_ui_;
    MapData get_map(int room_id);
    std::unordered_map<int, std::unique_ptr<Room>> visited;
public:
    Room* curr_room=nullptr;
    Game();
    ~Game();
    void process();
    void draw();
    void change_room(int room_id);
    void restart();
};


#endif //ISLAND_WITH_NO_NAME_GAME_H
