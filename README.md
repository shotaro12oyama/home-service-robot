# home-service-robot

## Task
The summary what should be done in this project to simulate a home service robot
* Design a simple environment with the Building Editor in Gazebo.
* Teleoperate your robot and manually test SLAM.
* Create a wall_follower node that autonomously drives your robot to map your environment.
* Use the ROS navigation stack and manually commands your robot using the 2D Nav Goal arrow in rviz to move to 2 different desired positions and orientations.
* Write a pick_objects node that commands your robot to move to the desired pickup and drop off zones.
* Write an add_markers node that subscribes to your robot odometry, keeps track of your robot pose, and publishes markers to rviz.


## Building from Source

Run the following commands from terminal to build the project from source:

``` bash
$ cd /home/workspace/catkin_ws
$ git clone http://github.com/shotaro12oyama/home-service-robot.git src
$ cd ../
$ catkin_make
$ source devel/setup.sh
$ cd ./src/Shellscript/home_service.sh
```

