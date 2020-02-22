#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>  // c++ stream make fun

int main(int argc,char **argv)
{
    ros::init(argc,argv,"talker");  // int ros,named nodenme
    ros::NodeHandle n;  // init node ,return n handle
    // define a sender.
    ros::Publisher chatter_pub =n.advertise<std_msgs::String>("chatter",1);
    ros::Rate loop_rate(10);    // set send freq;
    int count =0;       // send message number.
    while(ros::ok())   {    // check node is work
        std_msgs::String msg;

        std::stringstream ss;   // define stream var
        ss<<"Hello world"<<count;
        msg.data=ss.str();  // fill send msg
        ROS_INFO("%s",msg.data.c_str()); //print msg
        chatter_pub.publish(msg);   // send msg
        ros::spinOnce();    // excute callback fun, will reback,this is no must ,because this node no callback fun.
        loop_rate.sleep();  // it pair of lin 11. it control by send freq.
        ++count;            // msg count.
    }
    return 0;
}