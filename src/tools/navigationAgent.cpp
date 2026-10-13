//
// Created by golczewa on 12.10.2026.
//

#include "navigationAgent.h"

#include <queue>
#include <unordered_map>
#include <utility>

NavigationAgent::NavigationAgent(std::vector<int> map,Enemy* own):navigation_map(std::move(map)),owner(own) {
}


int NavigationAgent::chebyshev_heuristics(std::pair<int,int> pos1,std::pair<int,int> pos2) const {
    return std::max(std::abs(pos1.first - pos2.first), std::abs(pos1.second - pos2.second));
}

float NavigationAgent::diagonal_heuristics(std::pair<int,int> pos1, std::pair<int,int> pos2) {
    int x=abs(pos1.first-pos2.first);
    int y=abs(pos1.second-pos2.second);
    return x+y+(sqrt(2)-2)*std::min(x,y);
}

int NavigationAgent::pos_to_index(std::pair<int, int> pos) {
    return pos.first*16+pos.second;
}

std::pair<int, int> NavigationAgent::index_to_pos(int n) {
    int x=std::floor(n/16);
    int y=n-x*16;
    return {x,y};
}

std::pair<int,int> NavigationAgent::global_to_tile_pos(Vector2 vec) {
    int x=std::floor(vec.x/16);
    int y=std::floor(vec.y/16);
    return {x,y};
}

std::vector<int> NavigationAgent::get_neighbors(std::pair<int,int> pos) {
    std::vector<int> result;
    for (int i=-1;i<2;i++) {
        for (int j=-1;j<2;j++) {
            std::pair<int,int>new_pos={pos.first+i,pos.second+j};
            if (navigation_map[pos_to_index(new_pos)]==1 || new_pos.first<0 || new_pos.second<0 || new_pos.first>15 || new_pos.second>11) {
                continue;
            }else {
                result.push_back(pos_to_index(new_pos));
            }
        }
    }
    return result;
}

void NavigationAgent::astar(Vector2 pos) {
    if (pos.x==last_target.x and pos.y==last_target.y) {
        return;
    }
    curr_path.clear();
    auto start=global_to_tile_pos(owner->get_position());
    auto target=global_to_tile_pos(pos);
    std::queue<DataTrio> queue;
    queue.push({diagonal_heuristics(start,target),0,pos_to_index(start)});
    std::unordered_map<int,int>g;
    g[pos_to_index(start)]=0;
    while (!queue.empty()) {
        auto data=queue.front();
        queue.pop();
        if (data.index==pos_to_index(target)) {
            curr_path.push_back(pos_to_index(target));
            //TODO
            return;
        }
        if (data.val>g[data.index]) {
            continue;
        }
        for (auto neighbor:get_neighbors(index_to_pos(data.index))) {
            //TODO
        }
    }
}
