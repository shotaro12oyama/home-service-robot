#!/bin/sh

xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(rospack find wall_follower)/../World/simple_environment.world" &
sleep 5
xterm -e " roslaunch turtlebot_gazebo amcl_demo.launch map_file:=$(rospack find wall_follower)/../World/map/map.yaml" &
sleep 5
xterm -e " roslaunch $(rospack find add_markers)/../rviz/add_marker.launch" &
sleep 5
xterm -e " rosrun add_markers add_markers_node" &
sleep 5
xterm -e " rosrun pick_objects pick_objects_node"
