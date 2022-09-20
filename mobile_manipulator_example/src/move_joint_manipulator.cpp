#include <ros/ros.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "move_joint_manipulator");

    moveit::planning_interface::MoveGroupInterface arm("manipulator");
    ros::AsyncSpinner spinner(1);
    spinner.start();

    arm.setNamedTarget("stand_by");
    arm.move();

    vector<double> currentJointState;
  
    currentJointState=arm.getCurrentJointValues();

    cout<<"Before Change: ";
    for(int i=0; i<currentJointState.size(); i++)
    {
        cout<<currentJointState[i]<<", ";
    }
    cout<<endl<<endl;

    /*move 5th joint 90 deg*/
    currentJointState[4]+=3.141592/2;
    arm.setJointValueTarget(currentJointState);
    arm.move();

    currentJointState=arm.getCurrentJointValues();

    cout<<"After Change: ";
    for(int i=0; i<currentJointState.size(); i++)
    {
        cout<<currentJointState[i]<<", ";
    }
    cout<<endl<<endl;

    return 0;
}