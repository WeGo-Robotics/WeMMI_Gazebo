#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "move_tracer");
    ros::NodeHandle nh;

    ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("cmd_vel", 100);
    ros::Rate loop_rate(10);
    geometry_msgs::Twist msg;

    while(ros::ok())
    {
        msg.linear.x=0.5;
        msg.angular.z=0.5;
        pub.publish(msg);
        loop_rate.sleep();    
    }

    return 0;
}