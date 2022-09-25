#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "ball_chaser/DriveToTarget.h"

// ROS::Publisher motor commands;
ros::Publisher motor_command_publisher;

// The callback


bool handle_drive_bot_request(ball_chaser::DriveToTarget::Request& req,ball_chaser::DriveToTarget::Response& res)
{
         // Create a motor_command object of type geometry_msgs::Twist
        geometry_msgs::Twist motor_command;
        //Ask for wheel velocities
        motor_command.linear.x = req.linear_x;
        motor_command.angular.z = req.angular_z;
        // Publish angles to drive the robot
        motor_command_publisher.publish(motor_command);


       // Return a response message
    res.msg_feedback = "wheels velocity set to" 

    ROS_INFO_STREAM(res.msg_feedback);
   
        return true;
}

int main(int argc, char** argv)
{


    // Initialize a ROS node
    ros::init(argc, argv, "drive_bot");

    // Create a ROS NodeHandle object
    ros::NodeHandle n;

    // Inform ROS master that we will be publishing a message of type geometry_msgs::Twist on the robot actuation topic with a publishing queue size of 10
   motor_command_publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

// Define two publishers to publish std_msgs::Float64 messages on joints respective topics

// TODO: Define a drive /ball_chaser/command_robot service with a handle_drive_request callback function

    // TODO: Delete the loop, move the code to the inside of the callback function and make the necessary changes to publish the requested velocities instead of constant values

       // Define a service with a velocity_request callback function

    ros::ServiceServer service = n.advertiseService("/ball_chaser/velocity_command", handle_drive_bot_request);

    ROS_INFO("Enter velocity commands");

    // TODO: Handle ROS communication events
    ros::spin();

    return 0;
}
