//
// Created by golczewa on 25.10.2026.
//

#include "creature.h"

Creature::Creature(Vector2 pos, Player *player_, Room *room_)
    : player(player_),navigation_agent(room_->get_navigation_path(),this){
    room=room_;
    position=pos;
    health=max_health;
    speed=max_speed;
    sprite=LoadTexture("assets/sprites/bad_guy.png");
    frames = {0, 0, static_cast<float>(sprite.width) / 3.0f, static_cast<float>(sprite.height)};
    animated_sprite=std::make_unique<AnimatedSprite>(3,frames,sprite);
    animated_sprite->create_animation("stand",0,0);
    animated_sprite->create_animation("walk",1,2);
    collision={{position.x,position.y,10,10}
        ,LAYER_0,LAYER_0,true,true,this};
    CollisionWorld::add_collider(&collision);
}

void Creature::process() {
    if (dead) {
        animated_sprite->play_animation("stand");
        color=GRAY;
        collision.active=false;
        return;
    }
    attack_timer.process();
    red_timer.process();
    if (!red_timer.is_running()) {
        color=WHITE;
    }
    velocity.x=0;
    velocity.y=0;
    if (VectorTools::distance(position,player->get_position())>60) {
        animated_sprite->play_animation("walk");
        velocity=navigation_agent.get_next_move(player->get_position());
    }else {
        animated_sprite->play_animation("stand");
        velocity.x=0;
        velocity.y=0;
        if (!attack_timer.is_running()) {
            attack();
            attack_timer.start(cooldown);
        }
    }
    velocity = CollisionWorld::move_and_slide(&collision, velocity,speed);
    position.x = collision.shape.x;
    position.y = collision.shape.y;
}

void Creature::attack() {
    auto player_pos=player->get_middle();
    Vector2 direction={-get_middle().x+player_pos.x,-get_middle().y+player_pos.y};
    direction=VectorTools::normalise(direction);
    Vector2 bullet_pos={get_middle().x+direction.x*16,get_middle().y+direction.y*16};
    auto bullet=std::make_unique<DefaultBullet>(bullet_pos,direction);
    room->add_bullet(std::move(bullet));
}

void Creature::draw() {
    DrawTextureRec(sprite,frames,position,color);
}
