#!/bin/sh

#xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/workspace/catkin_ws/src/World/simple_environment.world" &
xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch" &
sleep 5
#xterm -e " roslaunch turtlebot_gazebo amcl_demo.launch map_file:=/home/workspace/catkin_ws/src/World/map/map.yaml" &
xterm -e " roslaunch turtlebot_gazebo amcl_demo.launch" &
sleep 5
xterm -e " roslaunch turtlebot_rviz_launchers view_navigation.launch" 
