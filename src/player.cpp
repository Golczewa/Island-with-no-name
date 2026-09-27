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
    if (IsKeyDown(KEY_UP)) move(0,-speed);
    if (IsKeyDown(KEY_DOWN)) move(0,speed);
    if (IsKeyDown(KEY_LEFT)) move(-speed,0);
    if (IsKeyDown(KEY_RIGHT)) move(speed,0);

}
