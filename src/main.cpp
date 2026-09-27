#include <iostream>
#include <memory>

#include "raylib.h"
#include "player.h"

int main(){
    const int screenWidth = 400;
    const int screenHeight = 225;
    InitWindow(screenWidth, screenHeight, "Island with no name");
    SetTargetFPS(60);
    auto player=std::make_unique<Player>();
    while (!WindowShouldClose())
    {
        player->movement();
        BeginDrawing();
            ClearBackground(WHITE);
            player->draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
