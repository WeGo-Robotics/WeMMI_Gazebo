#include <ros/ros.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "move_ee_manipulator");

    moveit::planning_interface::MoveGroupInterface arm("manipulator");
    ros::AsyncSpinner spinner(1);
    spinner.start();

    arm.setNamedTarget("stand_by");
    arm.move();
    
    /*get current pose*/
    geometry_msgs::PoseStamped currentPose;
    currentPose=arm.getCurrentPose();
    cout<<currentPose<<endl;

    /*move z -10cm*/
    geometry_msgs::Pose movePose;
    movePose.position.x=currentPose.pose.position.x;
    movePose.position.y=currentPose.pose.position.y;
    movePose.position.z=currentPose.pose.position.z-0.1;
    movePose.orientation=currentPose.pose.orientation;
    arm.setPoseTarget(movePose);
    arm.move();

    currentPose=arm.getCurrentPose();
    cout<<currentPose<<endl;

    return 0;
}