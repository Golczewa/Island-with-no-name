//
// Created by golczewa on 27.09.2026.
//

#include "player.h"

#include "game.h"

Player::Player(Game* game_) {
    animated_sprite.create_animation("idle_down",0,0);
    animated_sprite.create_animation("idle_up",3,3);
    animated_sprite.create_animation("idle_right",6,6);
    animated_sprite.create_animation("idle_left",7,7);
    animated_sprite.create_animation("walk_down",1,2);
    animated_sprite.create_animation("walk_up",3,4);
    animated_sprite.create_animation("walk_right",5,6);
    animated_sprite.create_animation("walk_left",7,8);
    CollisionWorld::add_collider(&collision);
    game=game_;

}

Player::~Player() {
    UnloadTexture(sprite);
    CollisionWorld::remove_collider(&collision);

}

void Player::draw() {
    DrawTextureRec(sprite,frames,position,WHITE);
}

void Player::process() {
    move_to_room();
    bool something_pressed=false;
    velocity.x=0;
    velocity.y=0;
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
    velocity = CollisionWorld::move_and_slide(&collision, velocity);
    position.x = collision.shape.x;
    position.y = collision.shape.y;
}

void Player::teleport_to(Vector2 pos) {
    velocity.x=0;
    velocity.y=0;
    collision.shape.x=pos.x;
    collision.shape.y=pos.y;
}

void Player::move_to_room() {
    if (0<position.x and position.x<4) {
        const int next_room = game->curr_room->paths.left_room_id;
        if (next_room == -1) {
            return;
        }
        game->change_room(next_room);
        teleport_to({224, position.y});
        return;
    }
    if (236<position.x and position.x<240) {
        const int next_room = game->curr_room->paths.right_room_id;
        if (next_room == -1) {
            return;
        }
        game->change_room(next_room);
        teleport_to({16, position.y});
        return;
    }
    if (0<position.y and position.y<4) {
        const int next_room = game->curr_room->paths.upper_room_id;
        if (next_room == -1) {
            return;
        }
        game->change_room(next_room);
        teleport_to({position.x, 160});
        return;
    }
    if (172<position.y and position.y<176) {
        const int next_room = game->curr_room->paths.down_room_id;
        if (next_room == -1) {
            return;
        }
        game->change_room(next_room);
        teleport_to({position.x,16});
        return;
    }
}

void Player::take_damage(int dmg) {
    health-=dmg;
}
