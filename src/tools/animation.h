//
// Created by golczewa on 28.09.2026.
//

#ifndef ISLAND_WITH_NO_NAME_ANIMATION_H
#define ISLAND_WITH_NO_NAME_ANIMATION_H
#include <string>
#include <unordered_map>

#include "raylib.h"

class AnimatedSprite {
    Texture2D& sprite;
    Rectangle& frames;
    int frame_count;
    bool hidden=false;
public:
    struct Animation {
        Animation(const std::string& _name,int _begin_frane,int _end_frame,int _frame_count,Rectangle& _frames,Texture2D& _sprite)
        :name(_name),begin_frame(_begin_frane),end_frame(_end_frame),frame_count(_frame_count),frames(_frames),sprite(_sprite) {}
        std::string name;
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
    std::unordered_map<std::string, Animation> animations;
    Animation* curr_animation=nullptr;
    AnimatedSprite(int _frame_count,Rectangle& _frames,Texture2D& _sprite);
    void create_animation(const std::string& _name,int _begin_frame,int _end_frame);
    void play_animation(const std::string& _name);
    void show();
    void hide();
    [[nodiscard]] bool is_hidden() const;
};




#endif //ISLAND_WITH_NO_NAME_ANIMATION_H