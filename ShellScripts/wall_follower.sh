#!/bin/sh

xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(rospack find wall_follower)/../World/simple_environment.world" &
sleep 5
xterm -e " roslaunch turtlebot_gazebo gmapping_demo.launch" &
sleep 5
xterm -e " roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5
xterm -e " rosrun wall_follower wall_follower"
