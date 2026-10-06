//
// Created by golczewa on 1.10.2026.
//

#include "prop.h"

Prop::Prop(Vector2 pos,const std::string& sprite_path):position(pos) {
    if (!sprite_path.empty()) {
        sprite=LoadTexture(sprite_path.c_str());
    }
    CollisionWorld::add_collider(&collision);
}

Prop::~Prop() {
    UnloadTexture(sprite);
    CollisionWorld::remove_collider(&collision);
}

void Prop::draw() {
    DrawTexture(sprite,position.x,position.y,WHITE);
}
