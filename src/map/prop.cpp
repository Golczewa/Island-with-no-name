//
// Created by golczewa on 1.10.2026.
//

#include "prop.h"

Prop::Prop(Vector2 pos,const std::string& sprite_path):position(pos) {
    if (!sprite_path.empty()) {
        sprite=LoadTexture(sprite_path.c_str());
    }
}

Prop::~Prop() {
        UnloadTexture(sprite);
}

void Prop::draw() {
    DrawTexture(sprite,position.x,position.y,WHITE);
}
