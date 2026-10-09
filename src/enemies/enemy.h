//
// Created by golczewa on 7.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_ENEMY_H
#define ISLAND_WITH_NO_NAME_ENEMY_H
#include "raylib.h"
#include "../tools/collisionWorld.h"


class Enemy {
protected:
	int health=0;
	float speed=0;
	Vector2 position{};
	Vector2 velocity{};
	Texture2D sprite{};
	Color color=WHITE;
	Collision collision{};
public:
	virtual ~Enemy();
	virtual void process()=0;
	void take_damage(int dmg);
	void draw();
};


#endif //ISLAND_WITH_NO_NAME_ENEMY_H