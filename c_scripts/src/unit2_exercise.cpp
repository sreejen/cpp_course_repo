#include "rosbot_control/rosbot_class.h"
#include <ros/ros.h>
#include <string>
#include <list>
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char **argv){
    ros::init(argc,argv, "rosbot_node");

    RosbotClass rosbot;

    map<double,float> time_pos;

    float x_1 = rosbot.get_position(1);
    double time_x_1 = rosbot.get_time();

    // time_pos[time_x] = x;

    // float coordinate_y = rosbot.get_position(2);

    // ROS_INFO_STREAM(coordinate_x << " and " << coordinate_y);
    
    rosbot.move();

    float x_2 = rosbot.get_position(1);
    double time_x_2 = rosbot.get_time();

    double mean_s = (x_2 - x_1)/(time_x_2-time_x_1);
    ROS_INFO_STREAM("Speed is: "<< (mean_s<1));

    // x = rosbot.get_position(1);
    // time_x = rosbot.get_time();

    // time_pos[time_x] = x;

    // float coordinate_x_2 = rosbot.get_position(1);
    // float coordinate_y_2 = rosbot.get_position(2);

    // ROS_INFO_STREAM(coordinate_x_2 << " and " << coordinate_y_2);
    // for( auto item: time_pos)
    //     ROS_INFO_STREAM(item.first<<" "<<item.second<<endl);
    return 0;
}