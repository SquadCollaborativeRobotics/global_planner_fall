/**
 * ExplorationTask definition file
 *
 * An exploration task extends Task and is used to explore an area
 * This task type is defined by points on the map of which the robots will move
 * and
 */

#include <ExplorationTask.h>

//Default Constructor
ExplorationTask::ExplorationTask()
{
  creationTime = ros::Time::now();
}
