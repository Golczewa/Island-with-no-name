//
// Created by golczewa on 12.10.2026.
//

#include "navigationAgent.h"

#include <utility>

NavigationAgent::NavigationAgent(std::vector<int> map):navigation_map(std::move(map)) {
}
