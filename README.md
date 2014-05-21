gz_sim-ss14
===========

Homework repository for the gazebo simulation seminar


Notes
=======
This software has been tested with Gazebo 1.9.5, that has been shipped by ROS Hydro (i've installed ros-hydro-desktop-full).

Instructions Homework1
====
- Go to that folder
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

