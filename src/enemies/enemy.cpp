//
// Created by golczewa on 7.10.2026.
//

#include "enemy.h"

void Enemy::take_damage(int dmg) {
	health-=dmg;
	if (health<=0) {
		dead=true;
	}else {
		flash_red();
	}
}

Enemy::~Enemy() {
	UnloadTexture(sprite);
	CollisionWorld::remove_collider(&collision);
}

void Enemy::draw() {
	DrawTexture(sprite,position.x,position.y,color);
}

void Enemy::flash_red() {
	color=RED;
	red_timer.start(0.1);
}


Vector2 Enemy::get_position() const {
	return position;
}

Vector2 Enemy::get_middle() const {
	return {position.x+middle_offset,position.y+middle_offset};
}
