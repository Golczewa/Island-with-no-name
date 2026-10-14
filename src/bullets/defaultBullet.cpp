//
// Created by golczewa on 14.10.2026.
//

#include "defaultBullet.h"

DefaultBullet::DefaultBullet(Vector2 pos, Vector2 vel) {
    position=pos;
    velocity=vel;
    sprite=LoadTexture("TODO");
}

void DefaultBullet::process() {

}
