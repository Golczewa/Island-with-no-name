//
// Created by golczewa on 5.10.2026.
//

#include "collisionWorld.h"

#include <stdexcept>

void CollisionWorld::add_collider(Collision* collision) {
    if (collisions.size()>=max_colliders) {
        throw std::out_of_range("Collider limit reached");
    }
    collisions.insert(collision);
}

void CollisionWorld::remove_collider(Collision *collision) {
    collisions.erase(collision);
}

std::vector<Collision *> CollisionWorld::get_colliders(Collision *collision) {
    std::vector<Collision *> result;
    for (auto col:collisions) {
        if (!col->active || col==collision) {
            continue;
        }
        if (CheckCollisionRecs(col->shape,collision->shape) && (col->Layers & collision->Mask)) {
            result.push_back(col);
        }
    }
    return result;
}
