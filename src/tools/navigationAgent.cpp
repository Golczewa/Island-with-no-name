//
// Created by golczewa on 12.10.2026.
//

#include "navigationAgent.h"

#include <unordered_map>
#include <utility>

NavigationAgent::NavigationAgent(std::vector<int> map,Enemy* own):navigation_map(std::move(map)),owner(own) {
}

int NavigationAgent::chebyshev_heuristics(Vector2 pos1,Vector2 pos2) const {
    return std::max(std::abs(pos1.x - pos2.x), std::abs(pos1.y - pos2.y));
}

std::pair<int,int> NavigationAgent::to_tile_pos(Vector2 vec) {
    int x=std::floor(vec.x/16);
    int y=std::floor(vec.y/16);
    return {x,y};
}

void NavigationAgent::astar(Vector2 pos) {
    auto start=to_tile_pos(owner->get_position());
    auto target=to_tile_pos(pos);
}
