#include <ros/ros.h>
using namespace ros;
int main(int argc, char **argv){
    init(argc, argv, "times_node");
    NodeHandle n;

    for(int i=2; i<=9; ++i){
        for(int j=1; j<=9; ++j){
            ROS_INFO("%d*%d = %d",i,j,i*j);
        }
    }

    return 0;
}