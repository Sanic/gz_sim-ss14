#include "gazebo/gazebo.hh"
#include "gazebo/physics/physics.hh"
#include "link_objects.hh"

namespace gazebo
{
    LinkObjects::LinkObjects() : WorldPlugin()
    {
      std::cout << "Hello World!" << std::endl;
    }

    //////////////////////////////////////////////////
    void LinkObjects::Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
    {
      // Don't do anything here, because the world will be loaded
      // in Init()!
    }

    //////////////////////////////////////////////////
    void LinkObjects::OnUpdate(const common::UpdateInfo & /*_info*/)
    {
       // Get the box and sphere model
       physics::ModelPtr sphere_model = _world->GetModel("sphere1");
       physics::ModelPtr box_model = _world->GetModel("box1");
       
       // Apply a small linear velocity to the models
       sphere_model->SetLinearVel(math::Vector3(.03, 0, 0));
       box_model->SetLinearVel(math::Vector3(.03, 0, 0));
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
