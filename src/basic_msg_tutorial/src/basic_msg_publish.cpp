#include <ros/ros.h>
#include <iostream>
#include "tutorial_msg/TutorialMsg.h"

using namespace std;
int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_msg_publish_node");
  ros::NodeHandle n;


  tutorial_msg::TutorialMsg tutorial_msg;
  ros::Publisher publisher_tutorial_msg = n.advertise<tutorial_msg::TutorialMsg>("tutorial_msg", 1000);
  ros::Rate loop_rate(60);

  while(ros::ok()){
    string str;
    cout << "send message : ";
    cin >> str;
    //tutorial_msg.Bool = true;
    //tutorial_msg.Int8 = 127;
    //tutorial_msg.UInt8 = 255;
    //tutorial_msg.Int16 = 32767;
    tutorial_msg.String = str;
    publisher_tutorial_msg.publish(tutorial_msg);

    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}

