//
// Created by golczewa on 27.09.2026.
//

#ifndef ISLAND_WITH_NO_NAME_PLAYER_H
#define ISLAND_WITH_NO_NAME_PLAYER_H
#include "raylib.h"
#include "tools/animation.h"


class Player {
    Vector2 position={.x = 50,.y = 50};
    Texture2D sprite=LoadTexture("assets/sprites/guy.png");
    const int frames_count=9;
    Rectangle frames={0,0,static_cast<float>(sprite.width)/frames_count,static_cast<float>(sprite.height)};
    AnimatedSprite animated_sprite=AnimatedSprite(frames_count,frames,sprite);
    float speed=1;


public:
    Player();
    ~Player();
    void move(float x,float y);
    void draw();
    void movement();

};


#endif //ISLAND_WITH_NO_NAME_PLAYER_H
