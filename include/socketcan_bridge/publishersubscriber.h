//
// Created by ethernet on 24.05.18.
//

#ifndef PUBLISHERSUBSCRIBER_H
#define PUBLISHERSUBSCRIBER_H

//packages to be used cv_bridge, message_filters,



#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>


static const std::string subscribetopic = "/project/depth/image";
static const std::string publishtopic = "/project/video_messages";


//important methods and classes
namespace camera {

    class PublishSubscribeCamera {


    private:

        const ros::NodeHandle _nh;
        image_transport::ImageTransport _it;
        image_transport::Subscriber _imagesub;
        image_transport::Publisher  _imagepub;

    public:

        //default constructor uses only camera
        PublishSubscribeCamera();

        //destructor

        ~PublishSubscribeCamera();


        //callback method for messages from camera in the ROS

        void callback(const sensor_msgs::ImageConstPtr& msg);

    };

}









#endif //CATKIN_WS_PUBLISHERSUBSCRIBER_H
