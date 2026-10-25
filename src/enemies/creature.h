//
// Created by golczewa on 25.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_CREATURE_H
#define ISLAND_WITH_NO_NAME_CREATURE_H
#include "enemy.h"
#include "../tools/navigationAgent.h"
#include "../tools/animation.h"
#include "../map/room.h"
#include "../tools/vectorTools.h"
#include "../game/player.h"
#include "../bullets/defaultBullet.h"

class Player;
class Room;

class Creature:public Enemy{
    const int max_health=6;
    const float max_speed=0.5;
    float cooldown=3;
    Player* player;
    NavigationAgent navigation_agent;
    Timer attack_timer{};
    Rectangle frames;
    std::unique_ptr<AnimatedSprite> animated_sprite;
public:
    Creature(Vector2 pos,Player *player_,Room* room_);
    void process() override;
    void attack();
    void draw() override;
};


#endif //ISLAND_WITH_NO_NAME_CREATURE_H
