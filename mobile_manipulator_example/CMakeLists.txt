cmake_minimum_required(VERSION 3.0.2)
project(mobile_manipulator_example)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  moveit_core
  moveit_ros_planning
  moveit_ros_planning_interface
)
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES mobile_manipulator_example
#  CATKIN_DEPENDS geometry_msgs roscpp rospy
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(move_tracer src/move_tracer.cpp)
target_link_libraries(move_tracer ${catkin_LIBRARIES})

add_executable(move_manipulator ./src/move_manipulator.cpp)
target_link_libraries(move_manipulator ${catkin_LIBRARIES})

 