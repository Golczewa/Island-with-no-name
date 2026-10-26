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
}
