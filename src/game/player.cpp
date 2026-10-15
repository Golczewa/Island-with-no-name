//
// Created by golczewa on 27.09.2026.
//

#include "player.h"

#include <algorithm>

#include "../enemies/enemy.h"
#include "game.h"

Player::Player(Game* game_) {
    animated_sprite.create_animation("idle_down",0,0);
    animated_sprite.create_animation("idle_up",3,3);
    animated_sprite.create_animation("idle_right",7,7);
    animated_sprite.create_animation("idle_left",8,8);
    animated_sprite.create_animation("walk_down",1,2);
    animated_sprite.create_animation("walk_up",4,5);
    animated_sprite.create_animation("walk_right",6,7);
    animated_sprite.create_animation("walk_left",8,9);
    animated_sprite.create_animation("weaponless_down",10,10);
    animated_sprite.create_animation("weaponless_up",11,11);
    animated_sprite.create_animation("weaponless_right",12,12);
    animated_sprite.create_animation("weaponless_left",13,13);

    slash.create_animation("slash",0,5);
    slash.hide();
    CollisionWorld::add_collider(&collision);
    CollisionWorld::add_collider(&weapon_area);
    game=game_;

}

Player::~Player() {
    UnloadTexture(sprite);
    UnloadTexture(slash_sprite);
    CollisionWorld::remove_collider(&collision);
    CollisionWorld::remove_collider(&weapon_area);

}

void Player::draw() {
    if (!animated_sprite.is_hidden()) {
        DrawTextureRec(sprite,frames,position,WHITE);
    }
    if (!slash.is_hidden()) {
        DrawTextureRec(slash_sprite,slash_rec,slash_position,WHITE);
    }
}

void Player::process() {
    attack_timer.process();
    if (!attack_timer.is_running()) {
        animated_sprite.show();
    }
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
    velocity = CollisionWorld::move_and_slide(&collision, velocity,speed);
    position.x = collision.shape.x;
    position.y = collision.shape.y;
    switch (stance) {
        case UP:
            if (attack_timer.is_running()) {
                animated_sprite.play_animation("weaponless_up");
            }
            weapon_area.shape.x = position.x;
            weapon_area.shape.y = position.y - 16;
            break;
        case DOWN:
            if (attack_timer.is_running()) {
                animated_sprite.play_animation("weaponless_down");
            }
            weapon_area.shape.x = position.x;
            weapon_area.shape.y = position.y + 16;
            break;
        case LEFT:
            if (attack_timer.is_running()) {
                animated_sprite.play_animation("weaponless_left");
            }
            weapon_area.shape.x = position.x - 16;
            weapon_area.shape.y = position.y;
            break;
        case RIGHT:
            if (attack_timer.is_running()) {
                animated_sprite.play_animation("weaponless_right");
            }
            weapon_area.shape.x = position.x + 16;
            weapon_area.shape.y = position.y;
            break;
    }
    slash_position={weapon_area.shape.x,weapon_area.shape.y};
    if (attack_timer.is_running()) {
        slash.play_animation("slash");
    } else {
        slash.hide();
    }
    if (IsKeyPressed(KEY_Z)) {
        attack();

    }
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

Vector2 Player::get_position() const {
    return position;
}

void Player::attack() {
    if (attack_timer.is_running()) {
        return;
    }
    TraceLog(LOG_INFO,"weapon_pos_coll: %f %f",weapon_area.shape.x,weapon_area.shape.y);
    attack_timer.start(6.0f/24.0f);
    auto& slash_animation=slash.animations.at("slash");
    slash_animation.curr_frame=slash_animation.begin_frame;
    slash_animation.frame_time=0;
    slash.show();
    slash.play_animation("slash");

    auto colliders=CollisionWorld::get_colliders(&weapon_area);
    for (auto col:colliders) {
        auto enemy=dynamic_cast<Enemy*>(col->owner);
        if (!enemy) {
            continue;
        }
        enemy->take_damage(sword_dmg);
        break;
    }
}
