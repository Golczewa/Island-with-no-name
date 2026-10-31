//
// Created by golczewa on 26.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_GAMEUI_H
#define ISLAND_WITH_NO_NAME_GAMEUI_H
#include "player.h"
#include "raylib.h"


class GameUI {
    Player* player_;
    const Vector2 hearth_pos={8,196};
    Texture2D hearth=LoadTexture("assets/sprites/hearths.png");
    Rectangle hearth_rec={0,0,static_cast<float>(hearth.width),static_cast<float>(hearth.height)};
    bool restart=false;
public:
    GameUI(Player* player);
    void process();
    void draw();
    void show_restart();
    void hide_restart();
};


#endif //ISLAND_WITH_NO_NAME_GAMEUI_H
