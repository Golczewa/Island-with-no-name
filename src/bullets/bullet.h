//
// Created by golczewa on 11.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_BULLET_H
#define ISLAND_WITH_NO_NAME_BULLET_H
#include "raylib.h"
#include "../tools/body.h"
#include "../tools/collisionWorld.h"


class Bullet:public Body {
protected:
    Vector2 position{};
    Texture2D sprite{};
    Collision collision_{};
    Vector2 velocity{};
    Color color=WHITE;
    bool to_remove=false;
    float speed=2;
    int dmg=1;
public:
    virtual void process()=0;
    void draw();
    [[nodiscard]] bool is_to_remove() const;
    ~Bullet() override;

};


#endif //ISLAND_WITH_NO_NAME_BULLET_H
