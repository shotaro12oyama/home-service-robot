#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

class AddSimpleMarker {
private:
    ros::NodeHandle n;
    ros::Publisher marker_pub;
    visualization_msgs::Marker marker;
    double pickupZone[2] = {3.5, 5.0};
    double dropoffZone[2] = {-0.5, 0.5};

public:
    AddSimpleMarker() {
        marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

        // initialize marker and show marker at pickup zone
        // Set the frame ID and timestamp.  See the TF tutorials for information on these.
        marker.header.frame_id = "map";
        marker.header.stamp = ros::Time::now();

        // Set the namespace and id for this marker.  This serves to create a unique ID
        // Any marker sent with the same namespace and id will overwrite the old one
        marker.ns = "add_markers";
        marker.id = 0;

        // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
        marker.type = visualization_msgs::Marker::SPHERE;

        // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
        marker.action = visualization_msgs::Marker::ADD;

        // Set the scale of the marker -- 1x1x1 here means 1m on a side
        marker.scale.x = 0.25;
        marker.scale.y = 0.25;
        marker.scale.z = 0.25;

        // Set the color -- be sure to set alpha to something non-zero!
        marker.color.r = 1.0f;
        marker.color.g = 0.0f;
        marker.color.b = 0.0f;
        marker.color.a = 1.0;

        // Set marker's initial coordinates
        setMarkerPosition(pickupZone[0], pickupZone[1]);

        marker.lifetime = ros::Duration();

				publishMarker();
        ROS_INFO("At pickup location...");

        // pause 5s to simulate pickup
        ros::Duration(5).sleep();
        // set marker to new coordinates
        setMarkerPosition(dropoffZone[0], dropoffZone[1]);
        ROS_INFO("At dropoff location...");

				// publish marker
        publishMarker();

    }

    void setMarkerPosition(double pos_x, double pos_y) {
        // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
        marker.pose.position.x = pos_x;
        marker.pose.position.y = pos_y;
    }

    void publishMarker() {
        // Publish the marker
        while (marker_pub.getNumSubscribers() < 1) {
            ROS_WARN_ONCE("Please create a subscriber to the marker");
            sleep(1);
        }

        marker_pub.publish(marker);
    }

};

int main(int argc, char **argv) {
    ros::init(argc, argv, "add_markers");

    AddSimpleMarker addSimpleMarker;
    ros::spin();

    return 0;
}
