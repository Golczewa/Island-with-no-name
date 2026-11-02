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
		{{Vector2(128,112),"assets/sprites/camp.png"},
		{Vector2(32,16),"assets/sprites/palm.png"},
		{Vector2(128,112),"assets/sprites/camp.png"},
		{Vector2(32,16),"assets/sprites/palm.png"},
		{Vector2(96,16),"assets/sprites/palm.png"},
		{Vector2(10*16,3*16),"assets/sprites/palm.png"},
		{Vector2(13*16,4*16),"assets/sprites/palm.png"}},
		{3,-1,2,5},
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
		{{Vector2(12*16,3*16),"assets/sprites/palm.png"},
		{Vector2(8*16,1*16),"assets/sprites/palm.png"},
		{Vector2(6*16,5*16),"assets/sprites/palm.png"},
		{Vector2(14*16,6*16),"assets/sprites/palm.png"},
		{Vector2(10*16,8*16),"assets/sprites/palm.png"}},
		{4,-1,-1,1},
		{{EnemyFactory::Enemies::CREATURE,{64,64}},
		{EnemyFactory::Enemies::CREATURE,{13*16,8*16}}}
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
		{{Vector2(16,10*16),"assets/sprites/palm.png"},
		{Vector2(3*16,2*16),"assets/sprites/palm.png"},
		{Vector2(5*16,4*16),"assets/sprites/palm.png"},
		{Vector2(12*16,5*16),"assets/sprites/palm.png"},
		{Vector2(9*16,8*16),"assets/sprites/palm.png"},
		{Vector2(13*16,10*16),"assets/sprites/palm.png"}},
		{-1,1,4,6},
		{{EnemyFactory::Enemies::CREATURE,{8*16,4*16}}}
	};
	MapData map4={
		4,
		"assets/sprites/tile_test.png",
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,
		2,2,2,2,0,2,2,2,0,0,0,2,2,2,2,0,
		2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,
		2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,
		2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,
		2,2,2,0,0,0,1,1,1,1,1,1,1,1,1,1,
		2,2,0,0,0,1,1,1,1,1,1,1,1,1,1,1,
		2,2,2,0,1,1,1,1,1,1,1,1,1,1,1,1,
		2,2,2,0,1,1,1,1,1,1,1,1,1,1,1,1,
		2,2,0,0,1,1,1,1,1,1,1,1,1,1,1,1,
		2,2,0,0,0,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,1},
		3,
		{{Vector2(6*16,4*16),"assets/sprites/palm.png"},
		{Vector2(12*16,3*16),"assets/sprites/palm.png"},
		{Vector2(8*16,7*16),"assets/sprites/palm.png"},
		{Vector2(13*16,9*16),"assets/sprites/palm.png"},
		{Vector2(5*16,10*16),"assets/sprites/palm.png"}},
		{-1,2,-1,3},
		{{EnemyFactory::Enemies::CREATURE,{10*16,4*16}},
		{EnemyFactory::Enemies::CREATURE,{9*16,8*16}},
		{EnemyFactory::Enemies::CREATURE,{13*16,6*16}}}
	};
	MapData map5={
		5,
		"assets/sprites/tile_test.png",
		{1,1,1,1,1,1,1,1,1,1,1,1,0,0,2,2,
		1,1,1,1,1,1,1,1,1,1,1,1,0,0,2,2,
		1,1,1,1,1,1,0,0,0,1,1,1,0,2,2,2,
		1,1,1,1,1,0,2,2,2,0,1,1,0,0,2,2,
		1,1,1,1,1,0,2,2,2,2,0,0,0,0,2,2,
		1,1,1,1,1,0,2,2,2,2,0,0,0,0,2,2,
		1,1,1,1,1,0,0,2,2,0,0,0,0,0,2,2,
		0,1,1,1,1,1,0,0,0,0,0,0,0,2,2,2,
		0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,
		0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,
		2,2,2,0,0,0,0,0,2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{0,0,1},
		3,
		{{Vector2(2*16,1*16),"assets/sprites/palm.png"},
		{Vector2(3*16,5*16),"assets/sprites/palm.png"},
		{Vector2(10*16,2*16),"assets/sprites/palm.png"},
		{Vector2(10*16,5*16),"assets/sprites/palm.png"},
		{Vector2(4*16,8*16),"assets/sprites/palm.png"}},
		{6,-1,1,-1},
		{{EnemyFactory::Enemies::CREATURE,{2*16,3*16}},
		{EnemyFactory::Enemies::CREATURE,{6*16,8*16}}}
	};
	MapData map6={
		6,
		"assets/sprites/tile_test.png",
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,0,2,2,2,2,2,2,2,2,2,
		0,2,2,2,2,0,0,0,2,2,2,0,2,2,2,2,
		0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,
		1,1,1,1,1,1,1,1,1,1,0,0,2,2,2,2,
		1,1,1,1,1,1,1,1,1,1,1,0,0,2,2,2,
		1,1,1,1,1,1,1,1,1,1,1,0,0,2,2,2,
		1,1,1,1,1,1,1,1,1,1,1,0,0,0,2,2,
		1,1,1,1,1,1,1,1,1,1,1,0,0,2,2,2,
		1,1,1,1,1,1,1,1,1,1,1,0,0,2,2,2,
		1,1,1,1,1,1,1,1,1,1,1,0,0,0,2,2,
		1,1,1,1,1,1,1,1,1,1,1,0,0,0,2,2},
		{0,0,1},
		3,
		{{Vector2(2*16,3*16),"assets/sprites/palm.png"},
		{Vector2(8*16,4*16),"assets/sprites/palm.png"},
		{Vector2(3*16,5*16),"assets/sprites/palm.png"},
		{Vector2(9*16,7*16),"assets/sprites/palm.png"},
		{Vector2(6*16,9*16),"assets/sprites/palm.png"}},
		{-1,5,3,-1},
		{{EnemyFactory::Enemies::CREATURE,{9*16,3*16}}}
	};
	MapLibrary() {
		maps.push_back(map1);
		maps.push_back(map2);
		maps.push_back(map3);
		maps.push_back(map4);
		maps.push_back(map5);
		maps.push_back(map6);
	}
};

#endif //ISLAND_WITH_NO_NAME_MAPS_H