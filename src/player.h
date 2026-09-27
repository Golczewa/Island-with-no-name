//
// Created by golczewa on 27.09.2026.
//

#ifndef ISLAND_WITH_NO_NAME_PLAYER_H
#define ISLAND_WITH_NO_NAME_PLAYER_H
#include "raylib.h"


class Player {
    Vector2 position={.x = 50,.y = 50};
    Texture2D sprite=LoadTexture("assets/sprites/guy.png");
    float speed=1;
    int curr_frame=0;
    int frame_count=0;
    int frame_speed=8;
    Rectangle frames={0,0,static_cast<float>(sprite.width)/5,static_cast<float>(sprite.height)};

public:
    ~Player();
    void move(float x,float y);
    void draw();
    void movement();
};


#endif //ISLAND_WITH_NO_NAME_PLAYER_H
