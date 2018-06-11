//
// Created by ethernet on 06.06.18.
//

#include <ros/ros.h>
#include <can_msgs/Frame.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

#include <fstream>  // file saving
#include <message_filters/subscriber.h>
#include <message_filters/sync_policies/approximate_time.h>


/*
 *
 * The data types for the CAN message is :
 *
 *
 *
 */





void canAndImageCallback ( const can_msgs::FrameConstPtr& frame, const sensor_msgs::ImageConstPtr& msg) {

    //TODO: generate a file which outputs image frames along with angle as their name.














}







int main(int argc, char* argv[]){

    ros::init(argc, argv, "listener");

    ros::NodeHandle nh;

    //TODO: subscribe to topic received_messages for CAN as well as /convertedImage/video"



    message_filters::Subscriber<can_msgs::Frame>canSubscriber(nh, "/project/can_messages", 1);
    message_filters::Subscriber<sensor_msgs::Image> info_sub(nh, "/project/video_messages", 1);


    typedef message_filters::sync_policies::ApproximateTime<can_msgs::Frame, sensor_msgs::Image> MySyncPolicy;

    message_filters::Synchronizer<MySyncPolicy> sync(MySyncPolicy(20), canSubscriber, info_sub);

    sync.registerCallback(boost::bind(&canAndImageCallback, _1,_2));







    ros::spin();

    return 0;



}