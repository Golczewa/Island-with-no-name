//
// Created by golczewa on 14.10.2026.
//

#include "defaultBullet.h"

#include "../game/player.h"

DefaultBullet::DefaultBullet(Vector2 pos, Vector2 vel) {
    color=ORANGE;
    position=pos;
    velocity=vel;
    speed=1;
    sprite=LoadTexture("assets/sprites/bullet.png");
    collision_=Collision({position.x,position.y,3,3},LAYER_0,LAYER_0,true,true,this);
    CollisionWorld::add_collider(&collision_);
}

void DefaultBullet::process() {
    color_switch_timer.process();
    if (color_switch_timer.is_running()) {
        color=RED;
    }else {
        color=ORANGE;
        color_switch_timer.start(0.2);
    }
    auto colliders=CollisionWorld::get_colliders(&collision_);
    if (!colliders.empty()) {
        for (auto collider: colliders) {
            auto player=dynamic_cast<Player*>(collider->owner);
            if (player) {
                player->take_damage(dmg);
                break;
            }
        }
        to_remove=true;
    }
    position.x+=velocity.x*speed;
    position.y+=velocity.y*speed;
    collision_.shape.x=position.x+1;
    collision_.shape.y=position.y+1;
}
