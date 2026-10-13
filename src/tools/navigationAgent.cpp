//
// Created by golczewa on 12.10.2026.
//

#include "navigationAgent.h"

#include <queue>
#include <unordered_map>
#include <utility>

#include "vectorTools.h"

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
    return pos.second*16+pos.first;
}

std::pair<int, int> NavigationAgent::index_to_pos(int n) {
    int x=n%16;
    int y=n/16;
    return {x,y};
}

std::pair<int,int> NavigationAgent::global_to_tile_pos(Vector2 vec) {
    int x=std::floor(vec.x/16);
    int y=std::floor(vec.y/16);
    return {x,y};
}

Vector2 NavigationAgent::pos_to_global(std::pair<int, int> pos) {
    return {static_cast<float>(pos.first*16+8),static_cast<float>(pos.second*16+8)};
}

std::vector<int> NavigationAgent::get_neighbors(std::pair<int,int> pos) {
    std::vector<int> result;
    for (int i=-1;i<2;i++) {
        for (int j=-1;j<2;j++) {
            std::pair<int,int>new_pos={pos.first+i,pos.second+j};
            if (new_pos.first<0 || new_pos.second<0 || new_pos.first>15 || new_pos.second>11 ) {
                continue;
            }
            if (navigation_map[pos_to_index(new_pos)]==0) {
                result.push_back(pos_to_index(new_pos));
            }
        }
    }
    return result;
}

void NavigationAgent::astar(Vector2 pos) {
    curr_path.clear();
    auto start=global_to_tile_pos(owner->get_position());
    auto target=global_to_tile_pos(pos);
    std::priority_queue<DataTrio, std::vector<DataTrio>, std::greater<DataTrio>> open;
    std::unordered_map<int,float>g;
    std::unordered_map<int,int>came_from;
    g[pos_to_index(start)]=0;
    open.push({diagonal_heuristics(start,target),0,pos_to_index(start)});
    while (!open.empty()) {
        auto data=open.top();
        open.pop();
        if (data.index==pos_to_index(target)) {
            int curr=pos_to_index(target);
            curr_path.push_back(curr);
            while (curr!=pos_to_index(start)) {
                curr=came_from[curr];
                curr_path.push_back(curr);
            }
            std::ranges::reverse(curr_path);
            return;
        }
        if (data.val>g[data.index]) {
            continue;
        }
        auto curr_pos=index_to_pos(data.index);
        for (auto neighbor:get_neighbors(index_to_pos(data.index))) {
            auto npos=index_to_pos(neighbor);
            auto it=g.find(neighbor);

            const bool diagonal = npos.first != curr_pos.first && npos.second != curr_pos.second;
            auto new_g=data.val+(diagonal ? std::sqrt(2.f) : 1.f);
            if (it==g.end() || new_g<it->second) {
                g[neighbor]=new_g;
                came_from[neighbor]=data.index;
                open.push({new_g+diagonal_heuristics(npos,target),new_g,neighbor});
            }
        }
    }
}

Vector2 NavigationAgent::get_next_move(Vector2 target) {
    auto target_tile=global_to_tile_pos(target);
    if (target_tile != last_target_tile) {
        last_target_tile=target_tile;
        astar(target);
    }
    if (curr_path.empty()) {
        return {0,0};
    }
    Vector2 next_pos = pos_to_global(index_to_pos(curr_path.front()));
    while (std::hypot(next_pos.x - owner->get_position().x, next_pos.y - owner->get_position().y) < 2) {
        curr_path.erase(curr_path.begin());
        if (curr_path.empty()) {
            return {0.f, 0.f};
        }
        next_pos = pos_to_global(index_to_pos(curr_path.front()));
    }
    Vector2 help={next_pos.x-owner->get_position().x,next_pos.y-owner->get_position().y};
    return VectorTools::normalise(help);
}

bool NavigationAgent::is_walking() const {
    return curr_path.empty();
}
