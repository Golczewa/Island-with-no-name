//
// Created by golczewa on 7.10.2026.
//

#include "testEnemy.h"

void TestEnemy::process() {

}

TestEnemy::TestEnemy(Vector2 pos) {
	position=pos;
	health=max_health;
	sprite=LoadTexture("assets/sprites/test_enemy.png");
}
