//
// Created by golczewa on 27.09.2026.
//

#include "player.h"

Player::~Player() {
    UnloadTexture(sprite);
}

void Player::move(const float x, const float y) {
    position.x+=x;
    position.y+=y;
}

void Player::draw() {
    DrawTextureRec(sprite,frames,position,WHITE);
}

void Player::movement() {
    bool something_pressed=false;
    if (IsKeyDown(KEY_UP)) {
        move(0,-speed);
        something_pressed=true;
        walk_up.play();
    }
    if (IsKeyDown(KEY_DOWN)){
        move(0,speed);
        something_pressed=true;
        walk_down.play();

    }
    if (IsKeyDown(KEY_LEFT)) {
        move(-speed,0);
        something_pressed=true;

    }
    if (IsKeyDown(KEY_RIGHT)) {
        something_pressed=true;
        move(speed,0);
    }
    if (!something_pressed){
        idle.play();
    }
}

