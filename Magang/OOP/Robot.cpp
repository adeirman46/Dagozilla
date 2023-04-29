#include <iostream>
#include <cmath>
#include "Pose2D.hpp"
#include "SoccerRobot.hpp"
#include "Keeper.hpp"
#include "Player.hpp"

using namespace std;

// default constructor using initialization list
Pose2D::Pose2D() : x(0), y(0), ort(0){}

// overloaded constructor
Pose2D::Pose2D(double x, double y, double ort) : x(x), y(y), ort(ort){}

// getters
double Pose2D::get_x(){
    return this->x;
}
double Pose2D::get_y(){
    return this->y;
}
double Pose2D::get_ort()
{
    return this->ort;
}

// setters
void Pose2D::set_x(double x)
{
    this->x = x;
}
void Pose2D::set_y(double y)
{
    this->y = y;
}
void Pose2D::set_ort(double ort)
{
    this->ort = ort;
}

// operator ==
bool Pose2D::operator==(Pose2D &other)
{
    return x == other.x && y == other.y && ort == other.ort;
}

// operator +
Pose2D Pose2D::operator+(Pose2D &other)
{
    double new_x = x + other.x;
    double new_y = y + other.y;
    double new_ort = fmod(ort + other.ort, 360);
    return Pose2D(new_x, new_y, new_ort);
}

// default constructor
SoccerRobot::SoccerRobot(): pos(Pose2D()), wheel_count(4), camera_status(true), battery_perc(100){
    this->robot_count += 1;
}

// overloaded constructor
SoccerRobot::SoccerRobot(Pose2D pos, int wheel_count, bool camera_status, double battery_perc) : pos(pos),
wheel_count(wheel_count), camera_status(camera_status), battery_perc(battery_perc)
{
    this->robot_count += 1;
}

// getters
Pose2D SoccerRobot::get_pos(){
    return this->pos;
}
int SoccerRobot::get_wheel_count()
{
    return this->wheel_count;
}
bool SoccerRobot::get_camera_status()
{
    return this->camera_status;
}
double SoccerRobot::get_battery_perc()
{
    return this->battery_perc;
}
int SoccerRobot::get_robot_count()
{
    return this->robot_count;
}
        // setters
void SoccerRobot::set_pos(Pose2D pos)
{
    this->pos = pos;
}
void SoccerRobot::set_wheel_count(int wheel_count)
{
    this->wheel_count = wheel_count;
}
void SoccerRobot::set_camera_status(bool camera_status)
{
    this->camera_status = camera_status;
}
void SoccerRobot::set_battery_perc(double battery_perc)
{
    this->battery_perc = battery_perc;
}
        // method
void SoccerRobot::move(Pose2D pos)
{
    set_pos(pos);
}
void SoccerRobot::recharge(int time_in_s)
{
    if (this->battery_perc > 100)
    {
        this->battery_perc = 100;
    }
    else
    {
        this->battery_perc += time_in_s * 1; // let 1 seconds 1% increases of battery
    }
}
// virtual deconstruction
// releasing resources when an object is destroyed
SoccerRobot::~SoccerRobot()
{
}
// pure virtual function
// any class that inherits from SoccerRobot must implement this function
 // a class that contain pure virtual function cannot be instantiated
// SoccerRobot::celebrate() = 0;

// default constructor
Keeper::Keeper(): SoccerRobot(), expander_status(false){}
// overloaded constructor
Keeper::Keeper(bool expander_status, Pose2D pos, int wheel_count, bool camera_status, double battery_perc) : SoccerRobot(pos, wheel_count, camera_status, battery_perc), expander_status(expander_status){
}
// getter
bool Keeper::get_expander_status(){
    return this->expander_status;
}
// setter
void Keeper::set_expander_status(bool expander_status){
    this->expander_status = expander_status;
}
// methods
void Keeper::save_ball()
{
    if (this->expander_status == true)
    {
        cout << "Keeper saved the ball.\n";
    }
    else
    {
        cout << "Keeper didn't saved the ball.\n";
    }
    // Let say after trying save the ball,
    // the battery decrease 20%
    double battery = get_battery_perc();
    set_battery_perc(battery - 20);
}

void Keeper::celebrate()
{
    cout << "Tú eres el mejor portero del mundo.\n";
}

// default constructor
Player::Player() : SoccerRobot(), dribble_status(0), kicker_status(0),
    is_ball_on_possession(0), capacitor_charge_perc(0){
}
// overloaded constructor
Player::Player(bool dribble_status, bool kicker_status, bool is_ball_on_possession, double capacitor_charge_perc,
    Pose2D pos, int wheel_count, bool camera_status, double battery_perc) : SoccerRobot(pos, wheel_count, camera_status, battery_perc),
    dribble_status(dribble_status), kicker_status(kicker_status), is_ball_on_possession(is_ball_on_possession), capacitor_charge_perc(capacitor_charge_perc)
{}
// getters
bool Player::get_dribble_status()
{
    return this->dribble_status;
}
bool Player::get_kicker_status()
{
    return this->kicker_status;
}
bool Player::get_is_ball_on_possession()
{
    return this->is_ball_on_possession;
}
double Player::get_capacitor_charge_perc()
{
    return this->capacitor_charge_perc;
}
// setters
void Player::set_dribble_status(bool dribble_status)
{
    this->dribble_status = dribble_status;
}
void Player::set_kicker_status(bool kicker_status)
{
    this->kicker_status = kicker_status;
}
void Player::set_is_ball_on_possession(bool is_ball_on_possession)
{
    this->is_ball_on_possession = is_ball_on_possession;
}
void Player::set_capacitor_charge_perc(double capacitor_charge_perc)
{
    this->capacitor_charge_perc = capacitor_charge_perc;
}
        // method
void Player::kick()
{
    if (this->capacitor_charge_perc >= 50 && this->is_ball_on_possession == true)
    {
        this->kicker_status = true;
        cout << "Player kicked.\n";
        this->capacitor_charge_perc -= 50;
        this->dribble_status = false;
        this->kicker_status = false;
        this->is_ball_on_possession = false;
    }
}
void Player::get_ball()
{
    this->is_ball_on_possession = true;
    this->dribble_status = true;
    cout << "Ball on possession.\n";
}
void Player::celebrate()
{
    cout << "Siuu\n";
}
void Player::charge_capacitor()
{
    this->capacitor_charge_perc = 100;
}

// initialize robot_count using "::" notation
int SoccerRobot::robot_count = 0;
