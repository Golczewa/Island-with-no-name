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
    CollisionWorld::add_collider(&collision);

}

Player::~Player() {
    UnloadTexture(sprite);
    CollisionWorld::remove_collider(&collision);

}

void Player::draw() {
    DrawTextureRec(sprite,frames,position,WHITE);
}

void Player::process() {
    bool something_pressed=false;
    if (IsKeyDown(KEY_UP)) {
        velocity.y=-speed;
        something_pressed=true;
        animated_sprite.play_animation("walk_up");
        stance=UP;
    }
    if (IsKeyDown(KEY_DOWN)){
        velocity.y=speed;
        something_pressed=true;
        animated_sprite.play_animation("walk_down");
        stance=DOWN;
    }
    if (IsKeyDown(KEY_LEFT)) {
        velocity.x=-speed;
        something_pressed=true;
        animated_sprite.play_animation("walk_left");
        stance=LEFT;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        something_pressed=true;
        velocity.x=speed;
        animated_sprite.play_animation("walk_right");
        stance=RIGHT;
    }

    if (!something_pressed){
        velocity.x=0;
        velocity.y=0;
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
    position.x+=velocity.x;
    position.y+=velocity.y;
}

