//
// Created by golczewa on 1.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_MAPS_H
#define ISLAND_WITH_NO_NAME_MAPS_H
#include <vector>

#include "prop.h"
#include "memory"

struct MapData {
	std::string tiles_path;
	std::vector<int> tiles;
	int tile_number;
	std::vector<std::pair<Vector2,std::string>> props;
};

struct MapLibrary {
	MapData map1={
		"assets/sprites/tile_test.png",
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
		0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		3,
		{{Vector2(16,16),"assets/sprites/palm.png"}}
	};
};

#endif //ISLAND_WITH_NO_NAME_MAPS_H