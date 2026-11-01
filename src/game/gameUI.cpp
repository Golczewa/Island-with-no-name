//
// Created by golczewa on 26.10.2026.
//

#include "gameUI.h"

GameUI::GameUI(Player *player):player_(player) {
}

void GameUI::process() {
    hearth_rec.width=hearth.width*player_->get_health_precent();
}

void GameUI::draw() {
    DrawTextureRec(hearth,hearth_rec,hearth_pos,WHITE);
    if (restart) {
        DrawText("Press R key to restart", 32, 96, 16, ORANGE);
    }
    if (won) {
        DrawText("YOU WON!", 48, 32, 32, DARKBLUE);
    }
    if (lost) {
        DrawText("YOU DIED!", 48, 32, 32, RED);
    }
}

void GameUI::hide_all() {
    restart=false;
    won=false;
    lost=false;
}

void GameUI::show_restart() {
    restart=true;
}

void GameUI::show_dead() {
    lost=true;
}

void GameUI::show_victory() {
    won=true;
}
