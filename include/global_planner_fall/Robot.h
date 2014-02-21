/**
 * Robot.h - The robot class is an interface to a single robot
 * that is controllable through the software
 *
 * Robots have unique names, IDs
 * The robot class keeps track of position through the tf tree/odom
 * Robot's motion can be controlled through this interface class
 */

#include <ros/ros.h>
#include <boost/shared_ptr>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

class Robot
{
public:
    Robot();
    ~Robot();

    bool setName(std::string name);
    std::string getName(){ return m_name; };
    boost::uuids::uuid getID(){ return m_uuid; };

private:
    boost::uuids::uuid m_uuid;
    std::string m_name;
};

typedef boost::shared_ptr< Robot > robot_ptr;