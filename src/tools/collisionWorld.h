//
// Created by golczewa on 5.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_COLLISIONWORLD_H
#define ISLAND_WITH_NO_NAME_COLLISIONWORLD_H
#include <unordered_set>
#include <vector>
#include "../tools/body.h"


#include "raylib.h"

enum CollisionLayers{
    LAYER_0=1<<0,
    LAYER_1=1<<1,
    LAYER_2=1<<2,
    LAYER_3=1<<3
};

struct Collision {
    Rectangle shape;
    CollisionLayers Layers;
    CollisionLayers Mask;
    bool solid;
    bool active;
    Body *owner;
};



class CollisionWorld {
    static constexpr int max_colliders = 256;
public:
    inline static std::unordered_set<Collision*> collisions;
    static void add_collider(Collision* collision);
    static void remove_collider(Collision* collision);
    static std::vector<Collision*> get_colliders(Collision* collision);
    static Vector2 move_and_slide(Collision* collision, Vector2 velocity,float speed);
};


#endif //ISLAND_WITH_NO_NAME_COLLISIONWORLD_H
