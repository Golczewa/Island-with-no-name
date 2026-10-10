//
// Created by golczewa on 27.09.2026.
//

#ifndef ISLAND_WITH_NO_NAME_PLAYER_H
#define ISLAND_WITH_NO_NAME_PLAYER_H
#include "raylib.h"
#include "../tools/animation.h"
#include "../tools/body.h"
#include "../tools/collisionWorld.h"

class Game;

class Player:public Body {
    const int max_health=6;
    int health=max_health;
    int sword_dmg=2;
    Vector2 position={.x =128,.y = 128};
    Vector2 velocity={0,0};
    Collision collision={{position.x,position.y,16,16},LAYER_0,LAYER_0,true,true,this};
    Collision weapon_area={{position.x,position.y+16,20,20},LAYER_0,LAYER_0,false,true,this};
    const int frames_count=10;

    Texture2D sprite=LoadTexture("assets/sprites/guy.png");
    Rectangle frames={0,0,static_cast<float>(sprite.width)/frames_count,static_cast<float>(sprite.height)};
    AnimatedSprite animated_sprite=AnimatedSprite(frames_count,frames,sprite);

    Texture2D weaponless_sprite=LoadTexture("assets/sprites/guy_weaponless.png");
    Rectangle weapon_rec={0,0,static_cast<float>(weaponless_sprite.width)/4,static_cast<float>(sprite.height)};
    AnimatedSprite weaponless=AnimatedSprite(4,weapon_rec,weaponless_sprite);

    Texture2D slash_sprite=LoadTexture("assets/sprites/guy_slash.png");
    Rectangle slash_rec={0,0,static_cast<float>(weaponless_sprite.width)/7,static_cast<float>(sprite.height)};
    AnimatedSprite slash=AnimatedSprite(7,slash_rec,slash_sprite);

    float speed=1;
    enum Stance {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    Stance stance=DOWN;
    Game* game;
public:
    Player(Game* game_);
    ~Player() override;
    void draw();
    void process();
    void teleport_to(Vector2 pos);
    void move_to_room();
    void take_damage(int dmg);
    [[nodiscard]] Vector2 get_position() const;
    void attack();

};


#endif //ISLAND_WITH_NO_NAME_PLAYER_H
