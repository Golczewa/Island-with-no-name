//
// Created by golczewa on 12.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_NAVIGATIONAGENT_H
#define ISLAND_WITH_NO_NAME_NAVIGATIONAGENT_H
#include <vector>
#include <cmath>
#include <algorithm>

#include "raylib.h"
#include "../enemies/enemy.h"


class NavigationAgent {
    std::vector<int>navigation_map;
    Enemy* owner;
protected:
    void astar(Vector2 pos); //TODO
    [[nodiscard]] int chebyshev_heuristics(Vector2 pos1,Vector2 pos2) const;
    [[nodiscard]] std::pair<int,int> to_tile_pos(Vector2 vec);
public:
    NavigationAgent(std::vector<int> map,Enemy* own);
    Vector2 get_next_move(Vector2 curr_pos,Vector2 pos); //TODO
};


#endif //ISLAND_WITH_NO_NAME_NAVIGATIONAGENT_H
