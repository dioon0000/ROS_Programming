#include <ros/ros.h>
#include "tutorial_srvs/TutorialSrv.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtle_service_client_node");
  ros::NodeHandle n;

  ros::ServiceClient service_client;
  service_client = n.serviceClient<tutorial_srvs::TutorialSrv>("turtle_circle_command");

  tutorial_srvs::TutorialSrv turtle_circle_command;

  turtle_circle_command.request.command = "circle";

  service_client.call(turtle_circle_command);

  ROS_INFO("rosservice call /turtle_circle_command command : '%s'", turtle_circle_command.request.command.c_str());
  ROS_INFO("Service Call Response Result : '%s'", turtle_circle_command.response.result.c_str());
  ROS_INFO("Service Call Response Message : '%s'", turtle_circle_command.response.message.c_str());
  return 0;
}
