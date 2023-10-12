#include <ros/ros.h>
#include "tutorial_msg/TutorialMsg.h"

void TutorialMsgCallback(const tutorial_msg::TutorialMsg::ConstPtr& tutorial_msg)
{
  ROS_INFO("tutorial_msg.String = %s", tutorial_msg->String.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_msg_subscribe_node");
  ros::NodeHandle n;

  ros::Subscriber subscriber_tutorial_msg;
  subscriber_tutorial_msg = n.subscribe("tutorial_msg", 1000, TutorialMsgCallback);
  ros::Rate loop_rate(60);

  while(ros::ok()){
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
