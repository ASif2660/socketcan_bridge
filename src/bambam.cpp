/*
 * Program developed for : MAster thesis
 * by: Mohammed Asif Chand
 * For: Master thesis, Computational Science and Engineering.
 * date started:  22.06.2018
 *
 */


 //defining important headers

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "socketcan_bridge/publishersubscriber.h"



int main (int argc, char* argv[]){


    ros::init(argc, argv, "cameraStreamingNode");

    camera::PublishSubscribeCamera instance;

    ros::spin();

    return 0;


}