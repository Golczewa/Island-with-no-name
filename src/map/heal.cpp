//
// Created by golczewa on 2.11.2026.
//

#include "heal.h"


Heal::Heal(Vector2 pos):position(pos) {
    collision={{pos.x,pos.y,8,8},LAYER_0,LAYER_0,false,true};
    register_collison();
}

Heal::~Heal() {
    UnloadTexture(sprite);
    unregister_collison();
}

void Heal::draw() {
    DrawTexture(sprite,position.x,position.y,WHITE);
}

void Heal::process() {
    for (auto& cols:CollisionWorld::get_colliders(&collision)) {
        auto player=dynamic_cast<Player*>(cols->owner);
        if (player) {
            player->heal(heal_amount);
            to_remove=true;
        }
    }
}

void Heal::register_collison() {
    CollisionWorld::add_collider(&collision);
}

void Heal::unregister_collison() {
    CollisionWorld::remove_collider(&collision);
}

bool Heal::is_to_remove() const {
    return to_remove;
}
