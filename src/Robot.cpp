#include "Robot.h"

Robot::setName(std::string name)
{
    boost::uuids::string_generator gen;

    m_uuid = gen(name);
    m_name = name;
}

Robot::setType(RobotType type)
{
    m_type = type;
}