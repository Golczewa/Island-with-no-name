//
// Created by golczewa on 1.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_PROP_H
#define ISLAND_WITH_NO_NAME_PROP_H
#include <string>

#include "raylib.h"
#include "../tools/body.h"
#include "../tools/collisionWorld.h"


class Prop :public Body{
	Vector2 position;
	Texture2D sprite;
    Collision collision={{position.x,position.y,16,16},LAYER_0,LAYER_0,true,true,this};

public:
	Prop(Vector2 pos,const std::string& sprite_path="");
	~Prop() override;
	void draw();
	[[nodiscard]] Vector2 get_position() const;
};


#endif //ISLAND_WITH_NO_NAME_PROP_H