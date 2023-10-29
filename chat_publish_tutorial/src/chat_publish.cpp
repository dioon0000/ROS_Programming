#include "ros/ros.h"
#include "customchat_msg/chatMsg.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "chat_master_publisher_node");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<customchat_msg::chatMsg>("chat_master_topic", 10);
    ros::Rate rate(1);  // 1 Hz

    while (ros::ok())
    {
        customchat_msg::chatMsg chat_msg;
        chat_msg.sender = "Master";
        std::cout << "Enter your message: ";
        std::cin >> chat_msg.message;
        pub.publish(chat_msg);
        rate.sleep();
    }

    return 0;
}
