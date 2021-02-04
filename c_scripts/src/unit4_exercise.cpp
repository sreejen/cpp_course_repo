#include "rosbot_control/rosbot_class.h"
#include <list>
#include <ros/ros.h>
using namespace std;

list<float> move_and_inform(RosbotClass rosbot, int n_secs) {
  rosbot.move_forward(n_secs);
  float x = rosbot.get_position(1);
  float y = rosbot.get_position(2);
  list<float> result({x, y});
  //   list<float> result = rosbot.get_position_full();
  return result;
}
string trajectory(RosbotClass rosbot) {
  rosbot.turn("clockwise", 3);
  cout << "Turn completed " << endl;
  rosbot.move_forward(2.0);
  cout << "Move completed" << endl;
  rosbot.turn("counterclockwise", 3);
  cout << "Turn completed" << endl;
  rosbot.move_forward(10.0);
  rosbot.turn("clockwise", 2);
  rosbot.move_forward(3.0);

  string message = "Trajectory was succesful!!";
  return message;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "node_name");

  RosbotClass robotobject;

  string m = trajectory(robotobject);
  cout << m << endl;

  //   list<float> co = move_and_inform(robotobject, 1);

  //   for (float x : co) {
  // cout << x << "  ";
  //   }

  return 0;
}
