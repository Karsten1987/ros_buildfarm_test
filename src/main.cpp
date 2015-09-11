#include <ros/ros.h>
#include "test_node.h"

int main( int argc, char** argv )
{
  ros::init(argc, argv, "ros_buildfarm_test");

  TestNode tn;

  ros::Rate r(1);

  const size_t n = 100000;
  size_t idx = 0;
  while(ros::ok())
  {
    if (idx > n)
      break;
    idx++;
    tn.publish();
    std::cout << "publishing hello buildfarm" << std::endl;
    ros::spinOnce();
    r.sleep();
  }

  return 0;
}


