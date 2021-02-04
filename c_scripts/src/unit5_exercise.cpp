#include "rosbot_control/rosbot_class.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "rosbot_node");

  RosbotClass rosbot;

  
  rosbot.move_forward(3);

  float *pointer;

  pointer = rosbot.get_laser_full();
  ROS_INFO_STREAM("Laser values: ");
  for (int i = 0; i < 720; i++) {
    ROS_INFO_STREAM(*pointer);
    pointer++;
  }

//   rosbot.move_forward(3);

//   float arr[2];
//   arr[0] = rosbot.get_laser(0);
//   arr[1] = rosbot.get_laser(719);

//   cout<<"0 : "<<arr[0]<<endl;
//   cout<<"1 : "<<arr[1]<<endl;
    
  return 0;
}