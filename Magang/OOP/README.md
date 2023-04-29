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
   This file used for creating class Player. This class in inherited from parent class _SoccerRobot_.
