#include "rosbot_control/rosbot_class.h"
#include <ros/ros.h>
#include <list>
using namespace std;

int main(int argc, char **argv){
    ros::init(argc,argv,"node_name");

    RosbotClass robotobject;

    // float x_limit = 2.0;

    robotobject.move_forward(2);
    list<float> co = robotobject.get_position_full();

    for ( float x : co){
        cout<< x << "  ";
    }
    // float x = robotobject.get_position(1);

    // while ( x < x_limit){
    //     robotobject.move_backwards(1);
    //     x = robotobject.get_position(1);
    // }
    // if (x >= x_limit){
    
    //     robotobject.stop_moving();

    // } else{
    //     robotobject.move_backwards(1);
    // }
    robotobject.stop_moving();

    return 0;
}

