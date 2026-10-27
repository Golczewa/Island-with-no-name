//
// Created by golczewa on 1.10.2026.
//

#include "room.h"

#include <cmath>

#include "../bullets/bullet.h"
#include "../enemies/enemy.h"

Room::Room(const MapData& map_data,Player* player_) {
    player=player_;
    tile_map=std::make_unique<TileMap>(map_data.tiles_path,map_data.tile_number ,map_data.tiles,map_data.cols);
    register_tile_collisions();
    for (auto& prop: map_data.props) {
        props.push_back(std::make_unique<Prop>(prop.first,prop.second));
    }
    for (auto& enemy:map_data.enemies) {
        enemies.push_back(EnemyFactory::create_enemy(enemy.first,enemy.second,player,this));
    }
    id=map_data.id;
    paths=map_data.paths;
}

Room::~Room() = default;

void Room::draw() {
    tile_map->draw();
    for (auto& prop :props) {
        prop->draw();
    }
    for (auto& enemy:enemies) {
        enemy->draw();
    }
    for (auto& bullet:bullets) {
        bullet->draw();
    }
}

void Room::process() {
    for (auto& enemy:enemies) {
        enemy->process();
    }
    for (auto& bullet:bullets) {
        if (!bullet->is_to_remove()) {
            bullet->process();
        }
    }
    remove_bullets();
}

std::vector<int> Room::get_navigation_path() const {
    std::vector<int> map(16*12);
    for (auto& prop:props) {
        auto pos=prop->get_position();
        int cx=std::floor(pos.x/16);
        int cy=std::floor(pos.y/16);
        const int offsets[6][2]={{0,0},{-1,0},{1,0},{0,-1},{0,1},{-1,-1}};
        for (auto& o:offsets) {
            int x=cx+o[0];
            int y=cy+o[1];
            if (x<0||x>=16||y<0||y>=12) continue;
            map[x+y*16]=1;
        }
    }
    for (int i=0;i<16*12;i++) {
        if (tile_map->get_cols()[tile_map->get_map()[i]]) {
            map[i]=1;
        }
    }
    return map;
}

void Room::add_bullet(std::unique_ptr<Bullet> bullet) {
    bullets.push_back(std::move(bullet));
}

void Room::remove_bullets() {
    std::erase_if(bullets, [](const auto& b) { return b->is_to_remove(); });
}

int Room::get_id() {
    return id;
}

void Room::cleanup() {
    tile_map->clear_collisions();
    remove_bullets();
    for (auto& enemy: enemies) {
        enemy->unregister_collision();
    }
    for (auto& porp:props) {
        porp->unregister_collision();
    }
}

void Room::register_collisions() {
    register_tile_collisions();
    for (auto& enemy: enemies) {
        enemy->register_collision();
    }
    for (auto& porp:props) {
        porp->register_collision();
    }
}

void Room::register_tile_collisions() const {
    for (int i=0;i<12;i++) {
        for (int j=0;j<16;j++) {
            if (tile_map->get_cols()[tile_map->get_map()[i*16+j]]==1) {
                Collision tile_col{Rectangle{static_cast<float>(j*16),static_cast<float>(i*16),16,16},LAYER_0,LAYER_0,true,true,nullptr};
                tile_map->add_tile_collision(tile_col);
            }
        }
    }
}
