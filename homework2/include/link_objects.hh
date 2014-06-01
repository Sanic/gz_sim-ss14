#ifndef _LINK_OBJECTS_HH_
#define _LINK_OBJECTS_HH_

#include "gazebo/gazebo.hh"
#include "gazebo/physics/physics.hh"

namespace gazebo
{
  class MoveObjects : public SystemPlugin
  {
    // Attributes
    private: physics::WorldPtr _world;
    private: event::ConnectionPtr updateConnection;

    public: virtual void Load(int _argc, char** _argv);

    /// \brief Callback method for every update in the current world
    public: void OnUpdate(const common::UpdateInfo & /*_info*/);

    /// \brief Callback for the initialization of the plugin
    /// This plugin will do the following things in this method:
    /// 1) Get access to the current world
    /// 2) Print the current physics engine and the name of
    ///    the loaded world.
    //  3) Subscribe to event::Events::ConnectWorldUpdateBegin
    private: virtual void Init();
  };
  // Register this plugin with the simulator
  GZ_REGISTER_SYSTEM_PLUGIN(MoveObjects)
}
#endif
