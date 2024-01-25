#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <std_srvs/Empty.h>

geometry_msgs::Twist cmd_vel;
std_srvs::Empty empty;

bool callSpeedFast = false;
bool callSpeedNorm = false;
bool update = false;

void handle_speed_service(const sensor_msgs::Joy::ConstPtr& msg) {
  if (msg->buttons[4] > 0) {
    callSpeedFast = true;
  } else if (msg->buttons[5] > 0) {
    callSpeedNorm = true;
  }
}

void handle_cml_vel(float x, float z) {
  if (x != cmd_vel.linear.x) {
    cmd_vel.linear.x = x;
    update = true;
  }
  if (z != cmd_vel.angular.z) {
    cmd_vel.angular.z = z;
    update = true;
  }
}

void joyStateCallback(const sensor_msgs::Joy::ConstPtr& msg) {
  // ROS_INFO("joyStateCallback called");
  static float x, z;
  if (msg->buttons[0] > 0) {
    x = 1;
    z = 0;  // forward
  } else if (msg->buttons[1] > 0) {
    x = 1;
    z = -1;  // right
  } else if (msg->buttons[2] > 0) {
    x = -1;
    z = 0;  // backward
  } else if (msg->buttons[3] > 0) {
    x = 1;
    z = 1;  // left
  } else {
    x = z = 0;  // stop
  }
  handle_cml_vel(x, z);
  handle_speed_service(msg);
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "wheebot_joy");
  ros::NodeHandle nh;

  ros::Publisher cmd_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
  ros::Subscriber joy_sub = nh.subscribe("/joy", 1000, joyStateCallback);
  ros::ServiceClient client1 =
      nh.serviceClient<std_srvs::Empty>("/speed_normal");
  ros::ServiceClient client2 = nh.serviceClient<std_srvs::Empty>("/speed_fast");

  ros::Rate loop_rate(50);
  while (ros::ok()) {
    if (callSpeedFast) {
      client1.call(empty);
      callSpeedFast = false;
      update = true;
    }
    if (callSpeedNorm) {
      client2.call(empty);
      callSpeedNorm = false;
      update = true;
    }
    //
    if (update) {
      cmd_pub.publish(cmd_vel);
      update = false;
    }
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}