#include <ros/ros.h>
#include "tutorial_srvs/TutorialSrv.h"
#include "geometry_msgs/Twist.h"

ros::ServiceServer service_server;
ros::Publisher publisher_cmd_vel;

bool TurtleCircleCommandServiceCallback(tutorial_srvs::TutorialSrv::Request &req, tutorial_srvs::TutorialSrv::Response &res){
    if(req.command == "circle"){
        geometry_msgs::Twist cmd_vel;
        ROS_INFO("Receive Service call tutorial command : circle");
        cmd_vel.linear.x = 10.0;
        cmd_vel.angular.z = 6.24;
        publisher_cmd_vel.publish(cmd_vel);
        res.result = "true";
        res.message = "Receive success";
    }
    return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtle_service_server_node");
  ros::NodeHandle n;

  service_server = n.advertiseService("turtle_circle_command", TurtleCircleCommandServiceCallback);
  publisher_cmd_vel = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
  ros::Rate loop_rate(60);
  
  while (ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
