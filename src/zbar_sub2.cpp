#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <std_msgs/String.h>	//包含了使用的数据类型
void StrCallback(const std_msgs::String::ConstPtr& msg)
{
  	ROS_INFO("node_b is receiving [%s]", msg->data.c_str());
}
//这里也可以不用指针接收，则对发布的消息进行拷贝，如
 
int main(int argc, char **argv)
{
  ros::init(argc, argv, "image_sub2");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("zbarQR_sub", 10, StrCallback);
  ros::spin();
  return 0;
}
