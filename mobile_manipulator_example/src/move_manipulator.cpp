#include <ros/ros.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/move_group_interface/move_group_interface.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "move_manipulator");

    moveit::planning_interface::MoveGroupInterface arm("manipulator");
    ros::AsyncSpinner spinner(1);
    spinner.start();

    while(ros::ok())
    {
        arm.setNamedTarget("stand_by");
        arm.move();

        arm.setNamedTarget("stretching");
        arm.move();
    }

    return 0;
}