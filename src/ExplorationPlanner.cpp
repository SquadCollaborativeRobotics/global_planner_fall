/**
 * Exploration planner
 *
 * The exploration planner will create exploration tasks to try to fully explore the map area.
 * The planner places randomly chosen points in the map. Robots will choose to go to this point
 * if it is profitable to do so.  The exploration planner just sends out points and keeps track
 * of whether or not they are completed, not the negotiation process
 */

#include <ros/ros.h>

int main(int argc, char** argv){
  // ROS Node Initialization
  ros::init(argc, argv, "exploration_planner");
  ros::NodeHandle nh;

  // Update tasks every second
  ros::Rate rate(1);

  // Wait for the map server to come up

  ROS_INFO("Starting exploration planner");

  ExplorationTask explorationGoal;

  ///We will want to keep exploring an area, but we may not give as much
  ///value to the information gained after the first time through the map
  ///(where we don't know anything) compared to just wandering the map to
  ///keep an updated map
  int revenueValues[5] = {1.0, 0.3, 0.2, 0.1, 0.05};

  //Keeps track of how many times we've "explored" an area
  int numTimesThrough = 0;
  while(ros::ok()){
    while(ros::ok() && numTimesThrough < sizeof(revenueValues) && explorationGoal )
    {
      // Send out points vector?

      // Update callbacks after the fact, for next loop iteration.
      ros::spinOnce();
    }
    numTimesThrough++;
    rate.sleep();
  }
  ros::spin();
}
