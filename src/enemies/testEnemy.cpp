//
// Created by golczewa on 7.10.2026.
//

#include "testEnemy.h"

#include "../tools/vectorTools.h"

void TestEnemy::process() {
	if (dead) {
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
	if (VectorTools::distance(position,player->get_position())>40) {
		velocity=navigation_agent.get_next_move(player->get_position());
	}else {
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

TestEnemy::TestEnemy(Vector2 pos,Player *player_,Room* room_)
	: player(player_),navigation_agent(room_->get_navigation_path(),this){
	room=room_;
	position=pos;
	health=max_health;
	speed=0.5;
	sprite=LoadTexture("assets/sprites/test_enemy.png");
	collision={{position.x,position.y,10,10}
		,LAYER_0,LAYER_0,true,true,this};
	CollisionWorld::add_collider(&collision);
}

void TestEnemy::attack() {
	auto playet_pos=player->get_position();
	Vector2 direction={position.x-playet_pos.x,position.y-playet_pos.y};
	direction=VectorTools::normalise(direction);
	Vector2 bullet_pos={position.x+direction.x*16,position.y+direction.y*16};
	auto bullet=std::make_unique<DefaultBullet>(bullet_pos,direction);
	room->add_bullet(std::move(bullet));
}
