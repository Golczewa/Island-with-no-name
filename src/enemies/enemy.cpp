//
// Created by golczewa on 7.10.2026.
//

#include "enemy.h"

void Enemy::take_damage(int dmg) {
	health-=dmg;
}

Enemy::~Enemy() {
	UnloadTexture(sprite);
	CollisionWorld::remove_collider(&collision);
}

void Enemy::draw() {
	DrawTexture(sprite,position.x,position.y,color);
}

