#include "rosbot_control/rosbot_class.h"
#include <ros/ros.h>

#include <string>

using namespace std;

class AvoidWall {
public:
  RosbotClass rosbot;

  float laser_front;

  void avoid_wall();
};

void AvoidWall::avoid_wall() {
  rosbot.move_forward(1);

  while (rosbot.get_laser(0) > 1.75) {
    rosbot.move_forward(1);
  }

  rosbot.turn("counterclockwise", 3);
  rosbot.move_forward(5);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "Rosbot_move_node");

  AvoidWall avoid_obj;
  avoid_obj.avoid_wall();
}