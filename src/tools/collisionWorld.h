//
// Created by golczewa on 5.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_COLLISIONWORLD_H
#define ISLAND_WITH_NO_NAME_COLLISIONWORLD_H
#include <unordered_set>

#include "raylib.h"

enum CollisionLayers {
    LAYER_0=0,
    LAYER_1=1,
    LAYER_2=2,
    LAYER_3=3
};

struct Collision {
    Rectangle shape;
    CollisionLayers Layers;
    CollisionLayers Mask;
    bool solid;
    bool active;
    void *owner;
};



class CollisionWorld {
    static constexpr int max_colliders = 128;
    int collisions_number=0;
public:
    inline static std::unordered_set<Collision*> collisions;
    void add_collider(const Collision* collision);
};


#endif //ISLAND_WITH_NO_NAME_COLLISIONWORLD_H
