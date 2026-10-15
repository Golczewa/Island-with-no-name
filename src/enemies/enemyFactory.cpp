//
// Created by golczewa on 7.10.2026.
//

#include "enemyFactory.h"

#include <stdexcept>

#include "testEnemy.h"

std::unique_ptr<Enemy> EnemyFactory::create_enemy(EnemyFactory::Enemies enemy, Vector2 pos,Player* player,Room* room) {
    switch (enemy) {
        case EnemyFactory::TEST_ENEMY:
            auto new_enemy=std::make_unique<TestEnemy>(pos,player,room);
            return new_enemy;
    }
    throw std::invalid_argument("unknown enemy");
}
