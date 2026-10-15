//
// Created by golczewa on 11.10.2026.
//

#include "bullet.h"

Bullet::~Bullet() {
    CollisionWorld::remove_collider(&collision_);
    UnloadTexture(sprite);
}

void Bullet::draw() {
    DrawTexture(sprite,position.x,position.y,color);
}

bool Bullet::is_to_remove() const {
    return to_remove;
}
