//
// Created by golczewa on 27.09.2026.
//

#include "player.h"

Player::Player() {
    animated_sprite.create_animation("idle_down",0,0);
    animated_sprite.create_animation("idle_up",3,3);
    animated_sprite.create_animation("idle_right",6,6);
    animated_sprite.create_animation("idle_left",7,7);
    animated_sprite.create_animation("walk_down",1,2);
    animated_sprite.create_animation("walk_up",3,4);
    animated_sprite.create_animation("walk_right",5,6);
    animated_sprite.create_animation("walk_left",7,8);

}

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
        animated_sprite.play_animation("walk_up");
        stance=UP;
    }
    if (IsKeyDown(KEY_DOWN)){
        move(0,speed);
        something_pressed=true;
        animated_sprite.play_animation("walk_down");
        stance=DOWN;
    }
    if (IsKeyDown(KEY_LEFT)) {
        move(-speed,0);
        something_pressed=true;
        animated_sprite.play_animation("walk_left");
        stance=LEFT;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        something_pressed=true;
        move(speed,0);
        animated_sprite.play_animation("walk_right");
        stance=RIGHT;
    }
    if (!something_pressed){
        switch (stance) {
            case UP:
                animated_sprite.play_animation("idle_up");
                break;
            case LEFT:
                animated_sprite.play_animation("idle_left");
                break;
            case RIGHT:
                animated_sprite.play_animation("idle_right");
                break;
            case DOWN:
                animated_sprite.play_animation("idle_down");
                break;
        }

    }
}

