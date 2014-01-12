#include "Robot.h"

Robot::setName(std::string name)
{
    boost::uuids::string_generator gen;

    m_uuid = gen(name);
    m_name = name;
}
