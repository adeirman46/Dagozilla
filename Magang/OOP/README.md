# OOP Soccer Robot

This repository consists 2 files CPP format and 4 files hpp format

## HPP Format Files

1. **Pose2D** <br>
   This file used for creating class Pose2D.
   Class Pose2D has attributes related into positioning a robot, such as x and y coordinates and orientation. <br>
   This class also contain operator + and == to whether add pose with another pose or compare one pose into another pose to check whether robot is changing pose or not. <br>

2. **SoccerRobot** <br>
   This file used for creating class SoccerRobot. This class consists of position, wheel_count, camera_status, battery_percentage, and robot_count attributes. <br>
   This class also consists move() and recharge()method, we also make pure virtual function celebrate() which makes this class cannot be instantiated and inherited class must implement this function. <br>

3. **Player** <br>
   This file used for creating class Player. This class in inherited from parent class _SoccerRobot_. This class has additional attributes such as dribble_status, kicker_status, is_ball_on_possession, and capacitor_charge_percentage. <br>
   This file also contains method kick(), get_ball(), celebrate(), and charge_capacitor(). <br>

4. **Keeper** <br>
   This file used for creating class Keeper. This class also child class from _SoccerRobot_ but only has additional attributes expander_status.
   This class has method save_ball() and celebrate() <br>

## CPP Format Files

1. **Robot.cpp** <br>
   This file used for implementing algorithms for all hpp files. <br>

2. **Main.cpp** <br>
   This file is main program. This file consists practical aspects, such as what is the output when robot move(), celebrate(), recharge(), expanding_status(), etc. <br>

## How to Run <br>

You can run and compile all of this programs by specifying this command in your terminal. <br>
`g++ -o output_file main.cpp Robot.cpp`.
