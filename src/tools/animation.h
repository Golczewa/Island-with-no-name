//
// Created by golczewa on 28.09.2026.
//

#ifndef ISLAND_WITH_NO_NAME_ANIMATION_H
#define ISLAND_WITH_NO_NAME_ANIMATION_H
#include "raylib.h"

struct Animation {
    Animation(int _begin_frane,int _end_frame,int _frame_count,Rectangle& _frames,Texture2D& _sprite)
    :begin_frame(_begin_frane),end_frame(_end_frame),frame_count(_frame_count),frames(_frames),sprite(_sprite) {}
    int begin_frame=0;
    int end_frame=0;
    int frame_count=0;
    Rectangle& frames;
    Texture2D& sprite;
    float frame_time=0;
    float speed=8;
    int curr_frame=0;
    void play() {
        frames.x=static_cast<float>(curr_frame)*static_cast<float>(sprite.width)/frame_count;
        frame_time+=GetFrameTime();
        if (frame_time>1.0f/speed) {
            frame_time=0;
            curr_frame++;
            if (curr_frame>end_frame) {
                curr_frame=begin_frame;
            }
        }
    }
};


#endif //ISLAND_WITH_NO_NAME_ANIMATION_H