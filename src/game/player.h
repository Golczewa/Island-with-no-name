//
// Created by golczewa on 27.09.2026.
//

#ifndef ISLAND_WITH_NO_NAME_PLAYER_H
#define ISLAND_WITH_NO_NAME_PLAYER_H
#include "raylib.h"
#include "../tools/animation.h"
#include "../tools/collisionWorld.h"

class Game;

class Player {
    const int max_health=6;
    int health=max_health;
    Vector2 position={.x =128,.y = 128};
    Vector2 velocity={0,0};
    Collision collision={{position.x,position.y,16,16},LAYER_0,LAYER_0,true,true,this};
    Texture2D sprite=LoadTexture("assets/sprites/guy.png");
    const int frames_count=9;
    Rectangle frames={0,0,static_cast<float>(sprite.width)/frames_count,static_cast<float>(sprite.height)};
    AnimatedSprite animated_sprite=AnimatedSprite(frames_count,frames,sprite);
    float speed=1;
    enum Stance {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    Stance stance=DOWN;
    Game* game;
public:
    Player(Game* game_);
    ~Player();
    void draw();
    void process();
    void teleport_to(Vector2 pos);
    void move_to_room();
    void take_damage(int dmg);

};


#endif //ISLAND_WITH_NO_NAME_PLAYER_H
