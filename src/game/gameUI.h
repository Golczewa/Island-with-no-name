//
// Created by golczewa on 26.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_GAMEUI_H
#define ISLAND_WITH_NO_NAME_GAMEUI_H
#include "player.h"
#include "raylib.h"


class GameUI {
    Player* player_;
    const Vector2 hearth_pos={0,0};
    Texture2D hearth=LoadTexture("assets/sprites/le_bar.png");
    Rectangle hearth_rec={hearth_pos.x,hearth_pos.y,static_cast<float>(hearth.width),static_cast<float>(hearth.height)};
public:
    GameUI(Player* player);
    void process();
    void draw();
};


#endif //ISLAND_WITH_NO_NAME_GAMEUI_H
