#include "test_node.h"
#include <ros/ros.h>
#include <std_msgs/String.h>

TestNode::TestNode()
{
  ros::NodeHandle nh;
  pub_ = nh.advertise<std_msgs::String>("chatter", 10);
}

void TestNode::publish()
{
  static std_msgs::String msg;
  msg.data = "Hello Buildfarm";
  pub_.publish(msg);
}
