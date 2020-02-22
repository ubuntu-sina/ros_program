#include "ros/ros.h"
#include "std_msgs/String.h"


void chatterCallback(const std_msgs::String::ConstPtr&msg)
{
    ROS_INFO("I heard :[%s]",msg->data.c_str());   
}


int main(int argc,char **argv)
{
    ros::init(argc,argv,"listener");
    ros::NodeHandle n;
    // define ros::Subscriber var, then by handle n,to call subscribe fun:n.subscrib(). 
    //par1: tilename,it same to the send tiller ,par2:array number, par3:callback fun.
    ros::Subscriber sub=n.subscribe("chatter",1000,chatterCallback);
    ros::spin();    // listener : not return ,listen and execut callback fun.
                    // if no the fun, the callback can't execut.
    return 0;       // can't goto here
}

