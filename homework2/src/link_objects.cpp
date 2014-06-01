#include "gazebo/gazebo.hh"
#include "gazebo/common/Time.hh"
#include "gazebo/physics/physics.hh"
#include "link_objects.hh"

namespace gazebo
{
    LinkObjects::LinkObjects() : WorldPlugin()
    {
      std::cout << "LinkObjects plugin loaded" << std::endl;
      this->_sleep_init_done = false;
      this->_joint_created = false;
      this->_joint_destroyed = false;
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

      // Wait until the objects fell down to the ground
      if(!_sleep_init_done)
      {
        common::Time passed_seconds_for_start(8,0);
        // common::Time::Sleep(time); //Time::Sleep blocks the physics engine ...

        if(current_time > passed_seconds_for_start)
        {
         std::cout << "Init phase over - Objects should lay on the ground" << std::endl;
        _sleep_init_done = true;
        }
      }
      else
      // Apply a small linear velocity to the sphere model after it hit the ground
      {
        // Get the box and sphere model
        physics::ModelPtr sphere_model = _world->GetModel("sphere1");
        physics::ModelPtr box_model = _world->GetModel("box1");

        // Create the joint after the init phase is over
        if(!_joint_created)
        {
          this->_joint = _world->GetPhysicsEngine()->CreateJoint("revolute", sphere_model);
          physics::LinkPtr sphere_link = sphere_model->GetLink();
          physics::LinkPtr box_link = box_model->GetLink();
          this->_joint->Attach(sphere_link, box_link);
          this->_joint->Load( sphere_link, box_link, math::Pose(sphere_link->GetWorldPose().pos, math::Quaternion()) );
          _joint_created = true;
          std::cout << "Joint created - Pull the Sphere" << std::endl;
        }
        else
        {
          // If the link has not been destroyed yet, wait for the
          // defined amount of time and detach it's link
          if(!_joint_destroyed)
          {
            common::Time passed_seconds_until_joint_destroy(16,0);
            if(current_time > passed_seconds_until_joint_destroy)
            {
              std::cout << "Joint destroyed" << std::endl;
              this->_joint->Detach();
              _joint_destroyed = true;
            }
          }

        }
        sphere_model->SetLinearVel(math::Vector3(.09, 0, 0));
      }
    }
}
