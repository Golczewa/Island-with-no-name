//
// Created by golczewa on 7.10.2026.
//

#include "enemyFactory.h"

#include "testEnemy.h"

std::unique_ptr<Enemy> EnemyFactory::create_enemy(EnemyFactory::Enemies enemy, Vector2 pos,Player* player,const std::vector<int>& col_map) {
    switch (enemy) {
        case EnemyFactory::TEST_ENEMY:
            auto new_enemy=std::make_unique<TestEnemy>(pos,player,col_map);
            return new_enemy;
    }
    throw std::invalid_argument("unknown enemy");
}
