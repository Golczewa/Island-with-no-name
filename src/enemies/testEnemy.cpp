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
	red_timer.process();
	if (!red_timer.is_running()) {
		color=WHITE;
	}
	velocity.x=0;
	velocity.y=0;
	if (VectorTools::distance(position,player->get_position())>25) {
		velocity=navigation_agent.get_next_move(player->get_position());
	}else {
		velocity.x=0;
		velocity.y=0;
	}
	velocity = CollisionWorld::move_and_slide(&collision, velocity,speed);
	position.x = collision.shape.x;
	position.y = collision.shape.y;
}

TestEnemy::TestEnemy(Vector2 pos,Player *player_,const std::vector<int>& col_map)
	: player(player_), navigation_agent(col_map,this) {
	position=pos;
	health=max_health;
	speed=0.5;
	sprite=LoadTexture("assets/sprites/test_enemy.png");
	collision={{position.x,position.y,10,10}
		,LAYER_0,LAYER_0,true,true,this};
	CollisionWorld::add_collider(&collision);
}


