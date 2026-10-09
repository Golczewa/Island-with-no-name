//
// Created by golczewa on 9.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_TIMER_H
#define ISLAND_WITH_NO_NAME_TIMER_H


class Timer {
    bool running=false;
    float cooldown=0;
    float curr_time=0;
public:
    void process();
    void start(float time);
    void stop();
    [[nodiscard]] bool is_running() const;
};


#endif //ISLAND_WITH_NO_NAME_TIMER_H
