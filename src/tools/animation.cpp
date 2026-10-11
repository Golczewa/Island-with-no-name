//
// Created by golczewa on 29.09.2026.
//
#include "animation.h"

#include <stdexcept>

AnimatedSprite::AnimatedSprite(int _frame_count,Rectangle& _frames,Texture2D& _sprite,float speeed)
    :frame_count(_frame_count),frames(_frames),sprite(_sprite),speed(speeed){}

void AnimatedSprite::create_animation(const std::string& _name, int _begin_frame, int _end_frame) {
    auto new_animation=Animation(_name,_begin_frame,_end_frame,frame_count,frames,sprite,speed);
    animations.emplace(_name,new_animation);
}

void AnimatedSprite::play_animation(const std::string& _name) {
    auto anim=animations.find(_name);
    if (anim==animations.end()) {
        throw std::invalid_argument("invalid animation name");
    }
    is_playing=false;
    curr_animation=&anim->second;
    curr_animation->play();
}

void AnimatedSprite::hide() {
    hidden=true;
}

void AnimatedSprite::show() {
    hidden=false;
}

bool AnimatedSprite::is_hidden() const {
    return hidden;
}
