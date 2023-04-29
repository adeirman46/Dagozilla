#ifndef SOCCERROBOT_H
#define SOCCERROBOT_H
#include "Pose2D.hpp"
#include <iostream>

class SoccerRobot
{
private:
    // attributes
    Pose2D pos; // position robot in 2D space // SoccerRobot just using Pose2D not inherits which is no problem
    int wheel_count;
    bool camera_status; // camera status: on/off
    double battery_perc;
    static int robot_count; // track number robot that already created
public:
    // default constructor
    SoccerRobot();
    // overloaded constructor
    SoccerRobot(Pose2D pos, int wheel_count, bool camera_status, double battery_perc);
    // getters
    Pose2D get_pos();
    int get_wheel_count();
    bool get_camera_status();
    double get_battery_perc();
    int get_robot_count();
    // setters
    void set_pos(Pose2D pos);
    void set_wheel_count(int wheel_count);
    void set_camera_status(bool camera_status);
    void set_battery_perc(double battery_perc);
    // method
    void move(Pose2D pos);
    void recharge(int time_in_s);
    // virtual deconstruction
    // releasing resources when an object is destroyed
    virtual ~SoccerRobot();
    // pure virtual function
    // any class that inherits from SoccerRobot must implement this function
    // a class that contain pure virtual function cannot be instantiated
    virtual void celebrate() = 0;
};

#endif SOCCERROBOT_H