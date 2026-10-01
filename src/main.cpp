#include <iostream>
#include <memory>

#include "map/maps.h"
#include "raylib.h"
#include "player.h"
#include "map/tileMap.h"

int main(){
    const int screenWidth = 930;
    const int screenHeight = 520;
    const int gameWidth = 256;
    const int gameHeight = 192;
    InitWindow(screenWidth, screenHeight, "Island with no name");
    SetTargetFPS(60);
    RenderTexture2D target=LoadRenderTexture(gameWidth,gameHeight);
    SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);
    Shader crt=LoadShader(0,"assets/shaders/crt.fs");
    auto maps=std::make_unique<Maps>();
    auto tilemap=std::make_unique<TileMap>("assets/sprites/tile_test.png",3,maps->map1);
    auto player=std::make_unique<Player>();
    while (!WindowShouldClose())
    {
        BeginTextureMode(target);
            ClearBackground(WHITE);
            player->movement();
            tilemap->draw();
            player->draw();
        EndTextureMode();
        float scale = std::min(
        screenWidth / gameWidth,
        screenHeight/ gameHeight
        );

        Rectangle source = {
            0.0f, 0.0f,
            static_cast<float>(target.texture.width),
            -static_cast<float>(target.texture.height)
        };
        Rectangle dest = {
            (screenWidth  - gameWidth  * scale) * 0.5f,
            (screenHeight - gameHeight * scale) * 0.5f,
            gameWidth  * scale,
            gameHeight * scale
        };
        BeginDrawing();
            ClearBackground(BLACK);
            BeginShaderMode(crt);
                DrawTexturePro(target.texture, source, dest, {0, 0}, 0.0f, WHITE);
            EndShaderMode();
        EndDrawing();
    }
    UnloadShader(crt);
    UnloadRenderTexture(target);
    CloseWindow();
    return 0;
}
