//
// Created by golczewa on 1.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_ROOM_H
#define ISLAND_WITH_NO_NAME_ROOM_H
#include <memory>
#include <vector>

#include "heal.h"
#include "maps.h"
#include "tileMap.h"

class Player;
class Enemy;
class Prop;
class Bullet;

class Room {
    int id;
    Player *player;
    std::unique_ptr<TileMap> tile_map;
    std::vector<std::unique_ptr<Prop>> props;
    std::vector<std::unique_ptr<Enemy>> enemies;
    std::vector<std::unique_ptr<Bullet>> bullets;
    std::vector<std::unique_ptr<Heal>> heals;
    bool cleard=false;

public:
    Paths paths;
    Room(const MapData& map_data,Player* player_);
    ~Room();
    void draw();
    void process();
    [[nodiscard]] std::vector<int> get_navigation_path() const;
    [[nodiscard]] int get_id();
    [[nodiscard]] bool is_cleard() const;
    void register_collisions();
    void register_tile_collisions() const;
    void cleanup();
    void add_bullet(std::unique_ptr<Bullet> bullet);
    void remove_bullets();
    void remove_all_bullets();
    void remove_all_heal();
    void spawn_heal(Vector2 pos);
};


#endif //ISLAND_WITH_NO_NAME_ROOM_H