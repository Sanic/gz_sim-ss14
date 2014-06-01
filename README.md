gz_sim-ss14
===========

Homework repository for the gazebo simulation seminar


Notes
=======
This software has been tested with Gazebo 1.9.5, that has been shipped by ROS Hydro (i've installed ros-hydro-desktop-full).

Instructions Homework1
====
- Go to the homework1/ folder
- mkdir build/
- cd build
- cmake ..
- make
- cd ..

This will build a server side plugin, that can control the world in the running simulation. You can load it by using:

```
gzserver -s $ABSOLUTE_PATH_TO_REPO/homework1/build/libmove_objects.so worlds/homework1.sdf
```
and 
```
gzclient
```
in another terminal

You should then see a sphere and a box, that are both moving at the same velocity.

Instructions Homework2
====
- Go to the homework2/ folder
- mkdir build/
- cd build
- cmake ..
- make
- cd ..
- Register your build/ folder to your gazebo plugin path:
```
export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/FULL/PATH/TO/homework2/build
```

The plugin in this exercise is a WorldPlugin. It must be findable by GAZEBO via the GAZEBO_PLUGIN_PATH variable. If you want to start the plugin for homework2, just start your gazebo with:
```
gazebo /PATH/TO/homework2/worlds/homework2.sdf
```
You should see how:
1) Two objects fall on the ground
2) The sphere begins to move and drags the Box with him via a Joint
3) The Joint will be detached from both objects. The sphere will move alone then
