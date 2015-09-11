#ifndef TEST_NODE_H
#define TEST_NODE_H

#include <ros/publisher.h>

class TestNode
{
public:
  TestNode();

  void publish();

private:
  ros::Publisher pub_;
};

#endif
