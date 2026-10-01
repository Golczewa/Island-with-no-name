//
// Created by golczewa on 1.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_PROP_H
#define ISLAND_WITH_NO_NAME_PROP_H
#include <string>

#include "raylib.h"


class Prop {
	Vector2 position;
	Texture2D sprite;
public:
	Prop(std::string sprite_path,Vector2 pos);
};


#endif //ISLAND_WITH_NO_NAME_PROP_H