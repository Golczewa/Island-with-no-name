//
// Created by golczewa on 12.10.2026.
//

#include "navigationAgent.h"

#include <utility>

NavigationAgent::NavigationAgent(std::vector<int> map):navigation_map(std::move(map)) {
}

float NavigationAgent::chebyshev_heuristics(Vector2 pos1,Vector2 pos2) {
    return std::max(std::abs(pos1.x - pos2.x), std::abs(pos1.y - pos2.y));
}
