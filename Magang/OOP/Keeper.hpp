#ifndef KEEPER_H
#define KEEPER_H
#include "SoccerRobot.hpp"
#include <iostream>

class Keeper : public SoccerRobot
{
private:
    // attributes
    bool expander_status;

public:
    // default constructor
    Keeper();
    // overloaded constructor
    Keeper(bool expander_status, Pose2D pos, int wheel_count, bool camera_status, double battery_perc);
    // getter
    bool get_expander_status();
    // setter
    void set_expander_status(bool expander_status);
    // methods
    void save_ball();
    void celebrate();
};

#endif KEEPER_H