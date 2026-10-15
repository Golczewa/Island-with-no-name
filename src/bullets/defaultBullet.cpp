//
// Created by golczewa on 14.10.2026.
//

#include "defaultBullet.h"

#include "../game/player.h"

DefaultBullet::DefaultBullet(Vector2 pos, Vector2 vel) {
    color=ORANGE;
    position=pos;
    velocity=vel;
    sprite=LoadTexture("assets/sprites/bullet.png");
    collision_=Collision({position.x,position.y,3,3},LAYER_0,LAYER_0,true,true,this);
    CollisionWorld::add_collider(&collision_);
}

void DefaultBullet::process() {
    auto colliders=CollisionWorld::get_colliders(&collision_);
    if (!colliders.empty()) {
        for (auto collider: colliders) {
            auto player=dynamic_cast<Player*>(collider->owner);
            if (!player) {
                player->take_damage(dmg);
                to_remove=true;
                break;
            }
        }
    position.x+=velocity.x*speed;
        position.y+=velocity.y*speed;
    }
}
