cmake_minimum_required(VERSION 2.8.3)
project(ros_buildfarm_test)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  tf2
)
catkin_package(
#  INCLUDE_DIRS include
  LIBRARIES ros_buildfarm_test
  CATKIN_DEPENDS roscpp std_msgs tf2
#  DEPENDS system_lib
)

add_library(ros_buildfarm_test
  src/test_node.cpp
)
target_link_libraries(ros_buildfarm_test ${catkin_LIBRARIES})

add_executable(ros_buildfarm_test_node src/main.cpp)
target_link_libraries(ros_buildfarm_test_node ros_buildfarm_test)

## Mark executables and/or libraries for installation
install(TARGETS ros_buildfarm_test ros_buildfarm_test_node
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Mark other files for installation (e.g. launch and bag files, etc.)
install(FILES
  launch/buildfarm_test.launch
  # myfile2
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_ros_buildfarm_test.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
