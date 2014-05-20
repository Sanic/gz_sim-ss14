cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

include (FindPkgConfig)

# Load catkin and all dependencies required for this package (from http://gazebosim.org/wiki/Tutorials/1.9/Creating_ROS_plugins_for_Gazebo)
find_package(catkin REQUIRED COMPONENTS 
	roscpp 
	gazebo 
	)

if (PKG_CONFIG_FOUND)
	pkg_check_modules(GAZEBO gazebo)
	pkg_check_modules(OGRE OGRE)
endif()   
include_directories(${GAZEBO_INCLUDE_DIRS} ${OGRE_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS} ${OGRE_LIBRARY_DIRS})

add_library(move_objects SHARED src/move_objects.cpp)
target_link_libraries(move_objects ${GAZEBO_libraries} ${OGRE_LIBRARIES})
