//
// Created by golczewa on 9.10.2026.
//

#include "timer.h"

#include "raylib.h"

void Timer::process() {
    if (running) {
        curr_time+=GetFrameTime();
        if (curr_time>=cooldown) {
            running=false;
        }
    }
}

void Timer::start(float time) {
    cooldown=time;
    curr_time=0;
    running=true;
}

void Timer::stop() {
    running=false;
}

bool Timer::is_running() const {
    return running;
}
