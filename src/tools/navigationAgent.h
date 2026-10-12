//
// Created by golczewa on 12.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_NAVIGATIONAGENT_H
#define ISLAND_WITH_NO_NAME_NAVIGATIONAGENT_H
#include <vector>
#include <cmath>
#include <algorithm>

#include "raylib.h"


class NavigationAgent {
    std::vector<int>navigation_map;
protected:
    Vector2 astar(Vector2 curr_pos,Vector2 wanted_pos); //TODO
    float chebyshev_heuristics(Vector2 pos1,Vector2 pos2);
public:
    NavigationAgent(std::vector<int> map);
    Vector2 get_next_move(Vector2 curr_pos,Vector2 pos); //TODO
};


#endif //ISLAND_WITH_NO_NAME_NAVIGATIONAGENT_H
