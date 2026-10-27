//
// Created by golczewa on 1.10.2026.
//

#include "prop.h"

#include <regex>

Prop::Prop(Vector2 pos,const std::string& sprite_path):position(pos) {
    if (!sprite_path.empty()) {
        sprite=LoadTexture(sprite_path.c_str());
    }
    register_collision();
}

Prop::~Prop() {
    UnloadTexture(sprite);
    unregister_collision();
}

void Prop::draw() {
    DrawTexture(sprite,position.x,position.y,WHITE);
}

Vector2 Prop::get_position() const {
    return position;
}

void Prop::register_collision() {
    CollisionWorld::add_collider(&collision);
}

void Prop::unregister_collision() {
    CollisionWorld::remove_collider(&collision);
}
