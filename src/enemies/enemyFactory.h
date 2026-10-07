//
// Created by golczewa on 7.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_ENEMYFACTORY_H
#define ISLAND_WITH_NO_NAME_ENEMYFACTORY_H
#include <functional>
#include <memory>
#include <unordered_map>

#include "enemy.h"

namespace EnemyFactory {
    enum Enemies {
        TEST_ENEMY,
    };
    std::unique_ptr<Enemy> create_enemy(Enemies enemy,Vector2 pos);
}





#endif //ISLAND_WITH_NO_NAME_ENEMYFACTORY_H
