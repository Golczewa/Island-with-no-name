//
// Created by golczewa on 7.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_ENEMY_H
#define ISLAND_WITH_NO_NAME_ENEMY_H
#include "raylib.h"
#include "../tools/body.h"
#include "../tools/collisionWorld.h"
#include "../tools/timer.h"


class Enemy : public Body{
protected:
	int health=0;
	float speed=0;
	Vector2 position{};
	Vector2 velocity{};
	Texture2D sprite{};
	Color color=WHITE;
	Collision collision{};
	bool dead=false;
	Timer red_timer;
public:
	~Enemy() override;
	virtual void process()=0;
	void take_damage(int dmg);
	void draw();
	void flash_red();
};


#endif //ISLAND_WITH_NO_NAME_ENEMY_H