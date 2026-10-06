//
// Created by golczewa on 6.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_GAME_H
#define ISLAND_WITH_NO_NAME_GAME_H
#include <memory>

#include "../map/room.h"
#include "../map/maps.h"

class Player;

class Game {
    MapLibrary map_library;
    std::unique_ptr<Player> player;
    MapData get_map(int room_id);
public:
    std::unique_ptr<Room> curr_room;
    Game();
    ~Game();
    void process();
    void draw();
    void change_room(int room_id);
};


#endif //ISLAND_WITH_NO_NAME_GAME_H
