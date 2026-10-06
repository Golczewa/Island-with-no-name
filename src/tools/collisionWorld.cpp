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

Vector2 CollisionWorld::move_and_slide(Collision *collision, Vector2 velocity) {
    constexpr int max_resolves = 4;

    collision->shape.x += velocity.x;
    if (velocity.x != 0) {
        for (int i = 0; i < max_resolves; ++i) {
            Collision *best = nullptr;
            for (auto *col : get_colliders(collision)) {
                if (!col->solid) {
                    continue;
                }
                if (!best) {
                    best = col;
                    continue;
                }
                if (velocity.x > 0) {
                    if (col->shape.x < best->shape.x) {
                        best = col;
                    }
                } else if (col->shape.x + col->shape.width > best->shape.x + best->shape.width) {
                    best = col;
                }
            }
            if (!best) {
                break;
            }
            if (velocity.x > 0) {
                collision->shape.x = best->shape.x - collision->shape.width;
            } else {
                collision->shape.x = best->shape.x + best->shape.width;
            }
            velocity.x = 0;
        }
    }

    collision->shape.y += velocity.y;
    if (velocity.y != 0) {
        for (int i = 0; i < max_resolves; ++i) {
            Collision *best = nullptr;
            for (auto *col : get_colliders(collision)) {
                if (!col->solid) {
                    continue;
                }
                if (!best) {
                    best = col;
                    continue;
                }
                if (velocity.y > 0) {
                    if (col->shape.y < best->shape.y) {
                        best = col;
                    }
                } else if (col->shape.y + col->shape.height > best->shape.y + best->shape.height) {
                    best = col;
                }
            }
            if (!best) {
                break;
            }
            if (velocity.y > 0) {
                collision->shape.y = best->shape.y - collision->shape.height;
            } else {
                collision->shape.y = best->shape.y + best->shape.height;
            }
            velocity.y = 0;
        }
    }

    return velocity;
}
