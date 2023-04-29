#include "Keeper.hpp"
#include "Player.hpp"
#include "SoccerRobot.hpp"
#include "Pose2D.hpp"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    Keeper keeper;
    Pose2D curr_pos_keeper;

    // Keeper Move
    curr_pos_keeper = keeper.get_pos();
    cout << "INITIAL POSITION (KEEPER)\n"
         << "X: " << curr_pos_keeper.get_x() << "\nY: " << curr_pos_keeper.get_y()
         << "\nOrientation: " << curr_pos_keeper.get_ort() << "\n";

    cout << "\nAFTER MOVE (KEEPER)\n";
    Pose2D pos_keeper(100, 100, 30);
    keeper.move(pos_keeper);
    curr_pos_keeper = keeper.get_pos();
    cout << "X: " << curr_pos_keeper.get_x() << "\nY: " << curr_pos_keeper.get_y()
         << "\nOrientation: " << curr_pos_keeper.get_ort() << "\n";

    // Keeper check battery
    cout << "\nCHECK BATTERY (KEEPER)\n";
    cout << "Battery: " << keeper.get_battery_perc() << "\n";

    // Keeper didn't saved the ball
    cout << "\nCONDITION WHEN DIDN'T SAVED THE BALL (KEEPER)\n";
    cout << "Expander status: " << keeper.get_expander_status() << "\n";
    keeper.save_ball();

    // Keeper saved the ball;
    cout << "\nCONDITION WHEN SAVED THE BALL (KEEPER)\n";
    keeper.set_expander_status(true);
    cout << "Expander status: " << keeper.get_expander_status() << "\n";
    keeper.save_ball();

    // Current battery level after trying to catch the ball twice
    cout << "\nCURRENT BATTERY LEVEL AFTER TRYING TO SAVED THE BALL TWICE (KEEPER)\n";
    cout << "Battery: " << keeper.get_battery_perc() << "\n";

    // Recharge battery 30 seconds (increase 1%/s)
    cout << "\nBATTERY AFTER CHARGING 30 S (KEEPER)\n";
    keeper.recharge(30);
    cout << "Battery: " << keeper.get_battery_perc() << "\n";

    // Keeper celebrate
    cout << "\nCELEBRATION (KEEPER)\n";
    keeper.celebrate();

    // Player
    Player player1(0, 0, 0, 60, Pose2D(), 4, true, 100);
    Player player2;

    // Get player battery percentage
    cout << "\nINITIAL BATTERY LEVEL (PLAYER)\n";
    cout << "Player1: " << player1.get_battery_perc() << "\nPlayer2: " << player2.get_battery_perc() << "\n";

    // Check ball possession
    cout << "\nCHECK BALL POSSESSION (PLAYER)\n";
    cout << "Player1: " << player1.get_is_ball_on_possession() << "\nPlayer2: " << player2.get_is_ball_on_possession() << "\n";

    // Get capacitor battery percentage
    cout << "\nCAPACITOR CHARGE (%) (PLAYER)\n";
    cout << "Player1: " << player1.get_capacitor_charge_perc() << "\nPlayer2: " << player2.get_capacitor_charge_perc() << "\n";

    // Let say player1 got the ball and pass into player2
    cout << "\nPLAYER1 GOT THE BALL AND THEN KICK INTO PLAYER2 (PLAYER)\n";
    player1.get_ball();
    player1.kick();
    player2.get_ball();

    // Get current capacitor battery percentage
    cout << "\nCAPACITOR CHARGE (%) AFTER PLAYER1 KICKED (PLAYER)\n";
    cout << "Player1: " << player1.get_capacitor_charge_perc() << "\nPlayer2: " << player2.get_capacitor_charge_perc() << "\n";

    // Charge capacitor player1 and player2
    cout << "\nCHARGING CAPACITOR OF PLAYER1 AND PLAYER2 (PLAYER)\n";
    player1.charge_capacitor();
    player2.charge_capacitor();
    cout << "Player1: " << player1.get_capacitor_charge_perc() << "\nPlayer2: " << player2.get_capacitor_charge_perc() << "\n";

    // Player2 going nearer into goalposts (gawang)
    cout << "\nPLAYER2 MOVING INTO NEAR GOALPOSTS (PLAYER)\n";
    Pose2D a(200, 150, 0), b(100, 300, 100);
    Pose2D c = a + b;
    player2.move(c);
    cout << "X: " << player2.get_pos().get_x() << "\nY: " << player2.get_pos().get_y()
         << "\nOrientation: " << player2.get_pos().get_ort() << "\n";

    // Player2 kicked the ball and goal
    cout << "\nPLAYER2 KICKED THE BALL AND GOAL (PLAYER & KEEPER)\n";
    player2.kick();
    player1.celebrate();
    player2.celebrate();
    keeper.celebrate();

    // Current capacitor charge percentage
    cout << "\nCURRENT CAPACITOR CHARGE (%) (PLAYER)\n";
    cout << "Player1: " << player1.get_capacitor_charge_perc() << "\nPlayer2: " << player2.get_capacitor_charge_perc() << "\n";

    // Number of robot that instantiated
    cout << "\nNUMBER ROBOTS THAT INSTANTIATED (PLAYER & KEEPER)\n";
    cout << player1.get_robot_count() << "\n";
}