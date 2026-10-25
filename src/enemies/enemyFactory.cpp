//
// Created by golczewa on 7.10.2026.
//

#include "enemyFactory.h"

#include <stdexcept>

#include "creature.h"
#include "testEnemy.h"

std::unique_ptr<Enemy> EnemyFactory::create_enemy(Enemies enemy, Vector2 pos,Player* player,Room* room) {
    switch (enemy) {
        case TEST_ENEMY:
            return  std::make_unique<TestEnemy>(pos,player,room);
            break;
        case CREATURE:
            return std::make_unique<Creature>(pos,player,room);
            break;
    }
    throw std::invalid_argument("unknown enemy");
}
