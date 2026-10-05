//
// Created by golczewa on 5.10.2026.
//

#include "collisionWorld.h"

#include <stdexcept>

void CollisionWorld::add_collider(const Collision* collision) {
    if (collisions_number>=max_colliders) {
        throw std::out_of_range("Collider limit reached");
    }
    collisions.insert(collision);
    collisions_number++;
}
