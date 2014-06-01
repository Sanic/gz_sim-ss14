#include "gazebo/gazebo.hh"
#include "gazebo/common/Time.hh"
#include "gazebo/physics/physics.hh"
#include "link_objects.hh"

namespace gazebo
{
    LinkObjects::LinkObjects() : WorldPlugin()
    {
      std::cout << "Hello World!" << std::endl;
      this->_sleep_init_done = false;
    }

    //////////////////////////////////////////////////
    void LinkObjects::Load(physics::WorldPtr _loaded_world, sdf::ElementPtr _sdf)
    {
      _world = _loaded_world;
      // Subscribe to the World Update event
      this->updateConnection = event::Events::ConnectWorldUpdateBegin(
          boost::bind(&LinkObjects::OnUpdate, this, _1));
    }

    //////////////////////////////////////////////////
    void LinkObjects::OnUpdate(const common::UpdateInfo & /*_info*/)
    {
      common::Time current_time = _world->GetSimTime();
      if(!_sleep_init_done)
      {
        common::Time passed_seconds_for_start(8,0);
        // common::Time::Sleep(time); //Time::Sleep blocks the physics engine ...
        if(current_time > passed_seconds_for_start)
        {
         std::cout << "Timeout reached" << std::endl;
        _sleep_init_done = true;
        }
      }
      // std::cout << current_time << std::endl;
      // Get the box and sphere model
      physics::ModelPtr sphere_model = _world->GetModel("sphere1");
      physics::ModelPtr box_model = _world->GetModel("box1");

      // Apply a small linear velocity to the models
      if(_sleep_init_done)
      {
        sphere_model->SetLinearVel(math::Vector3(.09, 0, 0));
        // box_model->SetLinearVel(math::Vector3(.03, 0, 0));
      }
    }

    //////////////////////////////////////////////////
    // void MoveObjects::Init()
    // {
    //   // Get the first world in the simulation
    //   _world = physics::get_world (); 
    //  std::cout << "The name of the current world: ";
    //  std::cout << _world->GetName() << std::endl;
    //  physics::PhysicsEnginePtr physics_engine = _world->GetPhysicsEngine ();

    //  std::cout << "The physics engine type: ";
    //  std::cout << physics_engine->GetType() << std::endl;

    //  // Subscribe to the World Update event
    //  this->updateConnection = event::Events::ConnectWorldUpdateBegin(
    //      boost::bind(&MoveObjects::OnUpdate, this, _1));
    // }
}
