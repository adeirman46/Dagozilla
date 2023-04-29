#ifndef PLAYER_H
#define PLAYER_H
#include "SoccerRobot.hpp"
#include <iostream>

class Player : public SoccerRobot
{
private:
    // attributes
    bool dribble_status;
    bool kicker_status;
    bool is_ball_on_possession;
    double capacitor_charge_perc;

public:
    // default constructor
    Player();
    // overloaded constructor
    Player(bool dribble_status, bool kicker_status, bool is_ball_on_possession, double capacitor_charge_perc,
           Pose2D pos, int wheel_count, bool camera_status, double battery_perc);
    // getters
    bool get_dribble_status();
    bool get_kicker_status();
    bool get_is_ball_on_possession();
    double get_capacitor_charge_perc();
    // setters
    void set_dribble_status(bool dribble_status);
    void set_kicker_status(bool kicker_status);
    void set_is_ball_on_possession(bool is_ball_on_possession);
    void set_capacitor_charge_perc(double capacitor_charge_perc);
    // method
    void kick();
    void get_ball();
    void celebrate();
    void charge_capacitor();
};

#endif PLAYER_H