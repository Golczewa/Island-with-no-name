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
    std::vector<int>curr_path;
    Vector2 last_target;
protected:
    struct DataTrio {
        float heu_val;
        int val;
        int index;
    };
    void astar(Vector2 pos); //TODO
    [[nodiscard]] int chebyshev_heuristics(std::pair<int,int> pos1,std::pair<int,int> pos2) const;
    [[nodiscard]] float diagonal_heuristics(std::pair<int,int> pos1,std::pair<int,int> pos2);
    [[nodiscard]] std::pair<int,int> global_to_tile_pos(Vector2 vec);
    [[nodiscard]] int pos_to_index(std::pair<int,int> pos);
    [[nodiscard]] std::pair<int,int> index_to_pos(int n);
    [[nodiscard]] std::vector<int> get_neighbors(std::pair<int,int> pos);
public:
    NavigationAgent(std::vector<int> map,Enemy* own);
    Vector2 get_next_move(Vector2 curr_pos,Vector2 pos); //TODO
};


#endif //ISLAND_WITH_NO_NAME_NAVIGATIONAGENT_H
