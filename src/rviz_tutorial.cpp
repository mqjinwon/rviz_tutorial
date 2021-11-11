#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>


int main(int argc, char **argv)
{
    ros::init(argc, argv, "rviz_tutorial");
    ros::NodeHandle n;
    ros::Rate loop_rate(10);

    ros::Publisher vis_pub = n.advertise<visualization_msgs::Marker>( "visualization_marker", 0 );
    ros::Publisher vis_pub_array = n.advertise<visualization_msgs::MarkerArray>( "visualization_marker_array", 0 );

    visualization_msgs::MarkerArray marker_array;

    visualization_msgs::Marker marker;

    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time();
    marker.ns = "my_namespace";
    
    marker.type = visualization_msgs::Marker::SPHERE;
    marker.action = visualization_msgs::Marker::ADD;

    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
    marker.scale.x = 0.05;
    marker.scale.y = 0.05;
    marker.scale.z = 0.05;
    marker.color.a = 1.0; // Don't forget to set the alpha!
    marker.color.r = 0.0;
    marker.color.g = 1.0;
    marker.color.b = 0.0;


    for (int i=0; i<10; i++)
    {
        marker.id = i;
        marker.pose.position.x = i*0.1;
        marker.pose.position.y = 0;
        marker.pose.position.z = 0;

        marker_array.markers.push_back(marker);
    }


    

    while (ros::ok())
    {
        vis_pub_array.publish(marker_array);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}