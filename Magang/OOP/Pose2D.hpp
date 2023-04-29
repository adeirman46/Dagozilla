#ifndef POSE2D_H
#define POSE2D_H
#include <iostream>

class Pose2D
{
private:
    // attributes
    double x;   // x-coordinate
    double y;   // y-coordinate
    double ort; // orientation (angle in degrees)

public:
    // default constructor using initialization list
    Pose2D();
    // overloaded constructor
    Pose2D(double x, double y, double ort);
    // getters
    double get_x();
    double get_y();
    double get_ort();
    // setters
    void set_x(double x);
    void set_y(double y);
    void set_ort(double ort);
    // operator ==
    bool operator==(Pose2D &other);
    // operator +
    Pose2D operator+(Pose2D &other);
};

#endif POSE2D_H