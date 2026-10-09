//
// Created by golczewa on 7.10.2026.
//

#include "testEnemy.h"

#include "../tools/vectorTools.h"

void TestEnemy::process() {
	if (dead) {
		color=GRAY;
		return;
	}
	velocity.x=0;
	velocity.y=0;
	if (VectorTools::distance(position,player->get_position())>50) {
		Vector2 pos={-position.x+player->get_position().x,-position.y+player->get_position().y};
		velocity=VectorTools::normalise(pos);
	}else {
		velocity.x=0;
		velocity.y=0;
	}
	velocity = CollisionWorld::move_and_slide(&collision, velocity,speed);
	position.x = collision.shape.x;
	position.y = collision.shape.y;
}

TestEnemy::TestEnemy(Vector2 pos,Player *player_) {
	player=player_;
	position=pos;
	health=max_health;
	speed=0.5;
	sprite=LoadTexture("assets/sprites/test_enemy.png");
	collision={{position.x,position.y,10,10}
		,LAYER_0,LAYER_0,true,true,this};
	CollisionWorld::add_collider(&collision);
}
