//
// Created by golczewa on 7.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_TESTENEMY_H
#define ISLAND_WITH_NO_NAME_TESTENEMY_H
#include "enemy.h"
#include "../game/player.h"
#include "../map/room.h"
#include "../tools/navigationAgent.h"


class TestEnemy: public Enemy {
	const int max_health=6;
	Player* player;
	NavigationAgent navigation_agent;
public:
	TestEnemy(Vector2 pos,Player *player_,Room* room_);
	void process() override;
};

#endif //ISLAND_WITH_NO_NAME_TESTENEMY_H