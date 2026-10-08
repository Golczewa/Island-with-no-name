//
// Created by golczewa on 7.10.2026.
//

#include "testEnemy.h"

#include "../tools/vectorTools.h"

void TestEnemy::process() {
	if (VectorTools::distance(position,player->get_position())>50) {
		Vector2 pos={-position.x+player->get_position().x,-position.y+player->get_position().y};
		velocity=VectorTools::normalise(pos);
	}else {
		velocity.x=0;
		velocity.y=0;
	}
	position.x+=velocity.x*speed;
	position.y+=velocity.y*speed;
}

TestEnemy::TestEnemy(Vector2 pos,Player *player_) {
	player=player_;
	position=pos;
	health=max_health;
	speed=0.5;
	sprite=LoadTexture("assets/sprites/test_enemy.png");
}
