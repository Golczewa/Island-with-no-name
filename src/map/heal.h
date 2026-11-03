//
// Created by golczewa on 2.11.2026.
//

#ifndef ISLAND_WITH_NO_NAME_HEAL_H
#define ISLAND_WITH_NO_NAME_HEAL_H
#include "raylib.h"
#include "../tools/body.h"
#include "../tools/collisionWorld.h"
#include "../game/player.h"


class Heal:public Body{
    int heal_amount=2;
    Vector2 position{};
    Texture2D sprite=LoadTexture("assets/sprites/helth.png");
    const Vector2 collision_offset={7,7};
    Collision collision={};
    bool to_remove=false;
    Timer timer;

public:
    Heal(Vector2 pos);
    ~Heal() override;
    void draw();
    void process();
    void register_collision();
    void unregister_collision();
    [[nodiscard]] bool is_to_remove() const;
};


#endif //ISLAND_WITH_NO_NAME_HEAL_H
