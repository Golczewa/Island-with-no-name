//
// Created by golczewa on 14.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_DEFAULTBULLET_H
#define ISLAND_WITH_NO_NAME_DEFAULTBULLET_H
#include "bullet.h"
#include "../tools/timer.h"


class DefaultBullet:public Bullet {
    Timer color_switch_timer{};
public:
    DefaultBullet(Vector2 pos,Vector2 vel);
    void process() override;
};


#endif //ISLAND_WITH_NO_NAME_DEFAULTBULLET_H
