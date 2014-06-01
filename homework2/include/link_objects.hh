#ifndef _LINK_OBJECTS_HH_
#define _LINK_OBJECTS_HH_

#include "gazebo/gazebo.hh"
#include "gazebo/physics/physics.hh"

namespace gazebo
{
  class LinkObjects : public WorldPlugin
  {
    // Attributes
    private: physics::WorldPtr _world;
    private: event::ConnectionPtr updateConnection;
    private: physics::JointPtr _joint;
    private: bool _sleep_init_done;
    private: bool _joint_created;
    private: bool _joint_destroyed;

    public: LinkObjects();
    public: void Load(physics::WorldPtr _loaded_world, sdf::ElementPtr _sdf);

    /// \brief Callback method for every update in the current world
    /// This method will
    //  1) Wait 8 seconds. This timespan should be enough, to let all objects in worlds/homework2.sdf fall
    //     to the ground properly.
    //  2) Apply a velocity to the Sphere model in the world
    //  3) In addition, create a joint between the sphere and the box
    //  4) After 16 seconds from the start of the simulation, the joint will be created.
    //     The velocity of the sphere will still be set in every physics engine update.
    //
    // Note: This method uses the Sim time, not Walltime!
    //
    public: void OnUpdate(const common::UpdateInfo & /*_info*/);
  };
  // Register this plugin with the simulator
  GZ_REGISTER_WORLD_PLUGIN(LinkObjects)
}
#endif
