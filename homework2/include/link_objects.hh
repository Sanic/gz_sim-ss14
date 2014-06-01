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
    private: bool _sleep_init_done;

    public: LinkObjects();
    public: void Load(physics::WorldPtr _loaded_world, sdf::ElementPtr _sdf);

    /// \brief Callback method for every update in the current world
    public: void OnUpdate(const common::UpdateInfo & /*_info*/);
  };
  // Register this plugin with the simulator
  GZ_REGISTER_WORLD_PLUGIN(LinkObjects)
}
#endif
