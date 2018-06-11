//
// Created by ethernet on 24.05.18.
//


#include <socketcan_bridge/publishersubscriber.h>




camera::PublishSubscribeCamera::PublishSubscribeCamera(): _it(_nh){   //const references are to be initialized in initialization list ? check it out

    //subscribe raw images
    // images are directed to the call back method whenever an image appears
    //call back method performs necessary operations like undistorting etc.,.



    _imagesub = _it.subscribe(subscribetopic, 1 ,&PublishSubscribeCamera::callback, this);


    _imagepub = _it.advertise(publishtopic, 1);

    //cv::namedWindow (OPENCV_WINDOW);


}


camera::PublishSubscribeCamera::~PublishSubscribeCamera() {

    //kill any open opencv windows
    //release unwanted memory


}


void camera::PublishSubscribeCamera::callback(const sensor_msgs::ImageConstPtr& msg){



    cv_bridge::CvImagePtr cv_ptr; // converts sensor to cvbridge

    try
    {

        cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
        // cv_ptr->Mat gives the image to be used for OpenCV processing



    }
    catch (cv_bridge::Exception& e)

    {

        ROS_ERROR("cv_bridge exception: %s", e.what());

        return;
    }


    // do all sorts of image processing here

}




