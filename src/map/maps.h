//
// Created by golczewa on 1.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_MAPS_H
#define ISLAND_WITH_NO_NAME_MAPS_H
#include <vector>

#include "prop.h"
#include "memory"
#include "../enemies/enemyFactory.h"

struct Paths {
	int upper_room_id=-1;
	int down_room_id=-1;
	int left_room_id=-1;
	int right_room_id=-1;

};

struct MapData {
	int id;
	std::string tiles_path;
	std::vector<int> tiles;
	std::vector<int> cols;
	int tile_number;
	std::vector<std::pair<Vector2,std::string>> props;
	Paths paths;
	std::vector<std::pair<EnemyFactory::Enemies,Vector2>> enemies;
};

struct MapLibrary {
	std::vector<MapData> maps;
	MapData map1={
		1,
		"assets/sprites/tile_test.png",
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,
		1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,
		2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{0,0,1},
		3,
		{{Vector2(16,16),"assets/sprites/palm.png"},
		{Vector2(128,112),"assets/sprites/camp.png"},
		{Vector2(32,16),"assets/sprites/palm.png"},
		{Vector2(96,16),"assets/sprites/palm.png"}},
		{3,-1,2,-1},
		{}
	};
	MapData map2={
		2,
		"assets/sprites/tile_test.png",
		{2,2,0,0,0,1,1,1,1,1,1,1,1,1,1,1,
		2,2,0,0,1,1,1,1,1,1,1,1,1,1,1,1,
		2,2,0,0,1,1,1,1,1,1,1,1,1,1,1,1,
		2,2,0,0,1,1,1,1,1,1,1,1,1,1,1,1,
		2,2,0,0,1,1,1,1,1,1,1,1,1,1,1,1,
		2,2,0,0,1,1,1,1,1,1,1,1,1,1,1,1,
		2,2,0,0,0,1,1,1,1,1,1,1,1,1,1,1,
		2,2,2,0,0,1,1,0,0,1,1,1,1,1,1,1,
		2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,
		2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,
		2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{0,0,1},
		3,
		{{Vector2(12*16,3*16),"assets/sprites/palm.png"}},
		{-1,-1,-1,1},
		{{EnemyFactory::Enemies::CREATURE,{64,64}}}
	};
	MapData map3={
		3,
		"assets/sprites/tile_test.png",
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,
		2,2,0,0,0,2,2,2,0,0,0,2,2,2,2,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,1},
		3,
		{{Vector2(16,10*16),"assets/sprites/palm.png"}},
		{-1,1,-1,-1},
		{}
	};
	MapLibrary() {
		maps.push_back(map1);
		maps.push_back(map2);
		maps.push_back(map3);
	}
};

#endif //ISLAND_WITH_NO_NAME_MAPS_H