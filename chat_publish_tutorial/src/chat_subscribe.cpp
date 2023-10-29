#include "ros/ros.h"
#include "customchat_msg/chatMsg.h"

ros::Publisher pub;
ros::Subscriber sub;
void chatCallback(const customchat_msg::chatMsg::ConstPtr &msg)
{
  ROS_INFO("Received message from %s: %s", msg->sender.c_str(), msg->message.c_str());

}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "chat_master_subscriber_node");
    ros::NodeHandle nh;

    sub = nh.subscribe("chat_host_topic", 10, chatCallback);

    ros::spin();

    return 0;
}
