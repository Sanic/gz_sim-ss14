#include "gazebo/gazebo.hh"

namespace gazebo
{
  class MoveObjects : public SystemPlugin
  {
    // Attributes
    private: WorldPtr _world;

    public: virtual ~MoveObjects()
            {
            }

    public: virtual void Load(int _argc, char _argv)
            {
              // Get access to the world
               // _world = gazebo::physics::get_world ("homework1" )
              // PhysicsEnginePtr physics_engine = gazebo::physics::World::GetPhysicsEngine ();
              // std::cout << "The physics engine type:";
              // std::cout << physics_engine->GetType() << std::endl;
              // std::cout << "The name of the current world:";
              // std::cout << _world->GetName() << std::endl;

            }

            // Called by the world update start event
    public: void OnUpdate(const common::UpdateInfo & /*_info*/)
            {
              // Get the box and sphere model
              ModelPtr sphere_model = _world->getModel("sphere1");
              ModelPtr box_model = _world->getModel("box1");
              
              // Apply a small linear velocity to the models
              // sphere_model->SetLinearVel(math::Vector3(.03, 0, 0));
              // box_model->SetLinearVel(math::Vector3(.03, 0, 0));
            }

    private: virtual void Init()
             {
             }
  };
  // Register this plugin with the simulator
  GZ_REGISTER_SYSTEM_PLUGIN(MoveObjects)
}
