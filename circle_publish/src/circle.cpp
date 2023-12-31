#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "circle_publisher_node");
  ros::NodeHandle n;

  geometry_msgs::Twist cmd_vel;
  ros::Publisher publisher_cmd_vel = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);

  ros::Rate loop_rate(60);

  while (ros::ok())
  {

    cmd_vel.linear.x = 2.0;
    cmd_vel.angular.z = 1.0;

    publisher_cmd_vel.publish(cmd_vel);

    ros::spinOnce();
    loop_rate.sleep();
  }

  ROS_INFO("basic_publish_node Close");
  return 0;
}
