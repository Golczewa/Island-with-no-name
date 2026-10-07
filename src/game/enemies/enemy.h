//
// Created by golczewa on 7.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_ENEMY_H
#define ISLAND_WITH_NO_NAME_ENEMY_H
#include "raylib.h"


class Enemy {
	int health=0;
	Vector2 poition;
	Texture2D sprite={0,0};
public:
	virtual ~Enemy();
	virtual void process()=0;
	void take_damage(int dmg);
	void draw();
};


#endif //ISLAND_WITH_NO_NAME_ENEMY_H