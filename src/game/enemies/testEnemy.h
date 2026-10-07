//
// Created by golczewa on 7.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_TESTENEMY_H
#define ISLAND_WITH_NO_NAME_TESTENEMY_H
#include "enemy.h"


class TestEnemy: Enemy {
	const int max_health=6;
	int health=max_health;
	Texture2D sprite=LoadTexture("assets/sprites/test_enemy.png");
	Vector2 position{};
public:
	TestEnemy(Vector2 pos);
	void process() override;
};

#endif //ISLAND_WITH_NO_NAME_TESTENEMY_H